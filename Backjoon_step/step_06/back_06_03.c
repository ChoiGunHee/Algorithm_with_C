/**
* 2021. 02. 11
* Creater : Gunhee Choi
* Problem Number : 1065
* Title : 한수

* Problem :
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

* Input : 첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.
	110

* Output : 첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
	99
**/

#include <stdio.h>
#include <stdlib.h>

//한수 검사
int hansoo(int n) {
	int result = 0;
	int origin_n = n;
	//100, 10, 1자리수
	int arr_n[3] = {0, };
	int interval1, interval2;
	int i;
	
	//자리수 추출
	for(i=2; i>=0; i--) {
		arr_n[i] = origin_n%10;
		origin_n = origin_n/10;
	}
	
	//1000이 최대값이고, 순차순열이아니므로 0반환
	if(origin_n != 0)
		return 0;
	
	//100자리수가 0이면, 10~99까지는 순차순열
	if(arr_n[0] == 0)
		return 1;
	
	//100자리수와 10자리수가 0이면, 한자리수는 모두 순차순열
	if(arr_n[0] == 0 && arr_n[1] == 0)
		return 1;
	
	interval1 = arr_n[1] - arr_n[0];
	interval2 = arr_n[2] - arr_n[1];
	
	if(interval1 == interval2)
		result = 1;

	return result;
}

int main() {
	int max_num;
	int count = 0;
	int i;
	
	scanf("%d", &max_num);
	
	for(i=1; i<=max_num; i++) {
		if(hansoo(i) == 1)
			count++;
	}
	
	printf("%d\n", count);
	
	return 0;
}