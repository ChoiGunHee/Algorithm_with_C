/**
* 2021. 05. 01
* Creater : Gunhee Choi
* Problem Number : 1550
* Title : 16진수

* Problem :
16진수 수를 입력받아서 10진수로 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 16진수 수가 주어진다. 이 수의 최대 길이는 6글자이다. 16진수 수는 0~9와 A~F로 이루어져 있고, A~F는 10~15를 뜻한다. 또, 이 수는 음이 아닌 정수이다.

	A
	
* Output :
첫째 줄에 입력으로 주어진 16진수 수를 10진수로 변환해 출력한다.

	10

**/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	char arr[10];
	int len;
	int result = 0;
	int t;
	int i;
	
	scanf("%s", arr);
	len = strlen(arr);
	
	for(i=0; i<len; i++) {
		if( arr[i] >= '0' && arr[i] <= '9') {
			t = arr[i] - '0';	
		} else {
			t = arr[i] - 'A' + 10;
		}
		
		result += t * pow(16, len-i-1);
	}
	
	printf("%d\n", result);
	
	return 0;	
}