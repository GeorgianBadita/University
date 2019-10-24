import hashlib
import json
import os

from flask import render_template, request, flash, redirect, url_for

from app import app, ALLOWED_EXTENSIONS_AUDIO, ALLOWED_EXTENSIONS_LYRICS, db
from app.models import Artist, Song


def allowed_file_audio(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS_AUDIO


def allowed_file_lyrics(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS_LYRICS


@app.route('/upload', methods=['GET', 'POST'])
@app.route('/', methods=['GET', 'POST'])
def upload_song():
    if request.method == 'POST':
        err = ""
        print(request.form)
        if 'artist' not in request.form:
            err += "Artist not given\n"
        if 'title' not in request.form:
            err += "Title not given\n"
        if 'song' not in request.files:
            err += "Song not given\n"
        if 'lyrics' not in request.files:
            err += "Lyrics not given\n"
        if err != "":
            flash(err)
            return redirect(request.url)

        artist = request.form['artist']
        title = request.form['title']
        song = request.files['song']
        lyrics = request.files['lyrics']

        if song and allowed_file_audio(song.filename) and lyrics and allowed_file_lyrics(lyrics.filename):
            filename_song = hashlib.md5(song.read()).hexdigest() + '.mp3'
            song.seek(0)
            filename_lyrics = hashlib.md5(lyrics.read()).hexdigest() + '.csv'
            lyrics.seek(0)

            song_path = os.path.join(app.config['UPLOAD_FOLDER'], filename_song)
            lyrics_path = os.path.join(app.config['UPLOAD_FOLDER'], filename_lyrics)

            song.filename = song_path
            lyrics.filename = lyrics_path

            song.save(song_path)
            lyrics.save(lyrics_path)

            a = Artist.query.filter_by(name=artist).first()

            if a is None:
                a = Artist(name=artist)
                db.session.add(a)
                db.session.commit()

            s = Song(title=title, artist=a, song=song_path, lyrics=lyrics_path)
            db.session.add(s)
            db.session.commit()

            flash("UPLOAD SUCCESSFUL")
            return redirect(request.url)

    return render_template("add_song.html")


def trim(url):
    split = url.split('\\')
    return 'uploads/' + split[len(split) - 1]


@app.route('/index', methods=['GET', 'POST'])
def index():
    songs = {}
    all_songs = Song.query.all()
    for song in all_songs:
        artist_id = song.artist_id
        artist = Artist.query.filter_by(id=artist_id).first()
        ret = songs.get(artist.name)
        if ret is None:
            songs[artist.name] = [{
                'title' : song.title,
                'song': trim(song.song)
            }]
        else:
            songs[artist.name].append({
                'title': song.title,
                'song': trim(song.song)
            })

    print(songs)

    return render_template('index.html', songs=songs)


@app.route("/get_lyrics", methods=['GET'])
def get_lyrics():
    song_name = request.args.get('song')
    all_songs = Song.query.all()
    path = ""
    for song in all_songs:
        if song.song.split('\\')[1] == song_name:
            path = song.lyrics
    lyrics = {
        'lyrics': [

        ]
    }
    with open(path, 'r') as f:
        line = f.readline()
        while line != "":
            line = line.split(',')
            lyrics['lyrics'].append(
                {
                    'start': line[0],
                    'stop': line[1],
                    'words': line[2].split('\n')[0]
                }
            )
            line = f.readline()

    return json.dumps(lyrics)
