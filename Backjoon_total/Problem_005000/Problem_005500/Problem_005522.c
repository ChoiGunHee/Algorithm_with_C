/**
* 2025. 11. 26
* Creater : Gunhee Choi
* Problem Number : 5522
* Title : 카드 게임

* Problem :
JOI군은 카드 게임을 하고 있다. 이 카드 게임은 5회의 게임으로 진행되며, 그 총점으로 승부를 하는 게임이다.
JOI군의 각 게임의 득점을 나타내는 정수가 주어졌을 때, JOI군의 총점을 구하는 프로그램을 작성하라.

* Input :
표준 입력에서 다음과 같은 데이터를 읽어온다.
i 번째 줄(1 ≤ i ≤ 5)에는 정수 Ai가 적혀있다. 이것은 i번째 게임에서의 JOI군의 점수를 나타낸다.

    1
    2
    3
    4
    5
	
* Output :
표준 출력에 JOI군의 총점을 한 줄로 출력하라.

    15

**/

#include <stdio.h>

int main(void) {
    int A;
    int total = 0;
    for(int i=0; i<5; i++) {
        scanf("%d", &A);
        total += A;
    }
    
    printf("%d\n", total);
    return 0;
}