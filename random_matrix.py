import random
import numpy as np

row1 = 10
col1 = 10

row2 = 10
col2 = 10

f = open('D:\\1.txt', 'w')
f.write(str(row1)+" "+str(col1)+"\n")
for i in range(row1):
    for j in range(col1):
        f.write(f'{random.randint(-10, 10)} ')
    f.write('\n')

f = open('D:\\2.txt', 'w')
f.write(str(row2)+" "+str(col2)+"\n")
for i in range(row2):
    for j in range(col2):
        f.write(f'{random.randint(-10, 10)} ')
    f.write('\n')

