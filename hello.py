
import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
import seaborn as sns

import os
for dirname, _, filenames in os.walk('/kaggle/input'):
    for filename in filenames:
        print(os.path.join(dirname, filename))
import warnings
warnings.filterwarnings('ignore')
X_train = pd.read_csv('C:/Users/HP/Downloads/winequality-red.csv')
#print(X_train)

from sklearn import set_config
set_config(print_changed_only=False)


purple = ['#491D8B','#6929C4','#8A3FFC','#A56EFF',
          '#BE95FF','#CA96EC','#A163CF','#29066B',
          '#7D3AC1','#AF4BCE','#DB4CB2','#EB548C',
          '#EC96E0','#A2128E','#E8D9F3','#641811']

sns.palplot(purple, size = 2)
df = pd.read_csv('C:/Users/HP/Downloads/winequality-red.csv')
df.head(n=10).style.background_gradient(cmap="Purples_r")



df.describe().T.style.background_gradient(cmap="magma")

print("Totally there are {} null value in the dataset".format(df.isnull().sum().sum()))

df.rename(columns={"fixed acidity":"fixed_acidity","volatile acidity":"volatile_acidity",
                    "citric acid":"citric_acid","residual sugar":"residual_sugar",
                    "chlorides":"chlorides","free sulfur dioxide":"free_sulfur_dioxide",
                    "total sulfur dioxide":"total_sulfur_dioxide"}, inplace=True)

fig, axes = plt.subplots(1, 3, figsize = (40,10))

sns.histplot(ax = axes[0],x=df['fixed_acidity'],
            bins = 10,
            kde = True,
            cbar = True,
            color ="#CA96EC").set(title = "Distribution of 'fixed_acidity");

sns.histplot(ax = axes[1],x=df['volatile_acidity'],
            bins = 10,
            kde = True,
            cbar = True,
            color ="#A163CF").set(title = "Distribution of 'volatile_acidity");

sns.histplot(ax = axes[2],x=df['citric_acid'],
            bins = 10,
            kde = True,
            cbar = True,
            color ="#29066B").set(title = "Distribution of 'citric_acid");

fig, axes = plt.subplots(2, 2, figsize = (15,10))
axes = axes.flatten()

sns.scatterplot(ax = axes[0],
                x = "residual_sugar",
                y = "quality", hue = "quality",
                data = df).set(title = "Relationship between 'residual_sugar' and 'quality'");

sns.scatterplot(ax = axes[1],
                x = "alcohol",
                y = "quality", hue = "quality",
                data = df).set(title = "Relationship between 'alcohol' and 'quality'");

sns.scatterplot(ax = axes[2],
                x = "pH",
                y = "quality", hue = "quality",
                data = df).set(title = "Relationship between 'pH' and 'quality'");

sns.scatterplot(ax = axes[3],
                x = "density",
                y = "quality", hue = "quality",
                data = df).set(title = "Relationship between 'density' and 'quality'");

plt.figure(figsize=[20,10],facecolor='white')
sns.heatmap(df.corr(), annot = True, linewidths=2,cmap="magma")
plt.show()
