import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

covid_data = pd.read_csv(r'https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/08-08-2022.csv')
ax = plt.subplot()
#ax.scatter(covid_data['Country_Region'][0:10],covid_data['Deaths'][0:10])
#ax.bar(covid_data['Country_Region'][0:10],covid_data['Deaths'][0:10])
ax.plot(covid_data['Country_Region'][0:10],covid_data['Deaths'][0:10])
ax.set_title("Covid Deaths Each Region 08-08-2022")
ax.set_xlabel('Country_Region')
ax.set_ylabel('Deaths')
plt.show()