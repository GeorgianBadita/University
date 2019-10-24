from app import db


class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(128), unique=True)
    password = db.Column(db.String(128))

    def __repr__(self):
        return "<User {}, {}>".format(
            self.username, self.password
        )


class Word(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    word = db.Column(db.String(128), unique=True)
    length = db.Column(db.Integer)

    def __repr__(self):
        return "<Word {}, {}>".format(
            self.word, self.length
        )


class Winner(db.Model):
    id = db.Column(db.Integer, primary_key=True)
