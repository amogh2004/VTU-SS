%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror();
int id=0,dig=0,key=0,op=0;
%}
%token DIGIT ID KEY OP
%%
input:DIGIT input { dig++; }
| ID input { id++; }
| KEY input { key++; }
| OP input { op++; }
| DIGIT { dig++; }
| ID { id++; }
| KEY  { key++; }
| OP  { op++; }
;
%%
#include<stdio.h>

main()
{
	FILE *myfile = fopen("sam_input.c","r");
	if(!myfile) {
	printf("Cant open file!");
	return -1;
	}
	yyin=myfile;
	do{
	yyparse();
	}while(!feof(yyin));
	printf("Numbers= %d \n Keywords= %d \n Identifiers= %d \n Operators= %d \n", dig,key,id,op);
}
void yyerror(){
printf("EEK, parse error message:");
exit(-1);
}
