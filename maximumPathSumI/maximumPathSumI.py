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

tri = np.array((
[0,0,0,3,0,0,0],
[0,0,7,0,4,0,0],
[0,2,0,4,0,6,0],
[8,0,5,0,9,0,3]))

left_sum = 0
right_sum = 0
left_left_sum = 0
right_right_sum = 0
left_right_sum = 0
right_left_sum = 0
total = []
root_col = 0
print tri
for row in range(0,tri.shape[0]):
    if row == 0:
        root_col = int(((len(tri[row])-1)/2))
        print "row: ",row
        print "    root_col: ", root_col
        print "    value: ", tri[row][root_col]
        total.append(tri[row, root_col])
    else:
        lc = root_col-1
        rc = root_col+1
        i = 1
        ll = False
        lr = False
        rr = False
        rl = False
        print "row: ",row

        for rows in range(row+1,tri.shape[0]):
            left_left_sum+=tri[rows,lc-i]
            left_right_sum+=tri[rows,lc+i]
            right_right_sum+=tri[rows,rc+i]
            right_left_sum+=tri[rows,rc-i]
            print "        rows: %s, left_left: %s"%(rows, tri[rows,lc-i])
            print "        rows: %s, left_right: %s"%(rows, tri[rows,lc+i])
            i+=1

        if left_left_sum > left_right_sum:
            left_sum = left_left_sum
            ll = True

        else:
            left_sum = left_right_sum
            lr = True

        if right_right_sum > right_left_sum:
            right_sum = right_right_sum
            rr = True

        else:
            right_sum = right_left_sum
            rl = True
        print "    left_sum: %s, right_sum: %s"%(left_sum,right_sum)
        if left_sum > right_sum:
            root_col = lc
            total.append(tri[row, root_col])
        else:
            root_col = rc
            total.append(tri[row, root_col])
        print "    root_col: ", root_col
        print "    value: ", tri[row][root_col]
        print "    lc: ", tri[row][lc]
        print "    left_left_sum: ",left_left_sum
        print "    left_right_sum: ",left_right_sum
        print "    rc: ", tri[row][rc]
        print "    rigjt_right_sum: ",right_right_sum
        print "    left_left_sum: ",right_left_sum
    left_sum = 0
    right_sum = 0
    left_left_sum = 0
    right_right_sum = 0
    left_right_sum = 0
    right_left_sum = 0

print total
print sum(total)
