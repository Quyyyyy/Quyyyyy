import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
import seaborn as sns
import os

X_train = pd.read_csv('C:/Users/HP/Downloads/winequality-red.csv')

X_train.drop(labels=['chlorides'], axis=1, inplace = True)
X_train.shape
#print(X_train)


from sklearn.feature_selection import VarianceThreshold
sel = VarianceThreshold(threshold=1)
sel.fit(X_train)
sum(sel.get_support())
print(X_train.columns)
len(X_train.columns[sel.get_support()])
print(
    len([
        x for x in X_train.columns
        if x not in X_train.columns[sel.get_support()]
    ]))

[x for x in X_train.columns if x not in X_train.columns[sel.get_support()]]

X_train = sel.transform(X_train)
X_train.shape
X_train = np.array(X_train)
X_train = pd.DataFrame(X_train)
X_train.to_csv('winequality-red.csv')
X_train.columns = ['fixed acidity','volatile acidity','alcohol','dioxide','pH']
print(X_train)
print(X_train.shape)
