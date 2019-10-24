import functools

from flask import request, flash, session, url_for, redirect, render_template, g

from app import app, db
from app.models import Admin, Comment


@app.before_request
def load_logged_in_user():
    user_id = session.get('user_id')

    if user_id is None:
        g.user = None
    else:
        g.user = Admin.query.filter_by(username=user_id).first()


def login_required(view):
    @functools.wraps(view)
    def wrapped_view(**kwargs):
        if g.user is None:
            return redirect(url_for('login'))

        return view(**kwargs)

    return wrapped_view


@app.route('/', methods=['GET', 'POST'])
@login_required
def index():
    posts = Comment.query.filter_by(approved=0)
    return render_template('index.html', posts=posts)


@app.route('/login', methods=['POST', 'GET'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        err = None
        admin = Admin.query.filter_by(username=username).first()
        if admin is None:
            err = 'No user with username ' + username
        elif admin.password != password:
            err = 'Wrong password!'

        if err is None:
            session.clear()
            session['user_id'] = username
            return redirect(url_for('index'))

        flash(err)

    return render_template('login.html')


@app.route('/logout', methods=['GET', 'POST'])
@login_required
def logout():
    session.clear()
    return redirect(url_for('index'))


@app.route('/approve/<post_id>', methods=['GET', 'POST'])
def approve(post_id):
    post = Comment.query.filter_by(id=post_id).first()
    if post is not None:
        db.session.delete(post)
        post.set_approved(1)
        db.session.add(post)
        db.session.commit()
    return redirect(url_for('index'))


@app.route('/article', methods=['GET', 'POST'])
def article():

    if request.method == 'POST':
        text = request.form['text']
        author = request.form['author']

        comm = Comment(text=text, author=author)
        db.session.add(comm)
        db.session.commit()
    posts = Comment.query.filter_by(approved=1)

    return render_template('article.html', posts=posts)
