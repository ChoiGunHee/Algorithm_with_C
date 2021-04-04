/**
* 2021. 04. 04
* Creater : Gunhee Choi
* Problem Number : 1085
* Title : 직사각형에서 탈출

* Problem :
한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 x, y, w, h가 주어진다.

	6 2 10 3

* Output : 첫째 줄에 문제의 정답을 출력한다.

	1

 * 제한 :
 	1 ≤ w, h ≤ 1,000
	1 ≤ x ≤ w-1
	1 ≤ y ≤ h-1
	x, y, w, h는 정수
**/

#include <stdio.h>

int escapeRec(int x, int y, int w, int h) {
	int result = 0;
	int temp;
	
	//(0,0)쪽으로 가까운지 먼저 계산, x와 y 비교
	result = x < y ? x : y;
	
	//(w,h)쪽으로 가까운지 계산, w와 h 비교
	temp = (w - x) < (h - y) ? (w - x) : (h - y); 
	
	//최종비교
	result = temp < result ? temp : result;
	
	return result;
}

int main(void) {
	int x, y, w, h;
	int result = 0;
	
	scanf("%d %d %d %d", &x, &y, &w, &h);
	result = escapeRec(x, y, w, h);
	printf("%d\n", result);
}




