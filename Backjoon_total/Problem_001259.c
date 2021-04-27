/**
* 2021. 04. 27
* Creater : Gunhee Choi
* Problem Number : 1259
* Title : 팰린드롬수

* Problem :
어떤 단어를 뒤에서부터 읽어도 똑같다면 그 단어를 팰린드롬이라고 한다. 'radar', 'sees'는 팰린드롬이다.
수도 팰린드롬으로 취급할 수 있다. 수의 숫자들을 뒤에서부터 읽어도 같다면 그 수는 팰린드롬수다. 121, 12421 등은 팰린드롬수다. 123, 1231은 뒤에서부터 읽으면 다르므로 팰린드롬수가 아니다. 또한 10도 팰린드롬수가 아닌데, 앞에 무의미한 0이 올 수 있다면 010이 되어 팰린드롬수로 취급할 수도 있지만, 특별히 이번 문제에서는 무의미한 0이 앞에 올 수 없다고 하자.

* Input : 입력은 여러 개의 테스트 케이스로 이루어져 있으며, 각 줄마다 1 이상0 99999 이하의 정수가 주어진다. 입력의 마지막 줄에는 0이 주어지며, 이 줄은 문제에 포함되지 않는다.

	121
	1231
	12421
	0

* Output :
각 줄마다 주어진 수가 팰린드롬수면 'yes', 아니면 'no'를 출력한다.

	yes
	no
	yes

**/

#include <stdio.h>
#define MAX_LEN 5

int check_Palindrom(int n) {
	int arr[MAX_LEN] = {0, };
	int t = n;
	int count = 0;
	int result = 1;
	int i;
	
	while(n != 0) {
		arr[count++] = n%10;
		n /= 10;
	}
	
	for(i=0; i<count/2; i++) {
		if(arr[i] != arr[count-i-1]) {
			result = 0;
			break;
		}
	}
	
	return result;
}

int main(void) {
	int n = 9999;
	int result;
	
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		
		result = check_Palindrom(n);
		printf("%s\n", result == 1 ? "yes" : "no");
	}
	
	return 0;	
}