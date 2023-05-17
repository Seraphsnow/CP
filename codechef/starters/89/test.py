import os
import sys
import numpy as np

f = open("in.txt", 'w')
T = np.random.randint(1,1001)
f.write(str(T) + "\n")
for i in range(T):
    N = np.random.randint(1,11)
    M = np.random.randint(1,11)
    K = np.random.randint(1,10001)
    f.write(str(N) + " " +str(M) + " " +  str(K) + "\n")
    for j in range(N):
        f.write(str(np.random.randint(1,K+1)) + " ")
    for j in range(M):
        f.write(str(np.random.randint(1,K+1)) + " ")
    f.write("\n")
    