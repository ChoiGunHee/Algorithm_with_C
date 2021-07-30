/**
* 2021. 07. 30
* Creater : Gunhee Choi
* Problem Number : 1149
* Title : RGB거리

* Problem :
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

	1번 집의 색은 2번 집의 색과 같지 않아야 한다.
	N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
	i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

* Input :
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

	3
	26 40 83
	49 60 57
	13 89 99
	
* Output :
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

	96

**/

#include <stdio.h>
#define MAX_NUM 1001

long long cost[MAX_NUM][3];

int main(void) {
	int N;
	int i;
	int tmp_cost[3];
	int min;
	
	cost[0][0] = 0;	//R
	cost[0][1] = 0;	//G
	cost[0][2] = 0;	//B
	
	scanf("%d", &N);
	
	for(i=1; i<=N; i++) {
		scanf("%d %d %d", &tmp_cost[0], &tmp_cost[1], &tmp_cost[2]);
		cost[i][0] = tmp_cost[0] + (cost[i-1][1] < cost[i-1][2] ? cost[i-1][1] : cost[i-1][2]);
		cost[i][1] = tmp_cost[1] + (cost[i-1][0] < cost[i-1][2] ? cost[i-1][0] : cost[i-1][2]);
		cost[i][2] = tmp_cost[2] + (cost[i-1][1] < cost[i-1][0] ? cost[i-1][1] : cost[i-1][0]);
	}
	
	min = cost[N][1] < cost[N][2] ? cost[N][1] : cost[N][2];
	min = min < cost[N][0] ? min : cost[N][0];
	
	printf("%d\n", min);
	
	return 0;	
}