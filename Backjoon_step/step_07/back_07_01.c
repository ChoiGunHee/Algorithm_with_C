/**
* 2021. 02. 12
* Creater : Gunhee Choi
* Problem Number : 11654
* Title : 아스키 코드

* Problem :
알파벳 소문자, 대문자, 숫자 0-9중 하나가 주어졌을 때, 주어진 글자의 아스키 코드값을 출력하는 프로그램을 작성하시오.

* Input : 알파벳 소문자, 대문자, 숫자 0-9 중 하나가 첫째 줄에 주어진다.
	A

* Output : 입력으로 주어진 글자의 아스키 코드 값을 출력한다.
	65

**/

#include <stdio.h>

int main() {
	char input_string;
	scanf("%c", &input_string);
	printf("%d", input_string);
	return 0;
}