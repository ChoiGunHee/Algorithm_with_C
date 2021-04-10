/**
* 2021. 04. 05
* Creater : Gunhee Choi
* Problem Number : 3009
* Title : 네 번째 점

* Problem :
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

* Input : 세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

	30 20
	10 10
	10 20

* Output : 직사각형의 네 번째 점의 좌표를 출력한다.

	30 10

**/
#include <stdio.h>

int main(void) {
	int x[4];
	int y[4];
	int i;
	
	for(i=0; i<3; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	if(x[0] == x[1]) {
		x[3] = x[2];
	} else {
		if(x[0] == x[2]) {
			x[3] = x[1];
		} else {
			x[3] = x[0];
		}
	}
	
	if(y[0] == y[1]) {
		y[3] = y[2];
	} else {
		if(y[0] == y[2]) {
			y[3] = y[1];
		} else {
			y[3] = y[0];
		}
	}
	
	printf("%d %d\n", x[3], y[3]);
	
	return 0;	
}