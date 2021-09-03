/**
* 2021. 09. 03
* Creater : Gunhee Choi
* Problem Number : 10101
* Title : 삼각형 외우기

* Problem :
창영이는 삼각형의 종류를 잘 구분하지 못한다. 따라서 프로그램을 이용해 이를 외우려고 한다.

삼각형의 세 각을 입력받은 다음, 

	세 각의 크기가 모두 60이면, Equilateral
	세 각의 합이 180이고, 두 각이 같은 경우에는 Isosceles
	세 각의 합이 180이고, 같은 각이 없는 경우에는 Scalene
	세 각의 합이 180이 아닌 경우에는 Error

를 출력하는 프로그램을 작성하시오.

* Input :
총 3개의 줄에 걸쳐 삼각형의 각의 크기가 주어진다. 모든 정수는 0보다 크고, 180보다 작다.

	60
	70
	50

* Output :
문제의 설명에 따라 Equilateral, Isosceles, Scalene, Error 중 하나를 출력한다.

	Scalene
	
**/
#include <stdio.h>

int main(void) {
	int angle[3];
	int sum=0;
	int i;
	
	for(i=0; i<3; i++) {
		scanf("%d", &angle[i]);
		sum+=angle[i];
	}
	
	if(sum==180) {
		if(angle[0]==60 && angle[1]==60 && angle[2]==60)
			printf("Equilateral\n");
		else if(angle[0]!=angle[1] && angle[0]!=angle[2] && angle[1]!=angle[2])
			printf("Scalene\n");
		else
			printf("Isosceles\n");
	} else {
		printf("Error\n");
	}
	
	return 0;	
}