/**
* 2021. 08. 15
* Creater : Gunhee Choi
* Problem Number : 17626
* Title : Four Squares

* Problem :
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

	5 3
	5 4 3 2 1
	1 3
	2 4
	5 5

* Output :
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.

	12
	9
	1

* 제한 :
	1 ≤ N ≤ 100,000
	1 ≤ M ≤ 100,000
	1 ≤ i ≤ j ≤ N

**/

#include <stdio.h>

int sum[100001];

int main(void) {
	int N, M;
	int i, j;
	int tmp;
	
	scanf("%d %d", &N, &M);
	for(i=1; i<=N; i++) {
		scanf("%d", &tmp);
		sum[i] = sum[i-1] + tmp;
	}
	
	while(M--) {
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j]-sum[i-1]);
	}
	
	return 0;	
}