/**
* 2021. 04. 19
* Creater : Gunhee Choi
* Problem Number : 1427
* Title : 소트인사이드

* Problem :
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

* Input :
첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

	2143

* Output :
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

	4321

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX 11

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return 1;
    
    if (num1 > num2)
        return -1;
    
    return 0;
}

int main(void) {
	int N;
	int list[MAX];
	int i;
	
	scanf("%d", &N);
	for(i=0; i<MAX; i++)
		list[i] = -1;
	
	i = 0;
	while(N != 0) {
		list[i] = N%10;
		N = N/10;
		i++;
	}
	
	qsort(list, MAX, sizeof(int), compare);
	
	for(i=0; i<MAX; i++) {
		if(list[i] == -1) break;
		printf("%d", list[i]);
	}
		
	return 0;	
}