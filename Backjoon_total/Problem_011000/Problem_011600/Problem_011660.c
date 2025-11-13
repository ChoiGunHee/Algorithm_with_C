/**
* 2025. 11. 13
* Creater : Gunhee Choi
* Problem Number : 11660
* Title : 구간 합 구하기 5

* Problem :
N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.
예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.
    1 2 3 4
    2 3 4 5
    3 4 5 6
    4 5 6 7
여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.
표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.

* Input :
첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다.
다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다.
표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)

    4 3
    1 2 3 4
    2 3 4 5
    3 4 5 6
    4 5 6 7
    2 2 3 4
    3 4 3 4
    1 1 4 4
	
* Output :
총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.

    27
    6
    64

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M;
    int x1, y1, x2, y2;
    int sum;

    scanf("%d %d", &N, &M);

    int ** table = (int **)malloc( (N+1) * sizeof(int *));
    int **prefixSum = (int **)malloc((N + 1) * sizeof(int *));

    for (int i = 0; i <= N; i++) {
        table[i] = (int *)malloc((N + 1) * sizeof(int));
        prefixSum[i] = (int *)malloc((N + 1) * sizeof(int));
        for (int j = 0; j <= N; j++) {
            table[i][j] = 0;
            prefixSum[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &table[i][j]);
            prefixSum[i][j] = table[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int sum = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
        printf("%d\n", sum);
    }

    for (int i = 0; i <= N; i++) {
        free(table[i]);
        free(prefixSum[i]);
    }
    free(table);
    free(prefixSum);

    return 0;
}