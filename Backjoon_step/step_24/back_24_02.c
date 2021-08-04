/**
* 2021. 08. 04
* Creater : Gunhee Choi
* Problem Number : 2606
* Title : 바이러스

* Problem :
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

	7
	6
	1 2
	2 3
	1 5
	5 2
	5 6
	4 7
	
* Output :
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

	4
	
**/


#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1001
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];
int count;

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
	
	count++;
	for(w=0; w<g->n; w++)
		if(g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
	
}

int main(void) {
	int N, M;
	GraphType * g;
	int i;
	int temp_e1, temp_e2;
	
	g = (GraphType *) malloc(sizeof(GraphType));
	init(g);
	
	scanf("%d %d", &N, &M);
	
	for(i=0; i<=N; i++)
		insert_vertex(g, i);
	
	for(i=0; i<M; i++) {
		scanf("%d %d", &temp_e1, &temp_e2);
		insert_edge(g, temp_e1, temp_e2);
	}
	
	dfs_mat(g, 1);
	printf("%d\n", count-1);
	
	return 0;
}