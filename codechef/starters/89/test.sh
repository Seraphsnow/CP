#!/bin/bash

python3 test.py
g++ twoavg.cpp
./a.out < in.txt > out1.txt
g++ twoavgact.cpp
./a.out < in.txt > out2.txt
diff out1.txt out2.txt
