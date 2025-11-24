/**
* 2025. 11. 24
* Creater : Gunhee Choi
* Problem Number : 27323
* Title : 직사각형

* Problem :
정수 A, B 가 주어진다. 세로 길이가 A cm, 가로 길이가 B cm 인 아래와 같은 직사각형의 넓이를 cm2 단위로 구하시오.

* Input :
표준 입력에 다음과 같은 형태로 입력이 주어진다.

    2
    3
	
* Output :
세로 길이가 A cm, 가로 길이가 B cm인 직사각형의 넓이를 cm2 단위로 구하고, 단위 (cm2)를 생략하여 출력한다.

    6

**/

#include <stdio.h>

int main(void) {
    int A, B;
    scanf("%d %d", &A, &B);

    printf("%d\n", A*B);

    return 0;
}