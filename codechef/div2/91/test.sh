#!/bin/bash

#python3 test.py

g++ xorandsumslow.cpp
./a.out < test.txt > out1.txt

g++ xorandsum.cpp
./a.out < test.txt > out2.txt

diff out1.txt out2.txt