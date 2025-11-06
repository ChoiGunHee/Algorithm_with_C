#!/bin/bash

# Compile the C program
gcc Problem_010871.c -o Problem_010871

# Run the compiled program with automatic input
echo -e "10 5\n1 10 4 9 2 3 8 5 7 6" | ./Problem_010871
