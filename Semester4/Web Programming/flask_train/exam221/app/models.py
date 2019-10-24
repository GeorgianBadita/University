from app import db


class Image(db.Model):

    id = db.Column(db.Integer, primary_key=True)
    description = db.Column(db.String(256))
    photo = db.Column(db.String(256))
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'))

    def __repr__(self):
        return '<Image {}>'.format(
            self.description
        )


class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(256))
    password = db.Column(db.String(256))
    is_admin = db.Column(db.Boolean)
    images = db.relationship('Image', backref='image', lazy='dynamic')

    def __repr__(self):
        return '<User {}, {}>'.format(
            self.username,
            self.password
        )
