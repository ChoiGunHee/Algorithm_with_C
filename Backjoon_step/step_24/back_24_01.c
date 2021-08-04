/**
* 2021. 08. 04
* Creater : Gunhee Choi
* Problem Number : 1260
* Title : DFS와 BFS

* Problem :
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

* Input :
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

	4 5 1
	1 2
	1 3
	1 4
	2 4
	3 4
	
* Output :
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

	1 2 4 3
	1 2 3 4
	
**/


#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1001
#define MAX_QUEUE_SIZE 10001
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

//Queue
typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

void queue_init(QueueType * q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType * q) {
	return (q->front == q->rear);
}

int is_full(QueueType * q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int enqueue(QueueType * q, int data) {
	if(is_full(q)) return -1;
	
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = data;
}

int dequeue(QueueType * q) {
	if(is_empty(q)) return -1;
	
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

//Search
void dfs_mat(GraphType * g, int v) {
	int w;
	visited[v] = TRUE;
	
	printf("%d ", v);
	for(w=0; w<g->n; w++)
		if(g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
}

void bfs_mat(GraphType * g, int v) {
	int w;
	QueueType q;
	
	queue_init(&q);
	visited[v] = TRUE;
	
	printf("%d ", v);
	enqueue(&q, v);
	while(!is_empty(&q)) {
		v = dequeue(&q);
		for(w=0; w<g->n; w++) {
			if(g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d ", w);
				enqueue(&q, w);
			}
		}
	}
}

int main(void) {
	int N, M, V;
	GraphType * g;
	int i;
	int temp_e1, temp_e2;
	
	g = (GraphType *) malloc(sizeof(GraphType));
	init(g);
	
	scanf("%d %d %d", &N, &M, &V);
	
	for(i=0; i<=N; i++)
		insert_vertex(g, i);
	
	for(i=0; i<M; i++) {
		scanf("%d %d", &temp_e1, &temp_e2);
		insert_edge(g, temp_e1, temp_e2);
	}
	
	dfs_mat(g, V);
	printf("\n");
	init_visited();
	bfs_mat(g, V);
	printf("\n");
	
	return 0;
}