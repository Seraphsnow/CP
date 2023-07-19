import numpy as np
n = 5
m = 6
file = open("out.txt", 'w')
file.write(str(n) + " " + str(m) +"\n")
for i in range(m):
    u = np.random.randint(1,n)
    v = np.random.randint(u+1,n+1)
    y = np.random.randint(1, 100)
    file.write(str(u) + " " + str(v) + " " + str(y) + "\n")