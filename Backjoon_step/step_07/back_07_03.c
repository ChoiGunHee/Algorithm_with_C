/**
* 2021. 02. 12
* Creater : Gunhee Choi
* Problem Number : 10809
* Title : 알파벳 찾기

* Problem :
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
	baekjoon

* Output : 각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치, ... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.

만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.
	1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

**/

#include <stdio.h>
#include <string.h>

int main() {
	char arr[101];
	int results[26];
	int arr_count;
	int i, i_char;
	
	scanf("%s", arr);
	arr_count = strlen(arr);
	
	//init
	for(i=0; i<26; i++)
		results[i] = -1;
	
	for(i=0; i<arr_count; i++) {
		i_char = arr[i] - 'a';
		
		if(results[i_char] == -1)
			results[i_char] = i;
	}
	
	//print
	for(i=0; i<26; i++) {
		printf("%d ", results[i]);	
	}
	
	printf("\n");
	
	return 0;
}