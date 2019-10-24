import numpy as np
import pandas as pd
import operator


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

        return labels


def load_song_features(text_file, shape):
    new_data = np.loadtxt(text_file)
    new_data = new_data.reshape((shape[0], shape[1], shape[2]))
    return new_data


def append_labels(text_file, labels):
    """

    :param text_file:
    :param labels:
    :return:
    """
    line_ind = 0
    with open(text_file, "r") as f:
        line = f.readline()
        if line != "":
            if line[0] != "#":
                line += " " + str(labels[line_ind])
        f.write(line)


"""
dataset = pd.read_csv('data/voice.csv')

for col in dataset.drop(['label'], 1):
    mu = np.mean(np.array(dataset[col]))
    sd = np.std(np.array(dataset[col]))
    dataset[col] = np.divide(np.subtract(np.array(dataset[col]), mu), sd)

dataset = dataset.sample(frac=1, random_state=43)
"""

dataset = load_song_features("C:\\Users\\georg\\Desktop\\An2_sem2\\IA\\ProjAi\\song_features\\features_file.txt", [77839, 41, 20])
label_set = read_labels_from_file("C:\\Users\\georg\\Desktop\\An2_sem2\\IA\\ProjAi\\song_features\\labels_file.txt")

cnt = 0
d3_mat = []
for frame in dataset:
    d2_mat = []
    for line in frame:
        d2_line = list(line) + [label_set[cnt]]
        d2_mat.append(d2_line)

    d3_mat.append(d2_mat)
    cnt += 1

dataset = np.array(d3_mat)

print("Loaded dataset with shape " + str(dataset.shape))

dataset = dataset.reshape((dataset.shape[0]*dataset.shape[1], dataset.shape[2]))

train_size = int(dataset.shape[0] * 0.7)
test_size = int(dataset.shape[0] * 0.3)

[train_data, test_data] = [dataset[:train_size], dataset[train_size:]]

# X = train_data.loc[:,dataset.columns != 'label'].as_matrix()
X = np.array([x[:-1] for x in train_data])
# y = train_data.loc[:,dataset.columns == 'label'].as_matrix()
y = np.reshape(np.array([x[-1] for x in train_data]), (train_data.shape[0], 1))
# X_test = test_data.loc[:,dataset.columns != 'label'].as_matrix()
X_test = np.array([x[:-1] for x in test_data])
# y_test = test_data.loc[:,dataset.columns == 'label'].as_matrix()
y_test = np.reshape(np.array([x[-1] for x in test_data]), (test_data.shape[0], 1))

predictions = np.empty((y_test.shape[0], 1), dtype=object)
k = 1

print(X_test.shape)
print(y_test.shape)
print(X.shape)
print(y.shape)

for i in range(X_test.shape[0]):
    
    print("Reached sample {0}".format(i))
    distances = np.zeros((y.shape))
    dist_sum = np.sum(np.power(np.subtract(X, np.tile(X_test[i], (X.shape[0], 1))), 2), axis=1)
    distances[:, 0] = dist_sum
    distances = np.sqrt(distances)

    dist_tupls = []

    for j in range(distances.shape[0]):
        dist_tupls.append((distances[j][0], y[j][0]))

    dist_tupls.sort(key=operator.itemgetter(0))

    classVotes = {}
    for j in range(k):
        response = dist_tupls[j][-1]
        if response in classVotes:
            classVotes[response] += 1
        else:
            classVotes[response] = 1

    sortedVotes = sorted(classVotes.items(), key=operator.itemgetter(1), reverse=True)

    predictions[i, :] = sortedVotes[0][0]

acc = np.mean(predictions == y_test) * 100
print('Accuracy: ', acc)
