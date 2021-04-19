/**
* 2021. 04. 19
* Creater : Gunhee Choi
* Problem Number : 2108
* Title : 수 정렬하기 3

* Problem :
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

	5
	1
	3
	8
	-2
	2

* Output :
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
둘째 줄에는 중앙값을 출력한다.
셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
넷째 줄에는 범위를 출력한다.

	2
	2
	1
	10

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
	int sum = 0;
	int counting[8001] = {0, };
	int max_count = 0;
	int * temp_list;
	int temp_count = 0;
	int second_min = 9999;
	
	int i;
	
	scanf("%d", &N);
	list = (int *) malloc(sizeof(int) * N);
	temp_list = (int *) malloc(sizeof(int) * N);
	for(i=0; i<N; i++)
		temp_list[i] = 9999;
	
	for(i=0; i<N; i++) {
		scanf("%d", &list[i]);
		sum += list[i];
		counting[list[i] + 4000]++;
	}
	
	qsort(list, N, sizeof(int), compare);
	
	//산술평균
	printf("%.0lf\n", ((double)sum) / (double)N);
	
	//중앙값
	printf("%d\n", list[N/2]);
	
	//최빈값
	for(i=0; i<8001; i++) {
		if(counting[i] > max_count) {
			max_count = counting[i];
		}
	}
	
	for(i=0; i<8001; i++) {
		if(max_count == counting[i]) {
			temp_list[temp_count] = i - 4000;
			temp_count++;
		}
	}
	
	if(temp_count == 1) {
		printf("%d\n", temp_list[0]);
	} else {
		qsort(temp_list, N, sizeof(int), compare);
		printf("%d\n", temp_list[1]);
	}
				 
	//범위
	printf("%d\n", list[N-1] - list[0]);
	

	return 0;	
}