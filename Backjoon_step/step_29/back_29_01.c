/**
* 2021. 08. 30
* Creater : Gunhee Choi
* Problem Number : 5337
* Title : 웰컴

* Problem :
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

* Input :
첫째 줄에 n(1 ≤ n ≤ 1,000,000), m(1 ≤ m ≤ 100,000)이 주어진다. m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. a와 b는 n 이하의 자연수 또는 0이며 같을 수도 있다.

	7 8
	0 1 3
	1 1 7
	0 7 6
	1 7 1
	0 3 7
	0 4 2
	0 1 1
	1 1 1

* Output :
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)

	NO
	NO
	YES
	
**/

#include <stdio.h>
#define INF 1000000

int set_arr[INF];

int find_func(int n) {
	int p;
	
	if(set_arr[n]<0)
		return n;
	
	p=find_func(set_arr[n]);
	set_arr[n]=p;
	
	return p;
}

void union_func(int n1, int n2) {
	n1=find_func(n1);
	n2=find_func(n2);
	if(n1==n2)
		return;
	set_arr[n1] = n2;
}

int main(void) {
	int N, M;
	int op, a, b;
	int i;
	
	scanf("%d %d", &N, &M);
	for(i=0; i<=N; i++)
		set_arr[i]=-1;
	
	for(i=0; i<M; i++) {
		scanf("%d %d %d", &op, &a, &b);
		
		if(op) {
			if(find_func(a)==find_func(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			union_func(a, b);
	}
	
	return 0;	
}