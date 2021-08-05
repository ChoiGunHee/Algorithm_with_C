#!/bin/bash

gcc back_22_04.c
echo "Test Start"
echo "Test Case 1"
echo "sol : 1 1 2 2 2 2 5"
./a.out < case_step22_04_1.txt

echo "Test Case 2"
echo "sol : 5 4 4 4 4 4"
./a.out < case_step22_04_2.txt