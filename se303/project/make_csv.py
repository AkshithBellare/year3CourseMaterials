import pandas as pd

city = pd.DataFrame([['Sacramento', 'California'],['Miami', 'Florida']], columns = ['City', 'State'])

city.to_csv('city.csv')