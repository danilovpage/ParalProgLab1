import numpy as np

f = open('D:\\1.txt', 'r')
matrix1 = f.readlines()[1:]
data_1 = np.loadtxt(matrix1)
f.close()

f = open('D:\\2.txt', 'r')
matrix2 = f.readlines()[1:]
data_2 = np.loadtxt(matrix2)
f.close()

f = open('D:\\res.txt', 'r')
matrix3 = f.readlines()[2:]
res = np.loadtxt(matrix3)
f.close()

res_test = np.dot(data_1, data_2)
print(np.array_equal(res, res_test))
