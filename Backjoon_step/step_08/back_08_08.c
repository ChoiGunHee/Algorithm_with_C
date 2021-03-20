/**
* 2021. 02. 27
* Creater : Gunhee Choi
* Problem Number : 10757
* Title : 큰 수 A+B

* Problem :
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)
	9223372036854775807 9223372036854775808

* Output : 첫째 줄에 A+B를 출력한다.
	18446744073709551615

**/

#include <stdio.h>
#include <string.h>

void reverse(char * arr, const int len) {
	int i;
	char temp;
	
	for(i=0; i<len/2; i++) {
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

int main() {
	char ch_A[10001] = {0, };
	char ch_B[10001] = {0, };
	char result[10002] = {0, };
	
	int len_A, len_B;
	int max_len;
	int i;
	int value;
	int up = 0;

	scanf("%s %s", ch_A, ch_B);
	
	len_A = strlen(ch_A);
	len_B = strlen(ch_B);
	max_len = len_A > len_B ? len_A : len_B;
	
	reverse(ch_A, len_A);
	reverse(ch_B, len_B);
	
	for(i=0; i<=max_len; i++) {
		
		value = 0;
		
		if( ch_A[i] != 0 ) {
			value += ch_A[i] - '0';
		}
		
		if( ch_B[i] != 0 ) {
			value += ch_B[i] - '0';
		}
		
		value += up;
		
		if( value >= 10 ) {
			value -= 10;
			up = 1;
		} else {
			up = 0;
		}
		
		result[i] = value + '0';
	}
	
	if(result[max_len] == '0')
		result[max_len] = 0;
	
	reverse(result, strlen(result));
	
	printf("%s\n", result);
	return 0;
}