from flask import Flask
from flask_login import LoginManager

from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

from app.config import Config

app = Flask(__name__)
login = LoginManager(app)
app.config.from_object(Config)
db = SQLAlchemy(app)
migrate = Migrate(app, db)

from app import routes, models
