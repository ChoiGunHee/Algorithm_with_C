/**
* 2021. 08. 17
* Creater : Gunhee Choi
* Problem Number : 10926
* Title : ??!

* Problem :
준하는 사이트에 회원가입을 하다가 joonas라는 아이디가 이미 존재하는 것을 보고 놀랐다. 준하는 놀람을 ??!로 표현한다. 준하가 가입하려고 하는 사이트에 이미 존재하는 아이디가 주어졌을 때, 놀람을 표현하는 프로그램을 작성하시오.

* Input :
첫째 줄에 준하가 가입하려고 하는 사이트에 이미 존재하는 아이디가 주어진다. 아이디는 알파벳 소문자로만 이루어져 있으며, 길이는 50자를 넘지 않는다.

	joonas

* Output :
첫째 줄에 준하의 놀람을 출력한다. 놀람은 아이디 뒤에 ??!를 붙여서 나타낸다.

	joonas??!

**/

#include <stdio.h>

int main(void) {
	char str[100];
	
	scanf("%s", str);
	printf("%s", str);
	printf("\?\?!\n");
	
	return 0;	
}