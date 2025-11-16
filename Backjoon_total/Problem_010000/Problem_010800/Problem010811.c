/**
* 2025. 11. 16
* Creater : Gunhee Choi
* Problem Number : 10811
* Title : 바구니 뒤집기

* Problem :
도현이는 바구니를 총 N개 가지고 있고, 각각의 바구니에는 1번부터 N번까지 번호가 순서대로 적혀져 있다. 바구니는 일렬로 놓여져 있고, 가장 왼쪽 바구니를 1번째 바구니, 그 다음 바구니를 2번째 바구니, ..., 가장 오른쪽 바구니를 N번째 바구니라고 부른다. 
도현이는 앞으로 M번 바구니의 순서를 역순으로 만들려고 한다. 도현이는 한 번 순서를 역순으로 바꿀 때, 순서를 역순으로 만들 범위를 정하고, 그 범위에 들어있는 바구니의 순서를 역순으로 만든다.
바구니의 순서를 어떻게 바꿀지 주어졌을 때, M번 바구니의 순서를 역순으로 만든 다음, 바구니에 적혀있는 번호를 가장 왼쪽 바구니부터 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N (1 ≤ N ≤ 100)과 M (1 ≤ M ≤ 100)이 주어진다.
둘째 줄부터 M개의 줄에는 바구니의 순서를 역순으로 만드는 방법이 주어진다. 방법은 i j로 나타내고, 왼쪽으로부터 i번째 바구니부터 j번째 바구니의 순서를 역순으로 만든다는 뜻이다. (1 ≤ i ≤ j ≤ N)
도현이는 입력으로 주어진 순서대로 바구니의 순서를 바꾼다.

    5 4
    1 2
    3 4
    1 4
    2 2
	
* Output :
모든 순서를 바꾼 다음에, 가장 왼쪽에 있는 바구니부터 바구니에 적혀있는 순서를 공백으로 구분해 출력한다.

    3 1 4 2 5

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M;
    int a, b, temp;
    scanf("%d %d", &N, &M);

    int * baskets = (int *)malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        baskets[i] = i;
    }

    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        for(int j=0; j< (b - a + 1)/2; j++) {
            temp = baskets[a + j];
            baskets[a + j] = baskets[b - j];
            baskets[b - j] = temp;
        }
    }

    for (int i=1; i<=N; i++)
        printf("%d ", baskets[i]);
    
    free(baskets);
    
    return 0;
}