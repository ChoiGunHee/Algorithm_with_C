/**
* 2021. 08. 29
* Creater : Gunhee Choi
* Problem Number : 2166
* Title : CCW

* Problem :
2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 P1의 (x1, y1), 둘째 줄에 P2의 (x2, y2), 셋째 줄에 P3의 (x3, y3)가 주어진다. (-10,000 ≤ x1, y1, x2, y2, x3, y3 ≤ 10,000) 모든 좌표는 정수이다. P1, P2, P3의 좌표는 서로 다르다.

	1 1
	5 5
	7 3
	
* Output :
P1, P2, P3를 순서대로 이은 선분이 반시계 방향을 나타내면 1, 시계 방향이면 -1, 일직선이면 0을 출력한다.

	-1

**/

#include <stdio.h>

typedef struct Point {
	int x;
	int y;
} Point;

int ccw(Point A, Point B, Point C) {
	return (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);
}

int main(void) {
	Point point_list[3];
	int result;
	int i;
	
	for(i=0; i<3; i++)
		scanf("%d %d", &point_list[i].x, &point_list[i].y);
	
	result = ccw(point_list[0], point_list[1], point_list[2]);
	
	if(result==0)
		printf("0\n");
	else
		printf("%d\n", result>0 ? 1 : -1);
	
	return 0;	
}