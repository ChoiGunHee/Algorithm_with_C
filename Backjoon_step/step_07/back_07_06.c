/**
* 2021. 02. 13
* Creater : Gunhee Choi
* Problem Number : 1152
* Title : 단어의 개수

* Problem :
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

* Input : 첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다. 
	The Curious Case of Benjamin Button

* Output : 첫째 줄에 단어의 개수를 출력한다.
	6

**/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000001

int main() {
	char arr_string[MAX_LEN];
	int arr_len;
	int count = 0;
	int i;
	
	scanf("%s", arr_string);
	arr_len = strlen(arr_string);
	
	for(i=0; i<arr_len; i++) {
		if(arr_string[i] == 32)
			count++;
	}
	
	printf("%d\n", count);
	printf("dd %d\n", ' ');
	return 0;
}