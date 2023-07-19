import numpy as np

t = 50
f= open("test.txt", "w")
f.write(str(t)+ "\n")
for i in range(t):
    l = np.random.randint(1,101)
    r = np.random.randint(l, 101)
    f.write(str(l) + " " + str(r) + "\n")
