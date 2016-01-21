import sys
from sklearn import linear_model

x = []
y = []

with open('log') as f:
    for line in f:
        items = line.strip().split(" ")
        x.append([int(items[0])])
        y.append([int(items[1])])

clf = linear_model.LinearRegression()

clf.fit(x, y)
print(clf.coef_)
print(clf.intercept_)
#print(clf.predict([[10, 1]]))
