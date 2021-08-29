/**
* 2021. 08. 29
* Creater : Gunhee Choi
* Problem Number : 2166
* Title : 다각형의 면적

* Problem :
2차원 평면상에 N(3 ≤ N ≤ 10,000)개의 점으로 이루어진 다각형이 있다. 이 다각형의 면적을 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N이 주어진다. 다음 N개의 줄에는 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다. 좌표값은 절댓값이 100,000을 넘지 않는 정수이다.

	4
	0 0
	0 10
	10 10
	10 0
	
* Output :
첫째 줄에 면적을 출력한다. 면적을 출력할 때에는 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력한다.

	100.0

**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 10000

typedef struct Point {
	double x;
	double y;
} Point;

double ccw(Point A, Point B, Point C) {
	return (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);
}

int main(void) {
	int N;
	Point * point_list;
	double result=0;
	int i;
	
	scanf("%d", &N);
	point_list = (Point *) malloc(sizeof(struct Point)*N);
	for(i=0; i<N; i++)
		scanf("%lf %lf", &point_list[i].x, &point_list[i].y);
	
	for(i=1; i<N-1; i++)
		result += ccw(point_list[0], point_list[i], point_list[i+1]);
	
	result = fabs(result);
	
	printf("%.1lf\n", result/2);
	
	return 0;	
}