/**
* 2021. 02. 21
* Creater : Gunhee Choi
* Problem Number : 1193
* Title : 분수찾기

* Problem :
무한히 큰 배열에 다음과 같이 분수들이 적혀있다.

1/1	1/2	1/3	1/4	1/5	…
2/1	2/2	2/3	2/4	…	…
3/1	3/2	3/3	…	…	…
4/1	4/2	…	…	…	…
5/1	…	…	…	…	…
…	…	…	…	…	…

이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.
	14

* Output :
	2/4

**/

#include <stdio.h>

int main() {
	int num;
	int line_sum = 1;
	int gap;
	int i = 2;
	int p, c;
	
	scanf("%d", &num);
	
	if(num == 1) {
		printf("1/1\n");
		return 0;
	}
	
	while(1) {
		if(line_sum >= num) {
			line_sum = line_sum - i + 1;
			i--;
			break;
		}
		
		line_sum += i;
		i++;
	}
	
	gap = num - line_sum;
	
	if(i%2 == 0) {
		c = gap;
		p = i + 1 - gap;
	} else {
		p = gap;
		c = i + 1 - gap;
	}
	
	printf("%d/%d\n", c, p);

	return 0;
}