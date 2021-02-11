/**
* 2021. 02. 11
* Creater : Gunhee Choi
* Problem Number : 4673
* Title : 셀프 넘버

* Problem :
셀프 넘버는 1949년 인도 수학자 D.R. Kaprekar가 이름 붙였다. 양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수라고 정의하자. 예를 들어, d(75) = 75+7+5 = 87이다.

양의 정수 n이 주어졌을 때, 이 수를 시작해서 n, d(n), d(d(n)), d(d(d(n))), ...과 같은 무한 수열을 만들 수 있다. 

예를 들어, 33으로 시작한다면 다음 수는 33 + 3 + 3 = 39이고, 그 다음 수는 39 + 3 + 9 = 51, 다음 수는 51 + 5 + 1 = 57이다. 이런식으로 다음과 같은 수열을 만들 수 있다.

33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...

n을 d(n)의 생성자라고 한다. 위의 수열에서 33은 39의 생성자이고, 39는 51의 생성자, 51은 57의 생성자이다. 생성자가 한 개보다 많은 경우도 있다. 예를 들어, 101은 생성자가 2개(91과 100) 있다. 

생성자가 없는 숫자를 셀프 넘버라고 한다. 100보다 작은 셀프 넘버는 총 13개가 있다. 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97

10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

* Input :
* Output : 10,000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 증가하는 순서로 출력한다.

	1
	3
	5
	7
	9
	20
	31
	42
	53
	64
	|
	|       <-- a lot more numbers
	|
	9903
	9914
	9925
	9927
	9938
	9949
	9960
	9971
	9982
	9993

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 10001

//셀프넘버 정의
int d(int n) {
	int origin_n = n;
	int result = n;
	int count = 0;
	
	while(1) {
		if(origin_n <= 0)
			break;
		
		result += origin_n%10;
		origin_n = origin_n/10;	
	}
	
	return result;
}

int main() {
	int i, result;
	int arr_result[MAX_COUNT] = {0, };
	
	//최대값까지 d(n) 반복
	//생성자가 있는것을 찾아낸다
	//만약 결과값이 최대값보다 크다면 그냥 넘어간다.
	for(i=1; i<MAX_COUNT; i++) {
		result = d(i);
		if(result > MAX_COUNT)
			continue;
		
		//생성자 있는 것을 체크
		arr_result[result] = 1;
	}
	
	//출력
	for(i=1; i<MAX_COUNT; i++) {
		if(arr_result[i] == 0)
			printf("%d\n", i);
	}
	
	return 0;
}