import functools
import json

from flask import request, render_template, redirect, url_for, session, g

from app import app, db
from app.models import User, Word


@app.before_request
def load_logged_in_user():
    username = session.get('user_name')

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


@app.route('/', methods=['POST', 'GET'])
def hangman():
    if request.method == 'POST':
        level = session.get('level')
        length = 4
        if level is not None:
            length = 3 + level
        words = Word.query.filter_by(length=length)
        word = words[0].word
        hang_word = ""
        for i in range(len(word)):
            if i == 0 or i == len(word) - 1:
                hang_word += word[i]
            else:
                hang_word += "_"
            session['word'] = word
            session['hang_word'] = hang_word
            session['attempts'] = 0
            level = session.get('level')
            if level is None:
                level = 1
                session['level'] = level

        return json.dumps({'word': hang_word})

    return render_template('hangman.html')


@app.route('/login', methods=['POST', 'GET'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()
        if username == user.username and password == user.password:
            session.clear()
            session['user_name'] = username
            return redirect(url_for('admin'))
    return render_template('login.html')


@app.route('/admin', methods=['POST', 'GET'])
@login_required
def admin():
    if request.method == 'POST':
        word = request.form['word']
        w = Word(word=word)
        db.session.add(w)
        db.session.commit()
    return render_template('admin.html')


@app.route('/logout', methods=['GET', 'POST'])
@login_required
def logout():
    session.clear()
    return redirect(url_for('login'))


@app.route('/check', methods=['GET', 'POST'])
def check():
    done = False
    if request.method == 'POST':

        letter = request.form['letter']
        if len(letter) != 1:
            return json.dumps({"word": session['hang_word']})
        letter = letter[0]
        word = session['word']
        hang_word = [session['hang_word'][i] for i in range(len(session['hang_word']))]
        for i in range(len(word)):
            if word[i] == letter:
                hang_word[i] = letter
        new_hang = ""
        for elem in hang_word:
            new_hang += elem
        session['hang_word'] = new_hang
        session['attempts'] += 1
        if session['word'] == session['hang_word']:
            session['level'] += 1
            if session['level'] == 4:
                session.clear()
                print("DONEEEE")
            done = True

        if done is True:
            return json.dumps({"word": session['hang_word'], "attempts": session['attempts'], "done": 1, "level": session['level']})
        else:
            return json.dumps({"word": session['hang_word'], "attempts": session['attempts'], "done": 0, "level": session['level']})
