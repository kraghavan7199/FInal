%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  int top=-1;
  void yyerror(char *);
  extern FILE *yyin;
  #define YYSTYPE char*
  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  typedef struct twc
  {
    char *code; 
  }wc;
 
  int quadlen = 0;
  quad q[100];
  wc w[100];
%}

%start S
%token ID NUM T_lt T_gt T_lteq T_gteq T_neq T_noteq T_eqeq T_and T_or T_incr T_decr T_not T_eq WHILE INT CHAR FLOAT VOID H MAINTOK INCLUDE BREAK CONTINUE IF ELSE COUT STRING FOR ENDL T_ques T_colon

%token T_pl T_min T_mul T_div
%left T_lt T_gt
%left T_pl T_min
%left T_mul T_div

%%
S
      : START {printf("Input accepted.\n");}
      ;

START
      : INCLUDE T_lt H T_gt MAIN
      | INCLUDE "\"" H "\"" MAIN
      ;

MAIN
      : VOID MAINTOK BODY
      | INT MAINTOK BODY
      ;

BODY
      : '{' C '}'
      ;

C
      : C statement ';'
      | C LOOPS
      | statement ';'
      | LOOPS
      ;

LOOPS
      : WHILE {while1();} '(' COND ')'{while2();} LOOPBODY{while3();}
      | FOR '(' ASSIGN_EXPR{for1();} ';' COND{for2();} ';' statement{for3();} ')' LOOPBODY{for4();}
      | IF '(' COND ')' {ifelse1();} LOOPBODY{ifelse2();} ELSE LOOPBODY{ifelse3();}
      | IF '(' COND ')' {if1();} LOOPBODY{if3();};

TERNARY_EXPR
      :  '(' TERNARY_COND ')' {ternary1();} T_ques statement{ternary2();} T_colon statement{ternary3();}
      ;

LOOPBODY
  	  : '{' LOOPC '}'
  	  | ';'
  	  | statement ';'
  	  ;

LOOPC
      : LOOPC statement ';'
      | LOOPC LOOPS
      | statement ';'
      | LOOPS
      ;

statement
      : ASSIGN_EXPR
      | EXP
      | TERNARY_EXPR
      | PRINT
      ;

TERNARY_COND  : T_B {codegen_assigna();}
              | T_B T_and{codegen_assigna();} TERNARY_COND
              | T_B {codegen_assigna();}T_or TERNARY_COND
              | T_not T_B{codegen_assigna();}
              ;

T_B : T_V T_eq{push();}T_eq{push();} LIT
  | T_V T_gt{push();}T_F
  | T_V T_lt{push();}T_F
  | T_V T_not{push();} T_eq{push();} LIT
  |'(' T_B ')'
  | T_V {pushab();}
  ;

T_F :T_eq{push();}LIT
  |LIT{pusha();}
  ;

COND  : B {codegen_assigna();}
      | B T_and{codegen_assigna();} COND
      | B {codegen_assigna();}T_or COND
      | T_not B{codegen_assigna();}
      ;

B : V T_eq{push();}T_eq{push();} LIT
  | V T_gt{push();}F
  | V T_lt{push();}F
  | V T_not{push();} T_eq{push();} LIT
  |'(' B ')'
  | V {pushab();}
  ;

F :T_eq{push();}LIT
  |LIT{pusha();}
  ;

V : ID{push();}

T_V : ID{pushx();}

ASSIGN_EXPR
      : LIT {push();} T_eq {push();} EXP {codegen_assign();}
      | TYPE LIT {push();} T_eq {push();} EXP {codegen_assign();}
      ;

EXP
	  : ADDSUB
	  | EXP T_lt {push();} ADDSUB {codegen();}
	  | EXP T_gt {push();} ADDSUB {codegen();}
	  ;

ADDSUB
      : TERM
      | EXP T_pl {push();} TERM {codegen();}
      | EXP T_min {push();} TERM {codegen();}
      ;

TERM
	  : FACTOR
      | TERM T_mul {push();} FACTOR {codegen();}
      | TERM T_div {push();} FACTOR {codegen();}
      ;

FACTOR
	  : LIT
	  | '(' EXP ')'
  	;

PRINT
      : COUT T_lt T_lt STRING
      | COUT T_lt T_lt STRING T_lt T_lt ENDL
      ;
LIT
      : ID {push();}
      | NUM {push();}
      ;
TYPE
      : INT
      | CHAR
      | FLOAT
      ;
