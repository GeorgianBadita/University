import pandas as pd
import numpy as np
import librosa
import glob
import os
import tensorflow as tf

from tensorflow.python.ops import rnn

from keras.models import Sequential
from keras.layers.recurrent import LSTM
from keras.layers import Dense
from keras.optimizers import Adam

from keras.models import load_model

#from test import test

trainPath = "M:\\SpeechReconProject\\en\\trainGender.tsv"  # path to the file containing the mp3 fileNames and the genders


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
        line = f.readline().split(' ')
    
        for elem in line:
            to_add = -1
            if elem == 'fr':
                to_add = 1
            elif elem == 'de':
                to_add = 2
            elif elem == 'it':
                to_add = 3
            elif elem == 'en':
                to_add = 0
            
            if to_add != -1:
                labels.append(to_add)
            

        return labels




features = load_song_features("C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\song_features\\all_features.txt", [239864, 41, 20])
labels = read_labels_from_file("C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\song_features\\all_labels.txt")
labels = np.array(labels, dtype=np.int)
labels = one_hot_encode(labels)


lst = [0, 1, 2, 3, 0, 1, 2, 3]
def one_hot_encode(labels):
    n_labels = len(labels)
    n_unique_labels = len(np.unique(labels))
    one_hot_encode = np.zeros((n_labels, n_unique_labels))
    one_hot_encode[np.arange(n_labels), labels] = 1
    return one_hot_encode




def getTrainData(fromText=False, fileName="", directory="", featureCount=0):
    if not fromText:
        trainData = pd.read_csv(fileName, sep='\t')  # upload the data
        print(trainData)
        features, labels = extract_features(directory, trainData, ".mp3", bands=20, featureCount=featureCount)

    elif fromText:
        # 206718, 41, 20
        shape_features = [206718, 41, 20]
        features = load_song_features("C:\\Users\\georg\\Desktop\\An2_sem2\\IA\\ProjAi\\song_features\\age_features.txt", shape_features)
        # tr_features, tr_labels = extract_features("D:\\Audio - dataset\\clips")
        labels = read_labels_from_file("C:\\Users\\georg\\Desktop\\An2_sem2\\IA\\ProjAi\\song_features\\age_labels.txt")

    labels = one_hot_encode(labels)
    return features, labels


def getModel(features, labels, fromFile=False):
    if not fromFile:
        input_shape = (features.shape[1], features.shape[2])
        print("Build LSTM RNN model ...")
        with tf.device('/gpu:0'):
            model = Sequential()

            model.add(LSTM(units=128, dropout=0.3, recurrent_dropout=0.45, return_sequences=True, input_shape=input_shape))
            model.add(LSTM(units=64, dropout=0.2, recurrent_dropout=0.35, return_sequences=True, input_shape=input_shape))
           # model.add(LSTM(units=128, dropout=0.5, recurrent_dropout=0.35, return_sequences=True, input_shape=input_shape))

            model.add(LSTM(units=32, dropout=0.2, recurrent_dropout=0.35, return_sequences=False))
            model.add(Dense(units=labels.shape[1], activation="softmax"))

            print("Compiling ...")
            # Keras optimizer defaults:
            # Adam   : lr=0.001, beta_1=0.9, beta_2=0.999, epsilon=1e-8, decay=0.
            # RMSprop: lr=0.001, rho=0.9, epsilon=1e-8, decay=0.
            # SGD    : lr=0.01, momentum=0., decay=0.
            opt = Adam()
            model.compile(loss="categorical_crossentropy", optimizer=opt, metrics=["accuracy"])
    else:
        model = load_model('genderModel.h5')

    return model


def trainModel(model, features, labels, epochs=20, batchSize=30):
    print("Training ...")

    model.fit(
        features,
        labels,
        batch_size=batchSize,
        epochs=epochs,
    )


model = getModel(features, labels)
 
trainModel(model, features, labels)

features, labels = [], []

features, labels = getTrainData(fromText=True, directory="M:\\SpeechReconProject\\en\\clips\\", featureCount=5, fileName="M:\\SpeechReconProject\\en\\womanForGender.tsv")


features, labels = [],[]

features, labels = getTrainData(fromText=True,directory="M:\\SpeechReconProject\\en\\clips\\",featureCount=700, fileName="M:\\SpeechReconProject\\en\\trainGender.tsv")



class_map = {'teens': 0, 'twenties': 0, 'thirties': 0, 'fourties': 0, 'fifties': 0, 'sixties': 0, 'seventies': 0}


for label in labels:
    if label[0] == 1:
        class_map['teens'] += 1
    elif label[1] == 1:
        class_map['twenties'] += 1
    elif label[2] == 1:
        class_map['thirties'] += 1
    elif label[3] == 1:
        class_map['fourties'] += 1
    elif label[4] == 1:
        class_map['fifties'] += 1
    elif label[5] == 1:
        class_map['sixties'] += 1
    elif label[6] == 1:
        class_map['seventies'] += 1

for key in class_map:
    print(key, class_map[key])



featuresNew, labelsNew = [],[]
maleLimit = 5729
maleByNow = 0

for f,l in zip(features, labels):
    if l[0] == 1 or (maleByNow < maleLimit):
        if l[0] == 0:
            maleByNow += 1
        
        featuresNew.append(f)
        labelsNew.append(l)
        
featuresNew = np.asarray(featuresNew).reshape(11458,41, 20)
labelsNew = np.asarray(labelsNew).reshape(11458,2)


with tf.device('/gpu:0'):
    #model = load_model('ageModel.h5')
    model = getModel(features, labels)

    trainModel(model, features, labels, epochs=10)
    #result = predict("C:\\Users\\georg\\Desktop\\An2_sem2\\IA\\AI_untouched\\audios\\diana1.aac")
    #print("======================================================" + str(result))

print("Saving model")
model.save('newAgeModel.h5')
