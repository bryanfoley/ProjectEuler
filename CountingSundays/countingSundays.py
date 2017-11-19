import datetime
count = 0
for year in range(1901,2001):
    for month in range(1,13):
        dt = datetime.date(year,month,1)
        if dt.strftime("%a")=='Sun':
            count+=1

print count