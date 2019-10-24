import pandas as pd
import numpy as np
import librosa
import os

def save_song_features(data, text_file):
    # Write the array to disk
    with open(text_file, 'w') as outfile:
        # I'm writing a header here just for the sake of readability
        # Any line starting with "#" will be ignored by numpy.loadtxt
        outfile.write('# Array shape: {0}\n'.format(data.shape))
        # Iterating through a ndimensional array produces slices along
        # the last axis. This is equivalent to data[i,:,:] in this case
        for data_slice in data:
            # The formatting string indicates that I'm writing out
            # the values in left-justified columns 7 characters in width
            # with 2 decimal places.
            np.savetxt(outfile, data_slice, fmt='%-7.20f')

            # Writing out a break to indicate different slices...
            outfile.write('# New slice\n')


def load_song_features(text_file, shape):
    new_data = np.loadtxt(text_file)
    new_data = new_data.reshape((shape[0]*shape[1], shape[2]))
    return new_data


def write_to_file(text_file, data):
    with open(text_file, 'w') as f:
        f.write(data)


def read_labels_from_file(text_file):
    labels = []
    with open(text_file, 'r') as f:
        line = f.readline()
        while line != '':
            for elem in line:
                if elem != '[' and elem != ']' and elem != ' ':
                    labels.append(int(elem))
            line = f.readline()

        return np.array(labels, dtype=np.int)

def windows(data, window_size):
    start = 0
    while start < len(data):
        yield start, start + window_size
        start += (window_size // 2)
        

def extract_features_language(parent_dir, dataSet, bands=20, frames=41):
    trainData = dataSet
    window_size = 512 * (frames - 1)
    mfccs = []
    
    for i in range(len(dataSet)):
        path1 = os.path.join(parent_dir, trainData.path[i] + ".mp3")
        if i % 100 == 0:
            print("Reached song {0}".format(i))
        sound_clip, s = librosa.load(path1)
        for (start, end) in windows(sound_clip, window_size):
            if len(sound_clip[start:end]) == window_size:
                signal = sound_clip[start:end]
                mfcc = librosa.feature.mfcc(y=signal, sr=s, n_mfcc=bands).T.flatten()[:, np.newaxis].T
                mfccs.append(mfcc)
                

    print("Reached here!")
    features = np.asarray(mfccs).reshape(len(mfccs), frames, bands)
    save_song_features(features, "song_features/de_features.txt")
    
    return np.array(features)


trainPath = "D:\\Audio - dataset_de\\first_20k.tsv"  # todo switch this
trainData = pd.read_csv(trainPath, sep='\t')


tr_features = extract_features_language("D:\\Audio - dataset_de\\clips", trainData)


