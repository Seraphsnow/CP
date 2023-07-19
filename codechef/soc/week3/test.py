import sys
import numpy as np

t = 10
n = np.random.randint(3, 7)
u = np.random.randint(5, 26)

with open('input.txt', 'w') as f:
    f.write(str(t) + "\n")

    for j in range(t):
        a = []
        b = []
        for i in range(n):
            a.append(np.random.randint(2, 11))
            b.append(np.random.randint(1, a[i]))

        f.write(str(n) + " ")
        f.write(str(u) + "\n")
        for i in range(n):
            f.write(str(a[i]) + " ")
        f.write("\n")
        for i in range(n):
            f.write(str(b[i]) + " ")
        f.write("\n")

