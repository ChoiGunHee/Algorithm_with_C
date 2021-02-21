/**
* 2021. 02. 20
* Creater : Gunhee Choi
* Problem Number : 2869
* Title : 그룹 단어 체커

* Problem :
땅 위에 달팽이가 있다. 이 달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다.

달팽이는 낮에 A미터 올라갈 수 있다. 하지만, 밤에 잠을 자는 동안 B미터 미끄러진다. 또, 정상에 올라간 후에는 미끄러지지 않는다.

달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 세 정수 A, B, V가 공백으로 구분되어서 주어진다. (1 ≤ B < A ≤ V ≤ 1,000,000,000)
	2 1 5
	
* Output : 첫째 줄에 달팽이가 나무 막대를 모두 올라가는데 며칠이 걸리는지 출력한다.
	4
**/

#include <stdio.h>

int main() {
	int A, B, V;
	int result;
	
	scanf("%d %d %d", &A, &B, &V);
	
	if(A == V) {
		printf("1\n");
		return 0;
	}
	
	result = (V-A)/(A-B) + 1;
	if( (V-A)%(A-B) != 0)
		result += 1;
	
	printf("%d\n", result);
	return 0;
}