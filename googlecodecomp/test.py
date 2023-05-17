import os
import sys
import numpy as np

f = open("in.txt", 'w')
T = np.random.randint(1,100001)
f.write(str(T) + "\n")
for i in range(T):
    N = np.random.randint(1,51)
    K = np.random.randint(1,10001)
    f.write(str(N) + " " + str(K) + "\n")
    for j in range(N):
        f.write(str(np.random.randint(0,K+1)) + " ")
    f.write("\n")
    