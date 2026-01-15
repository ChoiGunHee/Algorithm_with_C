/**
* 2026. 01. 16
* Creater : Gunhee Choi
* Problem Number : 14215
* Title : 세 막대

* Problem :
영선이는 길이가 a, b, c인 세 막대를 가지고 있고, 각 막대의 길이를 마음대로 줄일 수 있다.
영선이는 세 막대를 이용해서 아래 조건을 만족하는 삼각형을 만들려고 한다.
    각 막대의 길이는 양의 정수이다
    세 막대를 이용해서 넓이가 양수인 삼각형을 만들 수 있어야 한다.
    삼각형의 둘레를 최대로 해야 한다.
a, b, c가 주어졌을 때, 만들 수 있는 가장 큰 둘레를 구하는 프로그램을 작성하시오. 

* Input :
첫째 줄에 a, b, c (1 ≤ a, b, c ≤ 100)가 주어진다.

    41 64 16

* Output :
첫째 줄에 만들 수 있는 가장 큰 삼각형의 둘레를 출력한다.
   
    113

**/

#include <stdio.h>

int main(void) {
    int a, b, c;
    int max = 0;
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c) {
        max = a;
        if (b + c > max) {
            printf("%d\n", a + b + c);
        } else {
            printf("%d\n", 2 * (b + c) - 1);
        }
    } else if (b >= a && b >= c) {
        max = b;
        if (a + c > max) {
            printf("%d\n", a + b + c);
        } else {
            printf("%d\n", 2 * (a + c) - 1);
        }
    } else {
        max = c;
        if (a + b > max) {
            printf("%d\n", a + b + c);
        } else {
            printf("%d\n", 2 * (a + b) - 1);
        }
    }

    return 0;
}