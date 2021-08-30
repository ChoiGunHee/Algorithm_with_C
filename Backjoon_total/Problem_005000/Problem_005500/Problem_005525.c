/**
* 2021. 08. 16
* Creater : Gunhee Choi
* Problem Number : 5525
* Title : IOIOI

* Problem :
N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.

	P1 IOI
	P2 IOIOI
	P3 IOIOIOI
	PN IOIOI...OI (O가 N개)
	
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다.

	1
	13
	OOIOIOIOIIOII

* Output :
S에 PN이 몇 군데 포함되어 있는지 출력한다.

	4

* 제한
	1 ≤ N ≤ 1,000,000
	2N+1 ≤ M ≤ 1,000,000
	S는 I와 O로만 이루어져 있다.

**/

#include <stdio.h>
#include <string.h>

int main(void) {
	int N, M;
	char S[1000001];
	int result = 0;
	int len;
	int pn;
	int i, j;
	
	scanf("%d %d", &N, &M);
	scanf("%s", S);
	
	len = strlen(S);
	for(i=0; i<len; i++) {
		pn = 0;
		if(S[i]=='O')
			continue;
		else {
			while(S[i+1]=='O' && S[i+2]=='I') {
				pn++;
				if(pn==N) {
					pn--;
					result++;
				}
				
				i += 2;
			}
			pn = 0;
		}
	}
	
	printf("%d\n", result);
	
	return 0;	
}