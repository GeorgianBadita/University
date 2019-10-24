import numpy as np
import pandas as pd
import operator

# https://www.kaggle.com/primaryobjects/voicegender/data - SOURCE OF DATA AND ITS MEANING
dataset = pd.read_csv('data/voice.csv')

for col in dataset.drop(['label'], 1):
    mu = np.mean(np.array(dataset[col]))
    sd = np.std(np.array(dataset[col]))
    dataset[col] = np.divide(np.subtract(np.array(dataset[col]), mu), sd)

dataset = dataset.sample(frac=1, random_state=43)

train_size = int(dataset.shape[0] * 0.7)
test_size = int(dataset.shape[0] * 0.3)

[train_data, test_data] = [dataset[:train_size], dataset[train_size:]]

# X = train_data.loc[:,dataset.columns != 'label'].as_matrix()
X = np.array(train_data.drop(['label'], 1))
# y = train_data.loc[:,dataset.columns == 'label'].as_matrix()
y = np.array(train_data[['label']])
# X_test = test_data.loc[:,dataset.columns != 'label'].as_matrix()
X_test = np.array(test_data.drop(['label'], 1))
# y_test = test_data.loc[:,dataset.columns == 'label'].as_matrix()
y_test = np.array(test_data[['label']])

predictions = np.empty((y_test.shape[0], 1), dtype=object)
k = 1

print(X_test.shape)
print(y_test.shape)
print(X.shape)
print(y.shape)

for i in range(X_test.shape[0]):
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