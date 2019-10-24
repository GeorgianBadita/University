import json

from flask import render_template, request, redirect, url_for

from app import app
from app.models import Question


@app.route('/')
def hello_world():
    return render_template('index.html')


@app.route('/get_questions', methods=['POST'])
def get_questions():
    if request.method == 'POST':
        all_questions = Question.query.all()
        index = int(request.form['index'])
        questions = all_questions[index - 1:index + 2]
        json_dict = {'questions': []}
        for question in questions:
            question_dict = {'text': question.text, 'a1': question.a1, 'a2': question.a2, 'a3': question.a3}
            json_dict['questions'].append(question_dict)
        return json.dumps(json_dict)

    return redirect(url_for('index'))
