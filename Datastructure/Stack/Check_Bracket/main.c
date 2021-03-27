#include "basic.h"
#include "Sim_Stack.h"
#include "Check_Matching.h"

int main(void) {
	char * str1 = "{ A[i+1=0] }";
	char * str2 = "{( B[i+1=0] }";
	char * str3 = "{ C[(i+1=0) + ([s+3]+[g+5])] }";
	
	if(check_matching(str1) == 1)
		printf("%s 괄호 검사 성공\n", str1);
	else
		printf("%s 괄호 검사 실패\n", str1);
	
	if(check_matching(str2) == 1)
		printf("%s 괄호 검사 성공\n", str2);
	else
		printf("%s 괄호 검사 실패\n", str2);
	
	if(check_matching(str3) == 1)
		printf("%s 괄호 검사 성공\n", str3);
	else
		printf("%s 괄호 검사 실패\n", str3);
	
	return 0;
}