import collections
names={}
names_list = []
with open("p022_names.txt","rb") as handle:
    for item in handle.readlines():
        names_list=item.split(",")
for name in names_list:
    sum=0
    for letter in name.replace('"',""):
        sum+=ord(letter)-64
    names[name.replace('"',"")]=sum
names = collections.OrderedDict(sorted(names.items(), key=lambda t: t[:]))
totalSum=0    
items = list(names.items())
for i in range(0,len(names.keys())):
    totalSum+=items[i][1]*(i+1)

print totalSum


