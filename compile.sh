#!/bin/sh
clear
g++ -std=gnu++0x main.cpp -O3 -s -DNDEBUG
time ./a.out word3.txt out.txt
