import os
basedir = os.path.abspath(os.path.dirname(__file__))


class Config(object):
    SECRET_KEY = os.environ.get('SECRET_KEY') or 'this-is-my-key'
    SQLALCHEMY_DATABASE_URI = os.environ.get("C:\\sqlite\\databases\\flask.db") or 'sqlite:///' + os.path.join(basedir, 'flask.db')
    SQLALCHEMY_TRACK_MODIFICATIONS = False
