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

int reverse(char * arr, const int len) {
	int i;
	char temp;
	
	for(i=0; i<len/2; i++) {
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

int main() {
	char ch_A[100] = {0, };
	char ch_B[100] = {0, };
	char result[100];
	
	int len_A, len_B;
	int max_len;
	int min_len;
	int i;
	
	scanf("%s %s", ch_A, ch_B);
	
	len_A = strlen(ch_A);
	len_B = strlen(ch_B);
	max_len = len_A > len_B ? len_A : len_B;
	min_len = len_A > len_B ? len_B : len_A;
	
	//reverse(ch_A, len_A);
	//reverse(ch_B, len_B);
	
	for(i=0; i<max_len; i++) {
		result[i] = ch_A[i] + ch_B[i] - '0';
	}
	result[max_len] = NULL;
	
	
	printf("%s\n", result);
	
	/*
	char ch_A[100] = {0, };
	char ch_B[100] = {0, };
	char result[200];
	char temp_arr[200];
	
	int len_A, len_B, len_max;
	int temp;
	int add_temp = 0;
	int count = 0;
	int i, j;
	
	scanf("%s %s", ch_A, ch_B);
	
	len_A = strlen(ch_A);
	len_B = strlen(ch_B);
	
	len_max = len_B > len_A ? len_B : len_A;
	
	for(i=len_max-1; i>0; i--) {
		if(add_temp == 1)
				temp += 1;
		
		if(ch_A[i] != 0 && ch_B[i] != 0) {	
			temp = ch_A[i] + ch_B[i] - '0' - '0';
		} else if(ch_A[i] != 0 || ch_B[i] != 0) {
			temp = ch_A[i] + ch_B[i]; - '0';
		} else {
			break;
		}
		
		if(temp >= 10) {
			temp -= 10;
			add_temp = 1;
		}
		
		result[count++] = temp;
	}
	
	for(i=count; i>0; i++) {
		printf("%d", result[i]);
	}
	printf("\n");
	*/
	return 0;
}