/**
* 2021. 08. 23
* Creater : Gunhee Choi
* Problem Number : 7576
* Title : 토마토

* Problem :
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

* Input :
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

	6 4
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 1
	
* Output :
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

	8

**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1001
#define MAX_NUM 1001

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
QueueType q;
int map[MAX_NUM][MAX_NUM];
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

void bfs(QueueType * q) {
	int x, y;
	int nx, ny;
	element tmp;
	int i, j;
	
	while(!is_empty(q)) {
		tmp = dequeue(q);
		x = tmp.x;
		y = tmp.y;
		
		for(i=0; i<4; i++) {
			nx = x+dx[i];
			ny = y+dy[i];
			
			if(nx>=0 && nx<M && ny>=0 && ny<N && map[ny][nx]==0) {
				map[ny][nx] = map[y][x]+1;
				enqueue(q, make_struct(nx, ny));
			}
		}
	}
}

int main(void) {
	int result;
	int i, j;
	
	init_queue(&q);
	
	scanf("%d %d", &N, &M);
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j]==1) {
				enqueue(&q, make_struct(i, j));
			}
		}
	}
	
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	
	bfs(&q);
	
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			if(map[i][j]==0) {
				printf("-1\n");
				return 0;
			}
			
			if(result<map[i][j])
				result = map[i][j];
		}
	}
	
	printf("%d\n", result-1);
	
	return 0;	
}