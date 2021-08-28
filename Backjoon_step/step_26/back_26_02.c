/**
* 2021. 08. 28
* Creater : Gunhee Choi
* Problem Number : 2470
* Title : 두 용액

* Problem :
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.  산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다.

같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다. 

예를 들어, 주어진 용액들의 특성값이 [-2, 4, -99, -1, 98]인 경우에는 특성값이 -99인 용액과 특성값이 98인 용액을 혼합하면 특성값이 -1인 용액을 만들 수 있고, 이 용액이 특성값이 0에 가장 가까운 용액이다. 참고로, 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다.

산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.

* Input :
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하이다. 둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. N개의 용액들의 특성값은 모두 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.

	5
	-2 4 -99 -1 98
	
* Output :
첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다. 출력해야 하는 두 용액은 특성값의 오름차순으로 출력한다. 특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다.

	-99 98

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 2000000000

int compare(const void *a, const void *b) {
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1 < num2)
		return -1;
	else if(num1 > num2)
		return 1;

	return 0;
}

int main(void) {
	int n;
	int * arr;
	int start, end;
	int sum;
	int result_min = MAX_NUM;
	int tmp;
	int result[2];
	int i;
	
	scanf("%d", &n);
	arr = (int *) malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	qsort(arr, n, sizeof(int), compare);
	
	start=0;
	end=n-1;
	sum=0;
	
	while(start < end) {
		sum = arr[start] + arr[end];
		
		if(result_min > abs(sum)) {
			result_min = abs(sum);
			result[0] = arr[start];
			result[1] = arr[end];
		}
		
		if(sum==0)
			break;
		
		if (sum < 0) 
            start++;
        else 
            end--;
	}
	
	printf("%d %d\n", result[0], result[1]);
	
	return 0;	
}