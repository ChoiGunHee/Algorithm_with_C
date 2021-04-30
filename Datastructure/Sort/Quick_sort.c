/* 2021. 04. 30
 * Creater : Gunhee Choi
 * This file is Quick Sort Simulation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right + 1;
	pivot = list[left];
	
	do {
		do
			low++;
		while(list[low] < pivot);
		do
			high--;
		while(list[high] > pivot);
		if(low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	
	SWAP(list[left], list[high], temp);
	return high;
}

void quik_sort(int list[], int left, int right) {
	int q;
	
	if (left < right) {
		q = partition(list, left, right);
		quik_sort(list, left, q-1);
		quik_sort(list, q + 1, right);
	}
}

int main(void) {
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	
	for(i=0; i<n; i++)
		list[i] = rand() % 100;
	
	quik_sort(list, 0, n-1);
	
	for(i=0; i<n; i++)
		printf("%d ", list[i]);
	
	printf("\n");
	
	return 0;
}