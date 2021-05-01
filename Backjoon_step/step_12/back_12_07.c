/**
* 2021. 05. 01
* Creater : Gunhee Choi
* Problem Number : 11651
* Title : 좌표 정렬하기2

* Problem :
2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

	5
	0 4
	1 2
	1 -1
	2 2
	3 3

* Output :
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

	1 -1
	1 2
	2 2
	3 3
	0 4

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct point {
	int x;
	int y;
} Point;

int compare(const void * a, const void * b)
{
    struct point * point1 = (struct point *) a;
    struct point * point2 = (struct point *) b;

    if (point1->y > point2->y) return 1;
	else if(point1->y < point2->y) return -1;
	else {
		if(point1->x > point2->x) return 1;
		else if(point1->x < point2->x) return -1;
		else return 0;
	}
	
    return 0;
}

int main(void) {
	int N;
	struct point list[MAX];
	int i;
	
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}
	
	qsort(list, N, sizeof(Point), compare);
	
	for(i=0; i<N; i++) {
		printf("%d %d\n", list[i].x, list[i].y);
	}
	
	return 0;	
}