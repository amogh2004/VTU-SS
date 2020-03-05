%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0;
%}
%%
[a-z A-Z]+[0-9 A-Z a-z]* {id++; printf("\nIdentifier:");ECHO;}
[\+\-\*\/\=] {op++; printf("\n operator:");ECHO;}
"(" {v++;}
")" {v--;}
";" {flag=1;}
.|\n {;}
%%

int main()
{
printf("Enter the expression");
yylex();
if(((op+1)==id) && (v==0) && (flag==0))
{
printf("\nValid Expression\n");
printf("number of identifiers=%d\n",id);
printf("number of operators=%d\n",op);
}
else printf("\n invalid expression\n");
}
int yywrap()
{
return 1;
}

