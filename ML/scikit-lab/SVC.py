import csv
import numpy as np
from sklearn.decomposition import PCA
from sklearn import svm
from sklearn import datasets

def test():
    digits = datasets.load_digits()
    X, y = digits.data, digits.target

    clf = svm.SVC(gamma=0.001, C=100.)
    clf.fit(digits.data[:-1], digits.target[:-1])

    print("%s %s" % (clf.predict(digits.data[-1:]), digits.target[-1]))


def practice():
    data = []
    target = []
    count = 0
    with open('train.csv') as csvfile:
        spamreader = csv.reader(csvfile)
        for row in spamreader:
            count += 1
            if count == 1:
                continue
            if count == 1000:
                break
            data.append(row[1:])
            target.append(row[0])

    m = len(data)
    t = m // 2
    data = np.array(data[:t])

    print(len(data[0]))
    pca = PCA(n_components = len(data[0]))
    data = pca.fit_transform(data)
    print(len(data[0]))

        
    #clf = svm.SVC(gamma=0.001, C=100.)
    #clf.fit(data[:t], target[:t])
    #r = clf.predict(data[t:])

    #yes = 0
    #for i in range(len(r)):
    #    if r[i] == target[t + i]:
    #        yes += 1
    #print("%s" % (yes / (m - t)))
practice()
