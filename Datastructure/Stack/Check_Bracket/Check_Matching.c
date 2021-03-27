/* 2021. 03. 11
 * Creater : Gunhee Choi
 * This file is Check Matching Program
 */

#include "Sim_Stack.h"
#include "Check_Matching.h"

int check_matching(const char * input) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(input);
	init_stack(&s);
	
	for(i=0; i<n; i++) {
		ch = input[i];
		switch (ch) {
			case '(' :
			case '[' :
			case '{' :
				push(&s, ch);
				break;
			case ')' :
			case ']' :
			case '}' :
				if(is_empty(&s)) return 0;
				else {
					open_ch = pop(&s);
					if( (open_ch == '(' && ch != ')') ||
					  	(open_ch == '(' && ch != ')') ||
					    (open_ch == '(' && ch != ')') ) {
						return 0;
					}//if
				break;
				}//else
		}//switch
	}//for
	
	if( !is_empty(&s) ) return 0;
	return 1;
}