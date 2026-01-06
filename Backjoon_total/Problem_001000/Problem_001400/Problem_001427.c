/**
* 2026. 01. 06
* Creater : Gunhee Choi
* Problem Number : 1427
* Title : 소트인사이드

* Problem :
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

* Input :
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

    999998999

* Output :
상을 받는 커트라인을 출력하라.
   
    999999998

**/

#include <stdio.h>

int main(void) {
    char number[10];
    int temp;

    scanf("%s", number);

    for (int i = 0; number[i] != '\0'; i++) {
        for (int j = i + 1; number[j] != '\0'; j++) {
            if (number[i] < number[j]) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }

    printf("%s\n", number);

    return 0;
}