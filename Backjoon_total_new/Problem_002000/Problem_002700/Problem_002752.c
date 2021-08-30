/**
* 2021. 08. 27
* Creater : Gunhee Choi
* Problem Number : 2752
* Title : 세수정렬

* Problem :
동규는 세수를 하다가 정렬이 하고싶어졌다.

숫자 세 개를 생각한 뒤에, 이를 오름차순으로 정렬하고 싶어 졌다.

숫자 세 개가 주어졌을 때, 가장 작은 수, 그 다음 수, 가장 큰 수를 출력하는 프로그램을 작성하시오.

* Input :
숫자 세 개가 주어진다. 이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다. 이 숫자는 모두 다르다.

	3 1 2
	
* Output :
제일 작은 수, 그 다음 수, 제일 큰 수를 차례대로 출력한다.

	1 2 3

**/

#include <stdio.h>

int main(void) {
	int a=0, b=0, c=0;
	int tmp;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if(a>c) {
		tmp = a;
		a = c;
		c = tmp;
	}
	
	if(b>c) {
		tmp = b;
		b = c;
		c = tmp;
	} else {
		if(a>b) {
			tmp = a;
			a = b;
			b = tmp;
		}
	}
	
	printf("%d %d %d\n", a, b, c);
	
	return 0;	
}