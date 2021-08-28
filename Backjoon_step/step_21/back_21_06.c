/**
* 2021. 08. 28
* Creater : Gunhee Choi
* Problem Number : 1300
* Title : K번째 수

* Problem :
세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다.

* Input :
첫째 줄에 배열의 크기 N이 주어진다. N은 105보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(109, N2)보다 작거나 같은 자연수이다.

	3
	7
	
* Output :
B[k]를 출력한다.

	6

**/

#include <stdio.h>
#define MIN(x,y) ( (x)<(y)?(x):(y) )

int main(void) {
	int N, k;
	int low, high, mid;
	int tmp_cnt;
	int result;
	int i;
	
	scanf("%d", &N);
	scanf("%d", &k);
	
	low=1;
	high=k;
	while(1) {
		if(low > high)
			break;
		
		mid = (low+high)/2;
		tmp_cnt=0;
		for(i=1; i<=N; i++)
			tmp_cnt += MIN(N, mid/i);
		
		if(tmp_cnt>=k) {
			result = mid;
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	
	printf("%d\n", result);
	
	return 0;	
}