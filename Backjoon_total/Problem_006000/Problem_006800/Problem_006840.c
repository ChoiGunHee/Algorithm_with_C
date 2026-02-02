/**
* 2026. 02. 02
* Creater : Gunhee Choi
* Problem Number : 6840
* Title : Who is in the middle?

* Problem :
In the story Goldilocks and the Three Bears, each bear had a bowl of porridge to eat while sitting at his/her favourite chair.
What the story didn’t tell us is that Goldilocks moved the bowls around on the table, so the bowls were not at the right seats anymore.
The bowls can be sorted by weight with the lightest bowl being the Baby Bear’s bowl, the medium bowl being the Mama Bear’s bowl and the heaviest bowl being the Papa Bear’s bowl.
Write a program that reads in three weights and prints out the weight of Mama Bear’s bowl.
You may assume all weights are positive integers less than 100.

* Input :

    10
    5
    8

* Output :
   
    8

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        printf("%d\n", a);
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        printf("%d\n", b);
    } else {
        printf("%d\n", c);
    }
    
    return 0;
}