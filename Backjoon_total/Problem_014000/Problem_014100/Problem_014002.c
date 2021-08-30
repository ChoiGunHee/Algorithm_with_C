/**
* 2021. 08. 28
* Creater : Gunhee Choi
* Problem Number : 14002
* Title : 가장 긴 증가하는 부분 수열 4

* Problem :
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

* Input :
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	6
	10 20 10 30 20 50
	
* Output :
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.

	4
	10 20 30 50
	
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long N;
	long long * list;
	long long tmp;
	long long i_list=0;
	long long low, high, mid;
	long long i;
	
	scanf("%lld", &N);
	list = (long long *) malloc(sizeof(long long)*N);
	
	for(i=0; i<N; i++) {
		scanf("%lld", &tmp);
		if(i==0)
			list[i]=tmp;
		
		if(tmp>list[i_list])
			list[++i_list] = tmp;
		else {
			low=0;
			high=i_list;
			
			while(low<high) {
				mid=(low+high)/2;
				
				if(list[mid]<tmp)
					low=mid+1;
				else
					high=mid;
			}
			
			list[high]=tmp;
		}
			
	}
	
	printf("%lld\n", i_list+1);
	for(i=0; i<i_list+1; i++)
		printf("%lld ", list[i]);
	printf("\n");
	
	return 0;	
}