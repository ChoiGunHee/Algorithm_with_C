/**
* 2025. 11. 25
* Creater : Gunhee Choi
* Problem Number : 4101
* Title : 크냐?

* Problem :
두 양의 정수가 주어졌을 때, 첫 번째 수가 두 번째 수보다 큰지 구하는 프로그램을 작성하시오.

* Input :
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 두 정수가 주어진다. 두 수는 백만보다 작거나 같은 양의 정수이다.
입력의 마지막 줄에는 0이 두 개 주어진다.

    1 19
    4 4
    23 14
    0 0
	
* Output :
각 테스트 케이스마다, 첫 번째 수가 두 번째 수보다 크면 Yes를, 아니면 No를 한 줄에 하나씩 출력한다.

    No
    No
    Yes

**/

#include <stdio.h>

int main(void) {
    int a, b;

    while(1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        
        if (a > b) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}