import functools
import hashlib
import json
import os

from flask import request, session, g, redirect, url_for, render_template, flash

from app import app, ALLOWED_EXTENSIONS_IMAGE, db
from app.models import User, Image


def allowed_file_image(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS_IMAGE


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

        print(username)
        print(password)
        user_log = User.query.filter_by(username=username).first()

        if username == user_log.username and password == user_log.password:
            session.clear()
            session['user'] = username
            if user_log.is_admin:
                return redirect(url_for('admin'))
            else:
                return redirect(redirect(url_for('user')))
    return render_template('login.html')


@app.route('/admin', methods=['GET', 'POST'])
@login_required
def admin():
    return render_template('admin.html')


@app.route('/user', methods=['GET', 'POST'])
@login_required
def user():
    return render_template('user.html')


@app.route('/logout', methods=['GET', 'POST'])
@login_required
def logout():
    session.clear()
    return redirect(url_for('login'))


@app.route('/upload', methods=['GET', 'POST'])
@login_required
def upload():
    if request.method == 'POST':
        err = ""
        print(request.form)
        if 'description' not in request.form:
            err += "Description not given"
        if 'photo' not in request.files:
            err += "Photo not given"

        if err != "":
            flash(err)
            return redirect(request.url)

        description = request.form['description']
        photo = request.files['photo']

        if photo and allowed_file_image(photo.filename):
            filename_photo = hashlib.md5(photo.read()).hexdigest() + '.jpg'
            photo.seek(0)

            photo_path = os.path.join(app.config['UPLOAD_FOLDER'], filename_photo)

            photo.filename = photo_path
            photo.save(photo_path)
            username = session['user']

            user = User.query.filter_by(username=username).first()

            user_id = user.id

            p = Image(description=description, user_id=user_id, photo=photo_path)
            db.session.add(p)
            db.session.commit()
            flash("UPLOAD SUCCESFUL")
            return redirect(request.url)

    return render_template('upload.html')


@app.route('/index', methods=['GET', 'POST'])
def index():
    return render_template('index.html')


def trim(filename):
    trimmed = filename.rsplit('\\')
    string = ""
    for element in trimmed:
        string += element + "/"
    print(string[:-1])
    return string[4:-1]


@app.route('/get_photos')
def get_photos():
    if request.args.get('description'):
        description = request.args.get('description')
        print(description)
        to_ret = []
        images = Image.query.all()

        for image in images:
            if description in image.description.split(','):
                to_ret.append(image)

        images = {
            'images': []
        }

        for image in to_ret:
            images['images'].append(
                {
                    'image': trim(image.photo),
                    'description': image.description
                }
            )
        return json.dumps(images)

    if request.args.get('user'):

        username = request.args.get('user')
        user = User.query.filter_by(username=username).first()
        images_ = Image.query.filter_by(user_id=user.id)
        images = {
            'images': []
        }
        for image in images_:
            images['images'].append(
                {
                    'image': trim(image.photo),
                    'description': image.description
                }
            )
        return json.dumps(images)


@app.route('/delete_photo')
def delete_photo():

    photo = request.args.get('photo')
    username = session['user']
    user = User.query.filter_by(username=username).first()
    images = Image.query.filter_by(user_id=user.id)

    to_del = None
    for image in images:
        if image.photo.split('\\')[1] == photo:
            to_del = image

    db.session.delete(to_del)
    db.session.commit()

    return json.dumps({})

