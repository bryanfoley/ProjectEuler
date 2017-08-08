primeElements = {'0':0,'1':3,'2':3,'3':5,'4':4,'5':4,'6':3,'7':5,'8':5,'9':4,'10':3,'11':6
,'12':6,'13':8,'14':8,'15':7,'16':7,'17':9,'18':8,'19':7,'teen':4,'ty':2,'20':6,'30':6,'40':5,'50':5,'60':5,'70':7,'80':6,'90':6,'00':7,'and':3,'000':8}

sum = 0
for num in range(1,1001):
    try:
    	value = primeElements[str(num)]
        sum+= value
    except:
        if 20 <= num < 100:
            coeff = 1
            value = primeElements[str((num/10**coeff)*10**coeff)] + primeElements[str(num%10**coeff)]
            sum+= value
        if 100 <= num < 1000:
            coeff = 2
            if num%10**coeff == 0:
                value = primeElements[str(num/10**coeff)] + primeElements['00']
            else:
                value1 = primeElements[str(num/10**coeff)] + primeElements['00'] + primeElements['and'] 
                if (num%10**coeff) > 20:
                    value2 = primeElements[str(((num%10**coeff)/10**(coeff-1))*(10**(coeff-1)))] \
                        + primeElements[str((num%10**coeff)%10**(coeff-1))]
                else:
                    value2 = primeElements[str(num%10**coeff)]
                value = value1+value2
            sum+= value
        if num == 1000:
            value = primeElements['1'] + primeElements['000'] 
            sum += value
    print num, value
    
print sum
