from flask import Flask
import os

from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
basedir = os.path.abspath(os.path.dirname(__file__))

UPLOAD_FOLDER = 'app/static/uploads'
ALLOWED_EXTENSIONS_AUDIO = {'mp3'}
ALLOWED_EXTENSIONS_LYRICS = {'csv'}

app.config.from_mapping(
    SECRET_KEY='9OLWxND4o83j4K4iuopO',
    SQLALCHEMY_DATABASE_URI=os.environ.get("C:\\sqlite\\databases\\flask.db") or 'sqlite:///' + os.path.join(basedir, 'db.db'),
    SQLALCHEMY_TRACK_MODIFICATIONS=False,
    UPLOAD_FOLDER=UPLOAD_FOLDER,
)

db = SQLAlchemy(app)
migrate = Migrate(app, db)

from app import models, routes