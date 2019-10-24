from flask import render_template

from app import app


@app.route('/index')
def hello_world():
    return render_template('index.html')


@app.route('/')
def sessions():
    return render_template('session.html')

