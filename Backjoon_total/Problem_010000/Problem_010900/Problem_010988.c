/**
* 2021. 08. 05
* Creater : Gunhee Choi
* Problem Number : 10988
* Title : 팰린드롬인지 확인하기

* Problem :
알파벳 소문자로만 이루어진 단어가 주어진다. 이때, 이 단어가 팰린드롬인지 아닌지 확인하는 프로그램을 작성하시오.

팰린드롬이란 앞으로 읽을 때와 거꾸로 읽을 때 똑같은 단어를 말한다. 

level, noon은 팰린드롬이고, baekjoon, online, judge는 팰린드롬이 아니다.

* Input :
첫째 줄에 단어가 주어진다. 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.

	level

* Output :
첫째 줄에 팰린드롬이면 1, 아니면 0을 출력한다.

	1

**/

#include <stdio.h>
#include <string.h>

int check_Palindrom(char * word, int len) {
	int count = len;
	int result = 1;
	int i;
	
	
	for(i=0; i<count/2; i++) {
		if(word[i] != word[count-i-1]) {
			result = 0;
			break;
		}
	}
	
	return result;
}

int main(void) {
	char word[101];
	int result;
	
	scanf("%s", word);
	result = check_Palindrom(word, strlen(word));
	printf("%s\n", result == 1 ? "1" : "0");
	
	return 0;	
}