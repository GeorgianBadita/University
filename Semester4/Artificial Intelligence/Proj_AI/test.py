from keras.models import load_model
import numpy as np
import pandas as pd
import librosa
import os


def windows(data, window_size):
    start = 0
    while start < len(data):
        yield start, start + window_size
        start += (window_size // 2)


def extract_features(parent_dir, dataSet, fileExt=".mp3", bands=20, frames=41, featureCount=10):
    window_size = 512 * (frames - 1)
    mfccs = []
    labels = []
    for i in range(featureCount):
        print("Load sample: " + str(i))
        path1 = os.path.join(parent_dir, dataSet.path[i] + fileExt)
        sound_clip, s = librosa.load(path1)
        label = dataSet.gender[i]
        if label == 'male':
            label = 1
        else:
            label = 0

        for (start, end) in windows(sound_clip, window_size):
            if (len(sound_clip[start:end]) == window_size):
                signal = sound_clip[start:end]
                mfcc = librosa.feature.mfcc(y=signal, sr=s, n_mfcc=bands).T.flatten()[:, np.newaxis].T
                mfccs.append(mfcc)
                labels.append(label)

    features = np.asarray(mfccs).reshape(len(mfccs), frames, bands)
    return np.array(features), np.array(labels)


def load_song_features(text_file, shape):
    new_data = np.loadtxt(text_file)
    new_data = new_data.reshape((shape[0], shape[1], shape[2]))
    return new_data


def read_labels_from_file(text_file):
    labels = []
    with open(text_file, 'r') as f:
        line = f.readline()
        while line != '':
            for elem in line:
                if elem == '0':
                    labels.append(int(elem))
                elif elem == '1':
                    labels.append(int(elem))
            line = f.readline()

        return np.array(labels, dtype=np.int)


def one_hot_encode(labels):
    n_labels = len(labels)
    n_unique_labels = len(np.unique(labels))
    one_hot_encode = np.zeros((n_labels, n_unique_labels))
    one_hot_encode[np.arange(n_labels), labels] = 1
    return one_hot_encode


def getTestData(fromText=False, fileName="", directory="", featureCount=0):
    if not fromText:
        trainData = pd.read_csv(fileName, sep='\t')  # upload the data
        features, labels = extract_features(directory, trainData, ".mp3", bands=20, featureCount=featureCount)

    elif fromText:
        shape_features = [6697, 41, 20]
        features = load_song_features("M:\\SpeechReconProject\\en\\gender_parsed\\feature_test_file.txt", shape_features)
        # tr_features, tr_labels = extract_features("D:\\Audio - dataset\\clips")
        labels = read_labels_from_file("M:\\SpeechReconProject\\en\\gender_parsed\\test_labels_file.txt")

    labels = one_hot_encode(labels)
    return features, labels


features, labels = getTestData(fromText=True, directory="M:\\SpeechReconProject\\en\\clips\\", featureCount=712, fileName="M:\\SpeechReconProject\\en\\testGender.tsv")
model = load_model('ageModel.h5')

y = model.predict_classes(features)
y = one_hot_encode(y)


def test():
    guessed = 0
    for predicted, correct in zip(y, labels):
        if predicted[0] == correct[0] and predicted[1] == correct[1]:
            guessed += 1

    acc = guessed / len(y)

    # print("Model accuracy: " + str(acc))
    return acc
