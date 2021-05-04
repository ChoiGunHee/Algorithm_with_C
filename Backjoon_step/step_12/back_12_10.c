/**
* 2021. 05. 02
* Creater : Gunhee Choi
* Problem Number : 18870
* Title : 좌표 압축

* Problem :
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

* Input :
첫째 줄에 N이 주어진다.
둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

	5
	2 4 -10 4 -9

* Output :
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

	2 3 0 3 1

* 제한 :
	1 ≤ N ≤ 1,000,000
	-109 ≤ Xi ≤ 109

**/

#include <stdio.h>
#include <stdlib.h>

int binary_search(int list[], int key, int n) {
	int mid;
	int high = n - 1;
	int low = 0;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if(key == list[mid]) {
			printf("%d ", mid);
			return mid;
		} else if(key > list[mid]) low = mid + 1;
		  else if(key < list[mid]) high = mid - 1;
	}
	
	return -1;
}

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(void) {
	int N;
	int * arr_origin;
	int * arr_sort;
	int * arr_result;
	int i;
	int count = 0;
	
	scanf("%d", &N);
	arr_origin = (int *) malloc(sizeof(int) * N);
	arr_sort = (int *) malloc(sizeof(int) * N);
	arr_result = (int *) malloc(sizeof(int) * N);
	
	for(i=0; i<N; i++) {
		scanf("%d", &arr_origin[i]);
		arr_sort[i] = arr_origin[i];
	}
	
	/*
	printf("origin\n");
	for(i=0; i<N; i++) printf("%d ", arr_origin[i]);
	printf("\n");
	*/
	
	qsort(arr_sort, N, sizeof(int), compare);
	
	/*
	printf("origin\n");
	for(i=0; i<N; i++) printf("%d ", arr_sort[i]);
	printf("\n");
	*/
	
	arr_result[count++] = arr_sort[count];
	for(i=1; i<N; i++) {
		if (arr_sort[i] == arr_sort[i - 1]) continue;
		else
			arr_result[count++] = arr_sort[i];
	}

	printf("origin\n");
	for(i=0; i<N; i++) printf("%d ", arr_result[i]);
	printf("\n");
	
	for(i=0; i<N; i++) {
		binary_search(arr_result, arr_origin[i], count);
	}

	printf("\n");
	
	return 0;	
}