/**
* 2021. 02. 18
* Creater : Gunhee Choi
* Problem Number : 1316
* Title : 그룹 단어 체커

* Problem :
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
	3
	happy
	new
	year

	4
	aba
	abab
	abcabc
	a
	
* Output : 첫째 줄에 그룹 단어의 개수를 출력한다.
	3

	1
**/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 101

int main() {
	int problem_count;
	char arr[MAX_LEN];
	int arr_len;
	char alphabet[26];
	int word_result = 1;
	int count = 0;
	int i, j;
	
	scanf("%d", &problem_count);
	for(i=0; i<problem_count; i++) {
		scanf("%s", arr);
		arr_len = strlen(arr);
		
		//알파벳 초기화
		for(j=0; j<26; j++)
			alphabet[j] = 0;
		
		word_result = 1;
		
		//시작값
		alphabet[arr[0] - 'a'] = 1;
		
		for(j=1; j<arr_len; j++) {
			if(arr[j] != arr[j-1]) {
				
				if(alphabet[arr[j]-'a'] != 1) {
					alphabet[arr[j]-'a'] = 1;
				} else {
					word_result = 0;
					break;
				}
			}
		}//for j end
		
		if(word_result == 1)
			count++;
	}//for i end
	
	printf("%d\n", count);
	return 0;
}