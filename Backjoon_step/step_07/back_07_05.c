/**
* 2021. 02. 13
* Creater : Gunhee Choi
* Problem Number : 1157
* Title : 문자열 반복

* Problem :
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

* Input : 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다. 
	Mississipi
	zZa

* Output : 각 테스트 케이스에 대해 P를 출력한다.
	?
	Z

**/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000001
#define alphabet_count 26

int main() {
	char arr_string[MAX_LEN];
	int arr_count[alphabet_count];
	int arr_len;
	char alphabet_index;
	int max_value = 0;
	int max_index = 0;
	char result;
	int i;
	
	scanf("%s", arr_string);
	arr_len = strlen(arr_string);
	
	
	for(i=0; i<arr_len; i++) {
		alphabet_index = arr_string[i] - 'a';
		
		if(alphabet_index < 0)
			alphabet_index = arr_string[i] - 'A';
		
		arr_count[alphabet_index]++;
	}
	
	for(i=0; i<alphabet_count; i++) {
		if(arr_count[i] > max_value) {
			max_value = arr_count[i];
			max_index = i;
		}
	}
	
	result = max_index + 65;
	
	for(i=0; i<alphabet_count; i++) {
		if(max_value == arr_count[i] & max_index != i) {
			result = '?';
		}
	}
	
	printf("%c\n", result);
	
	return 0;
}