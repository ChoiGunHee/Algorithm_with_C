/**
* 2021. 08. 05
* Creater : Gunhee Choi
* Problem Number : 1655
* Title : 가운데를 말해요

* Problem :
수빈이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.

예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에는 수빈이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다. 그 다음 N줄에 걸쳐서 수빈이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

	7
	1
	5
	2
	10
	-99
	7
	5

* Output :
한 줄에 하나씩 N줄에 걸쳐 수빈이의 동생이 말해야하는 수를 순서대로 출력한다.

	1
	1
	2
	2
	2
	2
	5

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100001

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType * create() {
	return (HeapType * ) malloc(sizeof(HeapType));
}

void init(HeapType * h) {
	int i;
	
	h->heap_size = 0;
	for(i=1; i<MAX_ELEMENT; i++)
		h->heap[i] = -MAX_ELEMENT;
}

void insert_min_heap(HeapType * h, int item) {
	int i;
	i = ++(h->heap_size);

	while( (i != 1) && (item < h->heap[i/2]) ) {
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}

int delete_min_heap(HeapType * h) {
	int parent, child;
	int item, temp;
	
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	
	while(child <= h->heap_size) {
		if( (child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
			child++;
		
		if(temp <= h->heap[child]) break;
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	
	h->heap[parent] = temp;
	return item;
}

void insert_max_heap(HeapType * h, int item) {
	int i;
	i = ++(h->heap_size);

	while( (i != 1) && (item > h->heap[i/2]) ) {
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}

int delete_max_heap(HeapType * h) {
	int parent, child;
	int item, temp;
	
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	
	while(child <= h->heap_size) {
		if( (child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
			child++;
		
		if(temp >= h->heap[child]) break;
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	
	h->heap[parent] = temp;
	return item;
}

int peek_heap(HeapType * h) {
	return h->heap[1];
}

int main(void) {
	int N;
	int i, temp;
	int tmp_max, tmp_min;
	HeapType * max_heap;
	HeapType * min_heap;
	
	scanf("%d", &N);
	
	max_heap = create();
	min_heap = create();
	
	init(max_heap);
	init(min_heap);
	
	for(i=0; i<N; i++) {
		scanf("%d", &temp);
		
		if(max_heap->heap_size == 0)
			insert_max_heap(max_heap, temp);
		
		if(max_heap->heap_size > min_heap->heap_size)
			insert_min_heap(max_heap, temp);
		else
			insert_max_heap(min_heap, temp);
		
		if(peek_heap(max_heap) >= peek_heap(min_heap)) {
			tmp_max = peek_heap(max_heap);
			tmp_min = peek_heap(min_heap);
			
			delete_max_heap(max_heap);
			delete_max_heap(min_heap);
			
			insert_max_heap(max_heap, tmp_min);
			insert_min_heap(min_heap, tmp_max);
		}

		printf("%d\n", peek_heap(max_heap));
	}
	
	return 0;
}