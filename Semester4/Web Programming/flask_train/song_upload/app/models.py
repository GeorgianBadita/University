from app import db


class Artist(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(256))
    songs = db.relationship('Song', backref='artist', lazy='dynamic')

    def __repr__(self):
        return '<Artist {}>'.format(
            self.name
        )


class Song(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(256))
    artist_id = db.Column(db.Integer, db.ForeignKey('artist.id'))
    song = db.Column(db.String(256))
    lyrics = db.Column(db.String(256))

    def __repr__(self):
        return '<Song {}>'.format(self.title)
