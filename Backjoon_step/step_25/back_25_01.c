/**
* 2021. 09. 04
* Creater : Gunhee Choi
* Problem Number : 1753
* Title : 최단경로

* Problem :
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

* Input :
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

	5 6
	1
	5 1 1
	1 2 2
	1 3 3
	2 3 4
	2 4 5
	3 4 6

* Output :
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

	0
	2
	3
	7
	INF
	
**/

#include <stdio.h>
#include <stdlib.h>

#define INF 100000

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20001

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int vertices_n;
int weight[MAX_VERTICES][MAX_VERTICES];

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INF;
	minpos = -1;
	
	for(i=0; i<n; i++) {
		if(distance[i]<min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	
	return minpos;
}

void shortest_path(int start) {
	int i, u, w;
	
	for(i=0; i<vertices_n; i++) {
		distance[i] = weight[start][i];
		found[i] = FALSE;
	}
	
	found[start] = TRUE;
	distance[start] = 0;
	
	for(i=0; i<vertices_n; i++) {
		u=choose(distance, vertices_n, found);
		found[u]=TRUE;
		for(w=0; w<vertices_n; w++) {
			if(!found[w]) {
				if(distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
			}
		}
	}
}

void init_weight() {
	int i, j;
	
	for(i=0; i<MAX_VERTICES; i++)
		for(j=0; j<MAX_VERTICES; j++)
			weight[i][j] = INF;
	
}

int main(void) {
	int E;
	int u, v, w, k;
	int i;
		
	scanf("%d %d", &vertices_n, &E);
	scanf("%d", &k);
	
	init_weight(vertices_n);
	
	for(i=0; i<E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		weight[u-1][v-1] = w;
	}
	
	shortest_path(k-1);
	
	for(i=0; i<vertices_n; i++) {
		if(distance[i]==INF)
			printf("INF\n");
		else
			printf("%d\n", distance[i]);
	}

	return 0;	
}