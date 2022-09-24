import requests
import pandas as pd
import matplotlib.pyplot as plt
url="https://jhucoronavirus.azureedge.net/api/v1/testing/daily.json"
r = requests.get(url)
json = r.json()
df = pd.DataFrame(json)
#print(df)

selected_featues = ['date','state','people_viral_positive','tests_viral_positive']
for featues in selected_featues:
    if str(df[featues]) == 'NaN':
        df[featues] = float(df[featues].fillna('0.0'))


# plt.figure(figsize=(6.8,4.2))
# x = range(len(df['date']))
# plt.plot(x, df['people_viral_positive'])
# plt.xticks(x, df['date'])
# plt.xlabel('date')
# plt.ylabel('people_viral_positive')
# plt.show()

plt.figure(figsize=(6.8,4.2))
x = range(len(df['date']))
plt.plot(x, df['state'])
plt.xticks(x, df['date'])
plt.xlabel('date')
plt.ylabel('state')
plt.show()