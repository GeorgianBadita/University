import numpy as np
import pandas as pd

def load_song_features(text_file, shape):
    new_data = np.loadtxt(text_file)
    new_data = new_data.reshape((shape[0], shape[1], shape[2]))
    return new_data

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
                    labels.append(int(elem) - 1)
            line = f.readline()

        return np.array(labels, dtype=np.int)


def one_hot_encode(labels):
    n_labels = len(labels)
    n_unique_labels = len(np.unique(labels))
    one_hot_encode = np.zeros((n_labels, n_unique_labels))
    one_hot_encode[np.arange(n_labels), labels] = 1
    return one_hot_encode


def getTrainData(fileName="", directory="", featureCount=0):

    # 206718, 41, 20
    #(40693, 41, 20)
    shape_features = [40815, 41, 20]
    features = load_song_features("C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\song_features\\fr_features.txt", shape_features)
    # tr_features, tr_labels = extract_features("D:\\Audio - dataset\\clips")
       
    return features

en_features =  getTrainData(fileName="", directory="", featureCount=0)
en_labels = ['en' for x in en_features]

de_features =  getTrainData(fileName="", directory="", featureCount=0)
de_labels = ['de' for x in de_features]

it_features =  getTrainData(fileName="", directory="", featureCount=0)
it_labels = ['it' for x in it_features]

fr_features =  getTrainData(fileName="", directory="", featureCount=0)
fr_labels = ['fr' for x in fr_features]

BATCH = 100
en_f = [en_features[i: i + BATCH] for i in range(0, len(en_features), BATCH)]
fr_f = [fr_features[i: i + BATCH] for i in range(0, len(fr_features), BATCH)]
it_f = [it_features[i: i + BATCH] for i in range(0, len(it_features), BATCH)]
de_f = [de_features[i: i + BATCH] for i in range(0, len(de_features), BATCH)]

fr_f = fr_f + fr_f[:191]
en_f = en_f[:600]
it_f = it_f + it_f[:189]
de_f = de_f + de_f[:193]

concat_f = np.concatenate((en_f[0],fr_f[0],de_f[0],it_f[0]),axis=0)
labels = ['en','fr','de','it']
for i in range(1,600):
    if i%100 == 0:
        print(i)
    concat_f = np.concatenate((concat_f,en_f[i],fr_f[i],de_f[i],it_f[i]),axis=0)
    labels = labels + ['en','fr','de','it']



save_song_features(concat_f, "C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\song_features\\all_features.txt")


string = ""
for e in labels:
    string += " " + str(e)

write_to_file(string, "C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\song_features\\all_labels.txt")


with open("C:\\Users\\georg\\Desktop\\An2_sem2\\Proj_AI\\song_features\\all_labels.txt", 'w') as f:
        f.write(string)
    