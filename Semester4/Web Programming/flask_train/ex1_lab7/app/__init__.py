from flask import Flask

import os

from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

basedir = os.path.abspath(os.path.dirname(__file__))


app = Flask(__name__)

app.config.from_mapping(
    SECRET_KEY='dev',
    SQLALCHEMY_DATABASE_URI=os.environ.get("C:\\sqlite\\databases\\flask.db") or 'sqlite:///' + os.path.join(basedir, 'ex1.db'),
    SQLALCHEMY_TRACK_MODIFICATIONS=False
)

db = SQLAlchemy(app)
migrate = Migrate(app, db)

from app import routes, models


