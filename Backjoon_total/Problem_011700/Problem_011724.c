/**
* 2021. 08. 14
* Creater : Gunhee Choi
* Problem Number : 11724
* Title : 집합

* Problem :
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

	6 5
	1 2
	2 5
	5 1
	3 4
	4 6

* Output :
첫째 줄에 연결 요소의 개수를 출력한다.

	2

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 2000
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType * g) {
	int r, c;
	
	g->n = 0;
	for(r=0; r<MAX_VERTICES; r++)
		for(c=0; c<MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

//정점 삽입 연산
void insert_vertex(GraphType * g, int v) {
	if( ((g->n) + 1) > MAX_VERTICES ) {
		printf("그래프 정점의 개수 초과\n");
		return;
	}
	g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType * g, int start, int end) {
	if(start >= g->n || end >= g->n) {
		printf("그래프 : 정점 번호 오류");
	}
	
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;	
}

int init_visited() {
	int i;
	
	for(i=0; i<MAX_VERTICES; i++)
		visited[i] = 0;
}

//Search
void dfs_mat(GraphType * g, int v) {
	int w;
	visited[v] = TRUE;
	
	//printf("%d ", v);
	for(w=0; w<g->n; w++)
		if(g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
}

int main(void) {
	int N, M;
	int u, v;
	GraphType * g;
	int count = 0;
	int i;
	
	g = (GraphType *) malloc(sizeof(GraphType));
	init(g);
	
	scanf("%d %d", &N, &M);
	
	for(i=0; i<=N; i++)
		insert_vertex(g, i);
	
	for(i=0; i<M; i++) {
		scanf("%d %d", &u, &v);
		insert_edge(g, u, v);
	}
	
	for(i=1; i<=N; i++) {
		if(!visited[i]) {
			dfs_mat(g, i);
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;	
}