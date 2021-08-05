/**
* 2021. 08. 05
* Creater : Gunhee Choi
* Problem Number : 1927
* Title : 최소 힙

* Problem :
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

	1. 배열에 정수 x (x ≠ 0)를 넣는다.
	2. 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.

프로그램은 처음에 비어있는 배열에서 시작하게 된다.

* Input :
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.

	18
	1
	-1
	0
	0
	0
	1
	1
	-1
	-1
	2
	-2
	0
	0
	0
	0
	0
	0
	0

* Output :
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.

	-1
	1
	0
	-1
	-1
	1
	1
	-2
	2
	0

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100001

typedef struct {
	int heap[MAX_ELEMENT];
	int flag[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType * create() {
	return (HeapType * ) malloc(sizeof(HeapType));
}

void init(HeapType * h) {
	int i;
	
	h->heap_size = 0;
	for(i=0; i<MAX_ELEMENT; i++)
		h->flag[i] = 1;
}

void insert_min_heap(HeapType * h, int item) {
	int i;
	int flag = 1;
	
	i = ++(h->heap_size);
	
	if(item<0) {
		item = -item;
		flag = -1;
	}
	
	while( (i != 1) && (item < h->heap[i/2]) ) {
		h->heap[i] = h->heap[i/2];
		h->flag[i] = h->flag[i/2];
		i /= 2;
	}
	
	h->heap[i] = item;
	h->flag[i] = flag;
}

int delete_min_heap(HeapType * h) {
	int parent, child;
	int item, temp, flag, tmp_flag;
	int i;
	
	item = h->heap[1];
	flag = h->flag[1];
	
	temp = h->heap[(h->heap_size)--];
	tmp_flag = h->flag[(h->heap_size)+1];
	
	parent = 1;
	child = 2;
	
	while(child <= h->heap_size) {
		if( (child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
			child++;
		
		if(temp <= h->heap[child])
			break;
		
		h->heap[parent] = h->heap[child];
		h->flag[parent] = h->flag[child];
		parent = child;
		child *= 2;
	}
	
	h->heap[parent] = temp;
	h->flag[parent] = tmp_flag;
	/*
	printf("heap: ");
	for(i=1; i<10; i++) {
		printf("%d ", h->heap[i]);
	}
	printf("\nflag: ");
	for(i=1; i<10; i++) {
		printf("%d ", h->flag[i]);
	}
	printf("\n");
	*/
	return item * flag;
}

int main(void) {
	int N;
	int i, temp;
	int max;
	HeapType * heap;
	
	scanf("%d", &N);
	
	heap = create();
	init(heap);
	
	for(i=0; i<N; i++) {
		scanf("%d", &temp);
		if(temp == 0) {
			if(heap->heap_size == 0) printf("0\n");
			else printf("%d\n", delete_min_heap(heap));
		} else {
			insert_min_heap(heap, temp);
		}
	}
	
	return 0;
}