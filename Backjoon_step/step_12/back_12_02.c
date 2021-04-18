/**
* 2021. 04. 18
* Creater : Gunhee Choi
* Problem Number : 2751
* Title : 수 정렬하기 2

* Problem :
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

* Input : 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

	5
	5
	2
	3
	4
	1

* Output : 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

	1
	2
	3
	4
	5

**/

#include <stdio.h>
#include <stdlib.h>

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
	int * list;
	int i;
	
	scanf("%d", &N);
	list = (int *) malloc(sizeof(int) * N);
	
	for(i=0; i<N; i++)
		scanf("%d", &list[i]);
	
	qsort(list, N, sizeof(int), compare);
	
	for(i=0; i<N; i++)
		printf("%d\n", list[i]);
	
	return 0;	
}