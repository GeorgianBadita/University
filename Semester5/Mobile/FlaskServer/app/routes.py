import json

from app import app


@app.route('/')
def hello_world():
    return 'Hello World!'


@app.route('/data/<url_data>', methods=['POST', 'GET'])
def get_data(url_data):
    data = {'note': url_data}
    return json.dumps(data)
