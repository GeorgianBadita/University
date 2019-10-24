import functools
import json
from datetime import date

from flask import session, redirect, url_for, request, g, render_template, flash

from app import app, db
from app.models import User, Event


@app.before_request
def load_logged_in_user():
    username = session.get('user')

    if username is None:
        g.user = None
    else:
        g.user = User.query.filter_by(username=username).first()


def login_required(view):
    @functools.wraps(view)
    def wrapped_view(**kwargs):
        if g.user is None:
            return redirect(url_for('login'))

        return view(**kwargs)

    return wrapped_view


@app.route('/', methods=['GET', 'POST'])
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        err = ""
        admin = User.query.filter_by(username=username).first()
        if admin is None:
            err = 'No user with username ' + username
        elif admin.password != password:
            err = 'Wrong password'

        if err == "":
            session.clear()
            session['user'] = username
            return redirect(url_for('index'))
        else:
            flash(err)

    return render_template('login.html')


@app.route('/index', methods=['GET', 'POST'])
@login_required
def index():
    if request.method == 'POST':
        date = request.form['date']
        time = request.form['time']
        if date and time:
            description = request.form['description']
            event = Event(date=date, time=time, description=description)
            db.session.add(event)
            db.session.commit()
            flash("Event added successfully")
        else:
            flash("Parameters not given")
    return render_template('add_event.html')


@app.route('/logout', methods=['GET', 'POST'])
def logout():
    session.clear()
    return redirect(url_for('login'))


@app.route('/injection', methods=['GET', 'POST'])
@login_required
def injection():
    print(request.form)
    if request.method == 'POST':
        id = request.form['id']
        result = db.session.execute('select id from User where id=' + str(id))
        flash([row[0] for row in result])
        user = User.query.filter_by(id=id).all()
        flash([row.id for row in user])
        return render_template('injection.html')
    return render_template('injection.html')


def make_date(closest_date):
    year = int(closest_date.split('/')[2])
    month = closest_date.split('/')[0]
    if month[0] == '0':
        month = int(month[1:])
    else:
        month = int(month)
    day = closest_date.split('/')[1]
    if day[0] == '0':
        day = int(day[1:])
    else:
        day = int(day)
    print()
    return date(year, month, day)


@app.route('/tabs', methods=['GET', 'POST'])
def get_tabs():
    dates = []
    events = Event.query.all()
    for event in events:
        if event.date not in dates:
            dates.append(event.date)

    today = date.today()
    best_date = make_date(dates[0])
    best_dist = abs((today - best_date).days)
    for i in range(1, len(dates)):
        dist = abs((today - make_date(dates[i])).days)
        if dist < best_dist and today < make_date(dates[i]):
            best_dist = dist
            best_date = dates[i]

    return render_template('tabs.html', tabs=dates, closest_date=best_date)


@app.route('/get_events', methods=['GET', 'POST'])
def get_events():
    date = request.args.get('event')
    events = Event.query.filter_by(date=date)
    event_dict = {
        'events': []
    }

    for event in events:
        event_dict['events'].append(
            {
                'id': event.id,
                'description': event.description,
                'hour': event.time.split(':')[0],
                'minute': event.time.split(':')[1]
            }
        )
    return json.dumps(event_dict)