RELOP
      : T_lt
      | T_gt
      | T_lteq
      | T_gteq
      | T_neq
      | T_eqeq
      ;
bin_boolop
      : T_and
      | T_or
      ;

un_arop
      : T_incr
      | T_decr
      ;

un_boolop
      : T_not
      ;


%%

#include "lex.yy.c"
#include<ctype.h>
char st[100][100];
char code[100][7];
int c_line = 0;
char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int abcd=0;
int l_while=0;
int l_for=0;
int flag_set = 1;


int main(int argc,char *argv[])
{
  FILE *f;
  int i = 0;
  yyin = fopen("input.c","r");
  if(!yyparse())  
  {
    printf("Parsing Complete\n");
    f=fopen("icg.txt","w");
    for(i=0;i<quadlen;i++)
    {
    fprintf(f,"%s %s %s %s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
     fclose(f);
  }
  else
  {
    printf("Parsing failed\n");
  }

  fclose(yyin);
  return 0;
}

void yyerror(char *s)
{
  printf("Error :%s at %d \n",yytext,yylineno);
}

push()
{
strcpy(st[++top],yytext);
}
pusha()
{
strcpy(st[++top],"  ");
}
pushx()
{
strcpy(st[++top],"x ");
}
pushab()
{
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
}
codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," = ");
    strcat(w[c_line].code,st[top-2]);
    strcat(w[c_line].code," ");
    strcat(w[c_line].code,st[top-1]);
    strcat(w[c_line].code," ");
    strcat(w[c_line].code,st[top]);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top-=2;
    strcpy(st[top],temp);

temp_i++;
}
codegen_assigna()
{
strcpy(temp,"T");
sprintf(tmp_i, "%d", temp_i);
strcat(temp,tmp_i);
printf("%s = %s %s %s %s\n",temp,st[top-3],st[top-2],st[top-1],st[top]);
   w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," = ");
    strcat(w[c_line].code,st[top-3]);
    strcat(w[c_line].code," ");
    strcat(w[c_line].code,st[top-2]);
    strcat(w[c_line].code,st[top-1]);
    strcat(w[c_line].code," ");
    strcat(w[c_line].code,st[top]);
    c_line++;
//printf("%d\n",strlen(st[top]));
if(strlen(st[top])==1)
{
	//printf("hello");
	
    char t[20];
	//printf("hello");
	strcpy(t,st[top-2]);
	strcat(t,st[top-1]);
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,t);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    
}
else
{
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-2]);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top-1]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
}
top-=4;

temp_i++;
strcpy(st[++top],temp);
}

codegen_umin()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = -%s\n",temp,st[top]);
      w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," = ");
    strcat(w[c_line].code,"-");
    strcat(w[c_line].code,st[top]);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"-");
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top--;
    strcpy(st[top],temp);
    temp_i++;
}
codegen_assign()
{
    printf("%s = %s\n",st[top-3],st[top]);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,st[top-3]);
    strcat(w[c_line].code," = ");
    strcat(w[c_line].code,st[top]);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-3]);
    quadlen++;
    top-=2;
}

if1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 printf("%s = not %s\n",temp,st[top]);
 w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," = ");
    strcat(w[c_line].code," not ");
    strcat(w[c_line].code,st[top]);
    c_line++;
 q[quadlen].op = (char*)malloc(sizeof(char)*4);
 q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
 q[quadlen].arg2 = NULL;
 q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
 strcpy(q[quadlen].op,"not");
 strcpy(q[quadlen].arg1,st[top]);
 strcpy(q[quadlen].res,temp);
 quadlen++;
 printf("if %s goto L%d\n",temp,lnum);
 w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"if ");
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," goto ");
    strcat(w[c_line].code,lnum);
    c_line++;
 q[quadlen].op = (char*)malloc(sizeof(char)*3);
 q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
 q[quadlen].arg2 = NULL;
 q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
 strcpy(q[quadlen].op,"if");
 strcpy(q[quadlen].arg1,st[top-2]);
 char x[10];
 sprintf(x,"%d",lnum);
 char l[]="L";
 strcpy(q[quadlen].res,strcat(l,x));
 quadlen++;

 temp_i++;
 label[++ltop]=lnum;
}

if3()
{
    char y1[1];
    int y;
    sprintf(y1,"%d",y);
    y=label[ltop--];
    printf("L%d: \n",y);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y1);
    strcat(w[c_line].code,":");
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}

