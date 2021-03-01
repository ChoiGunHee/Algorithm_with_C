/**
* 2021. 03. 01
* Creater : Gunhee Choi
* Problem Number : 1002
* Title : 터렛

*** Backjoon_total/Problem_001/Problem_001002 와 동일한 문제이다.

* Problem :
조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.

(https://www.acmicpc.net/upload/201003/dfcmhrjj_142c3w76qg8_b.jpg)

이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.

한 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 자연수이다.

	3
	0 0 13 40 0 37
	0 0 3 0 7 4
	1 1 1 1 1 5

* Output : 각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.

	2
	1
	0

**/


//필요 함수
// double sqrt(double x)
// double pow(double x, double y)

//컴파일시
//gcc Problem_001002.c -lm

#include <stdio.h>
#include <math.h>

//(x1, y1)과 (x2, y2)의 거리계산
double distance(int x1, int y1, int x2, int y2) {
	return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2));	
}

//결과 계산
int location_result(int r1, int r2, double dis) {
	double r_sub = r1 > r2 ? r1-r2 : r2-r1;
	
	if(dis == 0 && r1 == r2)
		return -1;
	else if( ( dis < (r1+r2) ) && (r_sub < dis))
		return 2;
	else if( ( dis == (r1+r2) ) || ( dis == r_sub ))
		return 1;
	
	return 0;
}

int main() {
	int problem_num;
	int x1, y1, r1;
	int x2, y2, r2;
	int result;
	int i;
	
	scanf("%d", &problem_num);
	
	for(i=0; i<problem_num; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		result = location_result(r1, r2, distance(x1, y1, x2, y2));
		printf("%d\n", result);
	}
	
	return 0;
}