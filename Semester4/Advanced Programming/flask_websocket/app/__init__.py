from flask import Flask
from flask_socketio import join_room, emit, SocketIO

from app.codenames import Game

app = Flask(__name__)


socketio = SocketIO(app)

ROOMS = {}  # for active rooms

from app import routes, sockets

if __name__ == '__main__':
    socketio.run(app)
