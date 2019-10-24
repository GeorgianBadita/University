from app import db


class Admin(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(64), index=True, unique=True)
    password = db.Column(db.String(120), index=True, unique=True)

    def __repr__(self):
        return '<Admin {}>'.format(self.username)


class Comment(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    text = db.Column(db.String(512))
    author = db.Column(db.String(64), unique=True, index=True)
    approved = db.Column(db.Integer, default=0)

    def set_approved(self, value):
        self.approved = value

    def __repr__(self):
        return '<Comment {}>'.format(self.text)
