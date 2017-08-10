import numpy as np

tri = np.array(([0,0,0,3,0,0,0],[0,0,7,0,4,0,0],[0,2,0,4,0,6,0],[8,0,5,0,9,0,3]))
left_sum = 0
right_sum = 0
row = 0
root = int(((len(tri[row])-1)/2))
root_i = row
root_j = int(((len(tri[row])-1)/2))
for row in range(1,tri.shape[0]):
     left_sum+=tri[row,root_j-row]
     right_sum+=tri[row,root_j+row]
 
print left_sum
print right_sum

