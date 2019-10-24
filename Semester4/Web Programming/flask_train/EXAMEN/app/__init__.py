from flask import Flask
import os

from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

basedir = os.path.abspath(os.path.dirname(__file__))

app.config.from_mapping(
    SECRET_KEY='zx8j1k2nxz0cal2k2',
    SQLALCHEMY_DATABASE_URI=os.environ.get("C:\\sqlite\\databases\\flask.db") or 'sqlite:///' + os.path.join(basedir, 'bank.db'),
    SQLALCHEMY_TRACK_MODIFICATIONS=False,
)

db = SQLAlchemy(app)
migrate = Migrate(app, db)
from app import routes, models