/**
* 2021. 07. 25
* Creater : Gunhee Choi
* Problem Number : 3036
* Title : 링

* Problem :
상근이는 창고에서 링 N개를 발견했다. 상근이는 각각의 링이 앞에 있는 링과 뒤에 있는 링과 접하도록 바닥에 내려놓았다. 

상근이는 첫 번째 링을 돌리기 시작했고, 나머지 링도 같이 돌아간다는 사실을 발견했다. 나머지 링은 첫 번째 링 보다 빠르게 돌아가기도 했고, 느리게 돌아가기도 했다. 이렇게 링을 돌리다 보니 첫 번째 링을 한 바퀴 돌리면, 나머지 링은 몇 바퀴 도는지 궁금해졌다.

링의 반지름이 주어진다. 이때, 첫 번째 링을 한 바퀴 돌리면, 나머지 링은 몇 바퀴 돌아가는지 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 링의 개수 N이 주어진다. (3 ≤ N ≤ 100)

다음 줄에는 링의 반지름이 상근이가 바닥에 놓은 순서대로 주어진다. 반지름은 1과 1000를 포함하는 사이의 자연수이다.

	3
	8 4 2

* Output :
출력은 총 N-1줄을 해야 한다. 첫 번째 링을 제외한 각각의 링에 대해서, 첫 번째 링을 한 바퀴 돌리면 그 링은 몇 바퀴 도는지 기약 분수 형태 A/B로 출력한다.

	2/1
	4/1

**/

#include <stdio.h>

int gcd(int a, int b)
{
    int temp;
	
	while(b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	
    return a;
}

int main(void) {
	int N;
	int f_ring;
	int tmp;
	int gcd_rings;
	int i;
	
	scanf("%d", &N);
	scanf("%d", &f_ring);
	for(i=1; i<N; i++) {
		scanf("%d", &tmp);
		
		gcd_rings = gcd(f_ring, tmp);
		printf("%d/%d\n", f_ring/gcd_rings, tmp/gcd_rings);
	}
	
	return 0;	
}