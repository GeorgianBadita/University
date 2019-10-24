from app import db


class Question(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    text = db.Column(db.String(512))
    a1 = db.Column(db.String(512))
    a2 = db.Column(db.String(512))
    a3 = db.Column(db.String(512))
    ca = db.Column(db.Integer)

    def __repr__(self):
        return "<Question {}, {}, {}, {}>".format(
            self.text, self.a1, self.a2, self.a3
        )

