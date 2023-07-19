#!/bin/bash

python3 test.py
g++ binseaslow.cpp
./a.out < input.txt > out1.txt
g++ binsea.cpp
./a.out < input.txt > out2.txt
diff out1.txt out2.txt