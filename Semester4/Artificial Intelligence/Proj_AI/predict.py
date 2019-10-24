import keras
from keras.models import load_model
import librosa, os, numpy as np


def windows(data, window_size):
    start = 0
    while start < len(data):
        yield start, start + window_size
        start += (window_size // 2)


def extract_features(filePath, bands=20, frames=41):
    window_size = 512 * (frames - 1)
    mfccs = []
    labels = []

    sound_clip, s = librosa.load(filePath)

    for (start, end) in windows(sound_clip, window_size):
        if (len(sound_clip[start:end]) == window_size):
            signal = sound_clip[start:end]
            mfcc = librosa.feature.mfcc(y=signal, sr=s, n_mfcc=bands).T.flatten()[:, np.newaxis].T
            mfccs.append(mfcc)

    features = np.asarray(mfccs).reshape(len(mfccs), frames, bands)
    return np.array(features)


def predict(pathToAudio):
    '''

    :param pathToAudio:
    :return:    dictionary with : male,percentage    female,percentage
    '''
    model = load_model('newAgeModel.h5')

    features = extract_features(pathToAudio)

    y = model.predict_classes(features)

    class_map = {'teens': 0, 'twenties': 0, 'thirties': 0, 'fourties': 0, 'fifties': 0, 'sixties': 0, 'seventies': 0}
    print(y)
    for label in y:
        if label == 0:
            class_map['teens'] += 1
        elif label == 1:
            class_map['twenties'] += 1
        elif label == 2:
            class_map['thirties'] += 1
        elif label == 3:
            class_map['fourties'] += 1
        elif label == 4:
            class_map['fifties'] += 1
        elif label == 5:
            class_map['sixties'] += 1
        elif label == 6:
            class_map['seventies'] += 1

    sum_ = 0
    for key in class_map:
        sum_ += class_map[key]

    for key in class_map:
        class_map[key] //= sum_

    return class_map


print(predict("audios/old_man.mp3"))
# print(predict("C:\\Users\\mihai\\Desktop\\test_samples\\diana8.m4a"))
