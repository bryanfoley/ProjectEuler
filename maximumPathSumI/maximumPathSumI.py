import numpy as np

tri = np.array((
[00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 75, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 95, 00, 64, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 17, 00, 47, 00, 82, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 18, 00, 35, 00, 87, 00, 10, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 20, 00, 04, 00, 82, 00, 47, 00, 65, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 00, 00, 00, 19, 00, 01, 00, 23, 00, 75, 00, 03, 00, 34, 00, 00, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 00, 00, 88, 00, 02, 00, 77, 00, 73, 00, 07, 00, 63, 00, 67, 00, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 00, 99, 00, 65, 00, 04, 00, 28, 00, 06, 00, 16, 00, 70, 00, 92, 00, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 00, 41, 00, 41, 00, 26, 00, 56, 00, 83, 00, 40, 00, 80, 00, 70, 00, 33, 00, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 00, 41, 00, 48, 00, 72, 00, 33, 00, 47, 00, 32, 00, 37, 00, 16, 00, 94, 00, 29, 00, 00, 00, 00, 00],
[00, 00, 00, 00, 53, 00, 71, 00, 44, 00, 65, 00, 25, 00, 43, 00, 91, 00, 52, 00, 97, 00, 51, 00, 14, 00, 00, 00, 00],
[00, 00, 00, 70, 00, 11, 00, 33, 00, 28, 00, 77, 00, 73, 00, 17, 00, 78, 00, 39, 00, 68, 00, 17, 00, 57, 00, 00, 00],
[00, 00, 91, 00, 71, 00, 52, 00, 38, 00, 17, 00, 14, 00, 91, 00, 43, 00, 58, 00, 50, 00, 27, 00, 29, 00, 48, 00, 00],
[00, 63, 00, 66, 00, 04, 00, 68, 00, 89, 00, 53, 00, 67, 00, 30, 00, 73, 00, 16, 00, 69, 00, 87, 00, 40, 00, 31, 00],
[04, 00, 62, 00, 98, 00, 27, 00, 23, 00, 9, 00, 70, 00, 98, 00, 73, 00, 93, 00, 38, 00, 53, 00, 60, 00, 04, 00, 23]))

# tri = np.array((
# [0,0,0,3,0,0,0],
# [0,0,7,0,4,0,0],
# [0,2,0,4,0,6,0],
# [8,0,5,0,9,0,3]
# ))

nRows, nCols = tri.shape[0],tri.shape[1]
rowUpdate,colUpdate=0,2
rowShift, colShift = 1, nCols
leftShiftRow, leftShiftCol = 0,0
middleShiftRow,middleShiftCol = 1,1
rightShiftRow, rightShiftCol = 0,leftShiftCol+2
rowShifts=0

while rowShifts < nRows-1:
    print rowShifts
    columnShifts = 0
    while columnShifts < nCols/(colUpdate+rowUpdate):
        left,middle,right = tri[nRows-(rowShift+leftShiftRow)][nCols-(colShift+leftShiftCol)],\
        tri[nRows-(rowShift+middleShiftRow)][nCols-(colShift-middleShiftCol)],\
        tri[nRows-(rowShift+rightShiftRow)][nCols-(colShift-rightShiftCol)]
        print left,middle,right
        left_sum = left+middle
        right_sum = middle+right
        print "Left sum = %d, Right sum = %d"%(left_sum, right_sum)
        # update the middle to the new max
        tri[nRows-(rowShift+middleShiftRow)][nCols-(colShift-middleShiftCol)] = left_sum if (left_sum> right_sum) else right_sum 

        colShift-=colUpdate
        print "colShift = %d"%colShift
        columnShifts+=1

    for i in range(0,nCols):
        tri[nRows-rowShift][i] = 0
    print tri
    rowUpdate+=1
    colShift=nCols-rowUpdate
    rowShift+=rowUpdate
    rowShifts+=1

    if rowShifts == nRows-2:
        print "Final result"
        # Special case of the top of the pyramid
        left_sum = tri[0][(nCols-1)/2]+ tri[1][(nCols/2)-1]
        right_sum = tri[0][(nCols-1)/2]+ tri[1][(nCols/2)+1]

        tri[0][(nCols-1)/2] = left_sum if (left_sum> right_sum) else right_sum
        for i in range(0, nCols):
            tri[1][i] = 0

        print tri

        break
