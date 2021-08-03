/**
* 2021. 07. 31
* Creater : Gunhee Choi
* Problem Number : 1145
* Title : 적어도 대부분의 배수

* Problem :
다섯 개의 자연수가 있다. 이 수의 적어도 대부분의 배수는 위의 수 중 적어도 세 개로 나누어 지는 가장 작은 자연수이다.

서로 다른 다섯 개의 자연수가 주어질 때, 적어도 대부분의 배수를 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 다섯 개의 자연수가 주어진다. 100보다 작거나 같은 자연수이고, 서로 다른 수이다.

30 42 70 35 90

* Output :
첫째 줄에 적어도 대부분의 배수를 출력한다.

	210

**/

#include <stdio.h>
#define MAX_NUM 100*100*100+1

int main(void) {
	int num[5];
	int min = 100*100*100+100;
	int count;
	int i, j;
	
	for(i=0; i<5; i++) {
		scanf("%d", &num[i]);
		if(min > num[i])
			min = num[i];
	}
		
	for(i=min; i<MAX_NUM; i++) {
		count = 0;
		for(j=0; j<5; j++)
			if(i%num[j]==0)
				count++;
		
		if(count>=3)
			break;
	}
	
	printf("%d\n", i);
	
	return 0;	
}