#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_result(int result) {
    if(result%3==0 && result%5==0)
        printf("FizzBuzz\n");
    else if(result%3==0)
        printf("Fizz\n");
    else if(result%5==0)
        printf("Buzz\n");
    else
        printf("%d\n", result);
}

int main(void) {
    char s1[9], s2[9], s3[9];
    int result;
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);

    if(atoi(s1)!=0) {
        result = atoi(s1) + 3;
    } else if(atoi(s2)!=0) {
        result = atoi(s2) + 2;
    } else {
        result = atoi(s3) + 1;
    }

    print_result(result);

    return 0;
}
