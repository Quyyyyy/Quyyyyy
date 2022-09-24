import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/01-09-2022.csv')
#print(data)


plt.figure(figsize=(6.8,4.2))
x = range(len(data['Long_']))
plt.plot(x, data['Lat'])
plt.xticks(x, data['Long_'])
plt.xlabel('Long_')
plt.ylabel('Lat')
plt.show()