ifelse1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,st[top]);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," = not ");
    strcat(w[c_line].code,st[top]);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    char y2[1];
    sprintf(y2,"%d",lnum);
    printf("if %s goto L%d\n",temp,lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"if ");
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," goto ");
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y2);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    temp_i++;
    label[++ltop]=lnum;
}

ifelse2()
{
    int x;
    lnum++;
    x=label[ltop--];
    char y3[1];
    sprintf(y3,"%d",lnum);
    printf("goto L%d\n",lnum);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"goto ");
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y3);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    printf("L%d: \n",x);
    char y4[1];
    sprintf(y4,"%d",x);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y4);
    strcat(w[c_line].code,": ");
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");

    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
    label[++ltop]=lnum;
}

ifelse3()
{
int y;
y=label[ltop--];
printf("L%d: \n",y);
 char y5[1];
    sprintf(y5,"%d",y);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y5);
    strcat(w[c_line].code,": ");
    c_line++;
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
lnum++;
}

ternary1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 printf("%s = not %s\n",temp,st[top]);
 q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
 printf("if %s goto L%d\n",temp,lnum);
 q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

 temp_i++;
 label[++ltop]=lnum;
}

ternary2()
{
int x;
lnum++;
x=label[ltop--];
printf("goto L%d\n",lnum);
q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
printf("L%d: \n",x);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
    label[++ltop]=lnum;
}

ternary3()
{
int y;
y=label[ltop--];
printf("L%d: \n",y);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
lnum++;
}

while1()
{

    l_while = lnum;
    printf("L%d: \n",lnum++);
     char y6[5];
    sprintf(y6,"%d",lnum);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y6);
    strcat(w[c_line].code,": ");
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}

while2()
{
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 printf("%s = not %s\n",temp,st[top]);
     w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," = not ");
    strcat(w[c_line].code,st[top]);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    printf("if %s goto L%d\n",temp,lnum);
    char y7[5];
    sprintf(y7,"%d",lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"if ");
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code,"goto L");
    strcat(w[c_line].code,y7);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

 temp_i++;
 }

while3()
{

printf("goto L%d \n",l_while);
char y15[5];
    sprintf(y15,"%d",l_while);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"goto L");
    strcat(w[c_line].code,y15);
    c_line++;
q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",l_while);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    printf("L%d: \n",lnum++);
    char y16[5];
    sprintf(y16,"%d",lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y16);
    strcat(w[c_line].code,":");
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
}

for1()
{
    l_for = lnum;
    printf("L%d: \n",lnum++);
    char y14[5];
    sprintf(y14,"%d",lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y14);
    strcat(w[c_line].code,":");
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}
for2()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,st[top]);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," = not ");
    strcat(w[c_line].code,st[top]);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    printf("if %s goto L%d\n",temp,lnum);
    char y11[5];
    sprintf(y11,"%d",lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"if ");
    strcat(w[c_line].code,temp);
    strcat(w[c_line].code," goto L");
    strcat(w[c_line].code,y11);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
    lnum++;
    printf("goto L%d\n",lnum);
   char y12[5];
    sprintf(y12,"%d",lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"goto L");
    strcat(w[c_line].code,y12);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char x1[10];
    sprintf(x1,"%d",lnum);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
    label[++ltop]=lnum;
    printf("L%d: \n",++lnum);
    char y13[5];
    sprintf(y13,"%d",lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y13);
    strcat(w[c_line].code,":");
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x2[10];
    sprintf(x2,"%d",lnum);
    char l2[]="L";
    strcpy(q[quadlen].res,strcat(l2,x2));
    quadlen++;
 }
for3()
{
    int x;
    x=label[ltop--];
    printf("goto L%d \n",l_for);
    char y10[5];
    sprintf(y10,"%d",l_for);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"goto L");
    strcat(w[c_line].code,y10);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",l_for);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;


    printf("L%d: \n",x);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

}

for4()
{
    int x;
    x=label[ltop--];
    printf("goto L%d \n",lnum);
    char y8[5];
    sprintf(y8,"%d",lnum);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"goto L");
    strcat(w[c_line].code,y8);
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    printf("L%d: \n",x);
    char y9[5];
    sprintf(y9,"%d",x);
    w[c_line].code = (char*)malloc(sizeof(char));
    strcat(w[c_line].code,"L");
    strcat(w[c_line].code,y9);
    strcat(w[c_line].code,":");
    c_line++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
}
