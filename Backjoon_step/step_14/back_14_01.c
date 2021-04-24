/**
* 2021. 04. 24
* Creater : Gunhee Choi
* Problem Number : 15649
* Title : N과 M (1)

* Problem :
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

* Input : 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

	3 1

* Output :
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

	1
	2
	3

**/

#include <stdio.h>
#define MAX 10

int arr[MAX];
int visited[MAX];

void check(int n, int m, int depth) {
	int i;
	
	if(depth == m) {
		for(i=0; i<m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	
	for(i=1; i<=n; i++) {
		if(visited[i] == 0)
        {
            visited[i] = 1;
            arr[depth] = i;
            check(n, m, depth + 1);
            visited[i] = 0;
        }
	}
	
	return;
}

int main(void) {
	int N, M;
	
	scanf("%d %d", &N, &M);
	check(N, M, 0);
	
	return 0;	
}