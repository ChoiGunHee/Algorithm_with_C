/**
* 2021. 08. 10
* Creater : Gunhee Choi
* Problem Number : 1931
* Title : 회의실 배정

* Problem :
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

* Input :
첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

	11
	1 4
	3 5
	0 6
	5 7
	3 8
	5 9
	6 10
	8 11
	8 12
	2 13
	12 14

* Output :
첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.

	4

**/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100001

typedef struct Time {
	int start;
	int end;
} Time;


int compare(const void * a, const void * b) {
	const Time * t1;
	const Time * t2;
	
	t1 = (const Time*)a;
	t2 = (const Time*)b;

	if (t1->end != t2->end) {
		if (t1->end < t2->end)
			return -1;
		else if (t1->end > t2->end)
			return 1;
		else
			return 0;
	}
	else {
		if (t1->start < t2->start)
			return -1;
		else if (t1->start > t2->start)
			return 1;
		else
			return 0;
	}
}

int main(void) {
	int N;
	Time time[MAX_NUM];
	int cnt = 0;
	int last_time = 0;
	int i;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++)
		scanf("%d %d", &time[i].start, &time[i].end);
	
	qsort(time, N, sizeof(Time), compare);
	
	for (i=0; i<N; i++) {
		if (time[i].start>=last_time) {
			cnt++;
			last_time = time[i].end;
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;	
}