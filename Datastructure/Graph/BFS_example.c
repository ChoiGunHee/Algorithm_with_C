/* 2021. 07. 18
 * Creater : Gunhee Choi
 * This file is Breath First Search Simulation.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50

typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void queue_init(QueueType * q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType * q) {
	return (q->front == q->rear);
}

int is_full(QueueType * q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType * q, element data) {
	if(is_full(q)) return -1;
	
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = data;
}

element dequeue(QueueType * q) {
	if(is_empty(q)) return -1;
	
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}



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

void bfs_mat(GraphType * g, int v) {
	int w;
	QueueType q;
	
	queue_init(&q);
	visited[v] = TRUE;
	
	printf("%d 방문 -> ", v);
	enqueue(&q, v);
	while(!is_empty(&q)) {
		v = dequeue(&q);
		for(w=0; w<g->n; w++) {
			if(g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d 방문 -> ", w);
				enqueue(&q, w);
			}
		}
	}
}

int main(void) {
	GraphType * g;
	int i;
	
	g = (GraphType *) malloc(sizeof(GraphType));
	init(g);
	for(i=0; i<6; i++)
		insert_vertex(g, i);
	
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);
	
	bfs_mat(g, 0);
	printf("\n");
	
	free(g);
	
	return 0;
}