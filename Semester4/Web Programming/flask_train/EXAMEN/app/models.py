from app import db


class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(64), index=True, unique=True)
    password = db.Column(db.String(128), index=True)

    def __repr__(self):
        return '<User {}>'.format(
            self.username
        )


class Event(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    date = db.Column(db.String(256))
    time = db.Column(db.String(256))
    description = db.Column(db.String(256))

    def __repr__(self):
        return '<Event {}, {}, {}>'.format(
            self.date,
            self.time,
            self.description
        )
