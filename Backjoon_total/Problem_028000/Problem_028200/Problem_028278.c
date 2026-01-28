/**
* 2026. 01. 28
* Creater : Gunhee Choi
* Problem Number : 28278
* Title : 스택 2

* Problem :
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
3: 스택에 들어있는 정수의 개수를 출력한다.
4: 스택이 비어있으면 1, 아니면 0을 출력한다.
5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.

* Input :
첫째 줄에 명령의 수 N이 주어진다. (1 ≤ N ≤ 1,000,000)
둘째 줄부터 N개 줄에 명령이 하나씩 주어진다.
출력을 요구하는 명령은 하나 이상 주어진다.

    9
    4
    1 3
    1 5
    3
    2
    5
    2
    2
    5

* Output :
출력을 요구하는 명령이 주어질 때마다 명령의 결과를 한 줄에 하나씩 출력한다.
   
    1
    2
    5
    3
    3
    -1
    -1

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    int stack[1000000];
    int top = -1;
    int command;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &command);

        if (command == 1) {
            int value;
            scanf("%d", &value);
            stack[++top] = value;
        }
        else if (command == 2) {
            if (top == -1)
                printf("-1\n");
            else
                printf("%d\n", stack[top--]);
        }
        else if (command == 3) {
            printf("%d\n", top + 1);
        }
        else if (command == 4) {
            if (top == -1)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (command == 5) {
            if (top == -1)
                printf("-1\n");
            else
                printf("%d\n", stack[top]);
        }
    }

    return 0;
}