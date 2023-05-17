#!/bin/bash

python3 test.py
g++ banbunslow.cpp
./a.out < in.txt > out1.txt
g++ banbun.cpp
./a.out < in.txt > out2.txt
diff out1.txt out2.txt
