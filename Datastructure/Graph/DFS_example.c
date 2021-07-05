/* 2021. 07. 05
 * Creater : Gunhee Choi
 * This file is Depth First Search Simulation.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

//그래프 초기화
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

void dfs_mat(GraphType * g, int v) {
	int w;
	visited[v] = TRUE;
	
	printf("정점 %d -> ", v);
	for(w=0; w<g->n; w++)
		if(g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
}

int main(void) {
	GraphType * g;
	int i;
	
	g = (GraphType *) malloc(sizeof(GraphType));
	init(g);
	for(i=0; i<4; i++)
		insert_vertex(g, i);
	
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	
	dfs_mat(g, 0);
	printf("\n");
	
	free(g);
	
	return 0;
}