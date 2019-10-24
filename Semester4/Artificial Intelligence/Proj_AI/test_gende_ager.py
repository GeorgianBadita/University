from recorder import recorder
import keras
from keras.models import load_model
import librosa, os, numpy as np



PATH_TO_AUDIO = "C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\audios\\diana20sec.aac"
PATH_TO_GENDER_MODEL = "C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\models\\genderModelSimple.h5"
PATH_TO_AGE_MODEL = "C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\models\\newAgeModelOverTrained.h5"
PATH_TO_LANGUAGE_MODEL = "C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\models\\languageModel.h5"

recorder.record(PATH_TO_AUDIO, 5)


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


def predict_age(pathToAudio, model):
    '''

    :param pathToAudio:
    :return:    dictionary with : male,percentage    female,percentage
    '''
    #model = load_model(path_to_model)

    features = extract_features(pathToAudio)

    y = model.predict_classes(features)

    class_map = {'teens': 0, 'twenties': 0, 'thirties': 0, 'fourties': 0, 'fifties': 0, 'sixties': 0, 'seventies': 0}
    
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
        class_map[key] /= sum_

    return class_map

def predict_language(pathToAudio, model):
    features = extract_features(pathToAudio)
    y = model.predict_classes(features)
    class_map = {'en' : 0, 'de' : 0, 'it' : 0, 'fr' : 0}
    
    for label in y:
        if label == 0:
            class_map['en'] += 1
        elif label == 1:
            class_map['fr'] += 1
        elif label == 2:
            class_map['de'] += 1
        elif label == 3:
            class_map['it'] += 1

    sum_ = 0
    for key in class_map:
        sum_ += class_map[key]

    for key in class_map:
        class_map[key] /= sum_

    return class_map


def predict_gender(pathToAudio, model):
    '''

    :param pathToAudio:
    :return:    dictionary with : male,percentage    female,percentage
    '''
    #model = load_model(path_to_model)

    features = extract_features(pathToAudio)

    y = model.predict_classes(features)

    male, female = 0,0
    for pred in y:
        if pred == 0:
            female += 1
        else:
            male += 1

    maleProb = male/(male+female)
    femaleProb = female/(male+female)

    return {'male':maleProb, 'female':femaleProb}



gender_model = load_model(PATH_TO_GENDER_MODEL)
age_model = load_model(PATH_TO_AGE_MODEL)
language_model = load_model(PATH_TO_LANGUAGE_MODEL)

print(predict_gender(PATH_TO_AUDIO, gender_model))
print(predict_age(PATH_TO_AUDIO, age_model))
print(predict_language(PATH_TO_AUDIO, language_model))

