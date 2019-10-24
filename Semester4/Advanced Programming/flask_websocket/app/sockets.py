from flask_socketio import join_room, emit, send

from app import socketio, Game, ROOMS


@socketio.on('create')
def on_create(data):
    """
    Create a game lobby
    :param data:
    :return:
    """

    gm = Game(data['id'],
              data['teams'])
    room = gm.id
    ROOMS[room] = gm
    join_room(room)
    emit('join_room', {'room': room})


@socketio.on('join')
def on_join(data):
    room = data['room']
    if room in ROOMS:
        join_room(room)
        send(ROOMS[room].to_json(), room=room)
    else:
        emit('error', {'error': 'Unable to join room. Room does not exist'})


@socketio.on('flip_card')
def on_flip_card(data):
    room = data['room']
    card = data['card']
    ROOMS[room].flip_card(card)
    send(ROOMS[room].to_json(), room=room)


def message_received(methods=['GET', 'POST']):
    print('message was received!!!')


@socketio.on('my_event')
def handle_my_custom_event(json, methods=['GET', 'POST']):
    print('received my event: ' + str(json))
    socketio.emit('my_response', json, callback=message_received)
