import os

from flask import Flask
from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
basedir = os.path.abspath(os.path.dirname(__file__))

UPLOAD_FOLDER = 'app/static'
ALLOWED_EXTENSIONS_IMAGE = {'jpg', 'jpeg', 'gif', 'png'}

app.config.from_mapping(
    SECRET_KEY='9OLWxND4o83j4K4iuopO',
    SQLALCHEMY_DATABASE_URI=os.environ.get("C:\\sqlite\\databases\\flask.db") or 'sqlite:///' + os.path.join(basedir, 'db.db'),
    SQLALCHEMY_TRACK_MODIFICATIONS=False,
    UPLOAD_FOLDER=UPLOAD_FOLDER,
)

db = SQLAlchemy(app)
migrate = Migrate(app, db)

from app import models, routes