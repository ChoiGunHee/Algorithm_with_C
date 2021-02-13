/**
* 2021. 02. 13
* Creater : Gunhee Choi
* Problem Number : 2675
* Title : 문자열 반복

* Problem :
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다. S에는 QR Code "alphanumeric" 문자만 들어있다.

QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.

* Input : 첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 각 테스트 케이스는 반복 횟수 R(1 ≤ R ≤ 8), 문자열 S가 공백으로 구분되어 주어진다. S의 길이는 적어도 1이며, 20글자를 넘지 않는다. 
	2
	3 ABC
	5 /HTP

* Output : 각 테스트 케이스에 대해 P를 출력한다.
	AAABBBCCC
	/////HHHHHTTTTTPPPPP

**/

#include <stdio.h>
#include <string.h>

int main() {
	int num;
	char arr[100];
	char result[300];
	int iter_num;
	int i, j, m;
	
	scanf("%d", &num);
	
	for(i=0; i<num; i++) {
		scanf("%d %s", &iter_num, arr);
	
		for(j=0; j<strlen(arr); j++)  {
			for(m=0; m<iter_num; m++) {
				result[j*iter_num + m] = arr[j];
			}
		}
		
		result[strlen(arr)*iter_num] = '\0';
		printf("%s\n", result);
	}
	
	return 0;
}