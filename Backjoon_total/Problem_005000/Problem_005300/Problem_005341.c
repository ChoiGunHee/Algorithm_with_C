/**
* 2025. 12. 01
* Creater : Gunhee Choi
* Problem Number : 5341
* Title : Pyramids

* Problem :
A pyramid of blocks is constructed by first building a base layer of n blocks and then adding n-1 blocks to the next layer.
This process is repeated until the top layer only has one block.
You must calculate the number of blocks needed to construct a pyramid given the size of the base.
For example, a pyramid that has a base of size 4 will need a total of 10 blocks.

* Input :
The input will be a sequence of integers, one per line. The end of input will be signaled by the integer 0, and does not represent the base of a pyramid.
All integers, other than the last (zero), are positive.

    4
	6
    0

* Output :
For each positive integer print the total number of blocks needed to build the pyramid with the specified base.
   
    10
    21

**/

#include <stdio.h>

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("%d\n", n * (n + 1) / 2);
    }
    
    return 0;
}