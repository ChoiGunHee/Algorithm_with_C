/**
* 2021. 07. 25
* Creater : Gunhee Choi
* Problem Number : 2981
* Title : 검문

* Problem :
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 검문하는데 엄청나게 오랜 시간이 걸린다.

상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.

먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

* Input :
첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)

다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.

항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

	3
	6
	34
	38

* Output :
첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다.

	2 4

**/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

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
	long long arr_n[100];
	long long result[1000];
	int result_count = 0;
	long long gcd_n;
	int i;
	
	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%lld", &arr_n[i]);
	
	qsort(arr_n, N, sizeof(long long), compare);
	
	gcd_n = arr_n[1] - arr_n[0];
	for(i=2; i<N; i++) {
		gcd_n = gcd(gcd_n, arr_n[i]-arr_n[i-1]);
	}
	
	for(i=1; i*i<=gcd_n; i++) {
		if(gcd_n%i == 0) {
			result[result_count++] = i;
			result[result_count++] = gcd_n/i;
		}
		
		if(i*i == gcd_n)
			result[result_count++] = i*i;
	}
	
	qsort(result, result_count, sizeof(long long), compare);
	
	for(i=1; i<result_count; i++) {
		if(result[i] == result[i-1])
			continue;
		printf("%lld ", result[i]);
	}
	printf("\n");
	
	return 0;	
}