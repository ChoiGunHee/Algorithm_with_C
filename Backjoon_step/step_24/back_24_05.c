/**
* 2021. 08. 23
* Creater : Gunhee Choi
* Problem Number : 2178
* Title : 미로 탐색

* Problem :
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

* Input :
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

	4 6
	110110
	110110
	111111
	111101
	
* Output :
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

	9

**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10001
#define MAX_NUM 100

typedef struct element {
	int x;
	int y;
} element;

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

int N, M;
int map[MAX_NUM][MAX_NUM];
int check[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init_queue(QueueType * queue) {
	queue->rear = queue->front = 0;
}

int is_full(QueueType * queue) {
	return  ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

int is_empty(QueueType * queue) {
	return (queue->front == queue->rear);
}

int enqueue(QueueType * queue, element data) {
	if( is_full(queue) ) {
		printf("Queue is Full\n");
		return -1;
	}
	queue->rear = (queue->rear +1) % MAX_QUEUE_SIZE;
	//data input
	queue->data[queue->rear] = data;
	return 0;
}

element dequeue(QueueType * queue) {
	if(is_empty(queue)) printf("Queue is empty");
	queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
	return queue->data[queue->front];
}

void print_queue(QueueType * queue) {
	int i;
	
	printf("QUEUE(front=%d rear=%d) = ", queue->front, queue->rear);
	if( !is_empty(queue)) {
		i = queue->front;
		do {
			i = (i+1) % MAX_QUEUE_SIZE;
			printf("x: %d, y: %d | ", queue->data[i].x, queue->data[i].y);
			if(i == queue->rear) break;
		} while(i != queue->front);
	}
	printf("\n");
}

element make_struct(int x, int y) {
	element tmp;
	tmp.x = x;
	tmp.y = y;
	
	return tmp;
}

void bfs(int x, int y) {
	QueueType q;
	int cx, cy;
	int nx, ny;
	visited[x][y]=1;
	element tmp;
	int i;
	
	init_queue(&q);
	enqueue(&q, make_struct(x, y));
	
	while(!is_empty(&q)) {
		tmp=dequeue(&q);
		cx=tmp.x;
		cy=tmp.y;
		
		for(i=0; i<4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			
			if( nx>=0 && nx<N && ny>=0 && ny<M ) {
				if(map[nx][ny] && visited[nx][ny]==0) {
					check[nx][ny]=check[cx][cy]+1;
					visited[nx][ny]=1;
					enqueue(&q, make_struct(nx, ny));
				}
			}
		}//end of for i
	}//end of while
}

int main(void) {
	char tmp[101];
	int i, j;
	
	memset(map, 0, sizeof(map));
	scanf("%d %d", &N, &M);
	for(i=0; i<N; i++) {
		scanf("%s", tmp);
		for(j=0; j<M; j++) {
			if(tmp[j]=='1')
				map[i][j] = 1;
		}
	}
	
	bfs(0,0);
	printf("%d\n", check[N-1][M-1]+1);
	
	return 0;	
}