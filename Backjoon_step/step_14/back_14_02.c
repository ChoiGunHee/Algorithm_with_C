/**
* 2021. 06. 17
* Creater : Gunhee Choi
* Problem Number : 15650
* Title : N과 M (2)
* Problem :
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.

	4 2

* Output :
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

	1 2
	1 3
	1 4
	2 3
	2 4
	3 4
	
**/

#include <stdio.h>
#define MAX_NUM 9

int N, M;
int arr[MAX_NUM];
int visited[MAX_NUM];

void dfs(int idx, int count) {
	int i;
	
	if(count == M) {
		for(i=0; i<M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	
	for(i=idx; i<=N; i++) {
		if(!visited[i]) {
			visited[i] = 1;
			arr[count] = i;
			dfs(i+1, count+1);
			visited[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	
	dfs(1,0);
	
	return 0;	
}