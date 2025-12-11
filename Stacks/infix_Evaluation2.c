#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
#include<signal.h>

int val[max];
char op[max];
int top1 = -1 , top2 = -1;

void pushVal(int num){
    if (top1 == max-1)
    {
       return ;
    }
    val[++top1] = num;
}
void pushChar(char ch){
    if (top2 == max-1)
    {
       return ;
    }
    op[++top2] = ch;
}


int popVal(){
    if (top1 == -1)
    {
        return -1;
    }
    return val[top1--];
}

char popOp(){
    if (top2 == -1)
    {
        return -1;
    }
    return op[top2--];
}


int apply(int a , int b , char c){
    if (c == '+')
    {
        return a+b;
    }
    if (c == '-')
    {
        return a-b;
    }
    if (c == '*')
    {
        return a*b;
    }
    if (c == '/')
    {
        return a/b;
    }
}


int precedence(char op){
    if (op == '+' || op == '-')
    {
       return 1;
    }
    else if (op == '*' || op =='/')
    {
        return 2;
    }
    return 0;
}

int main(){
  char str[] = "9-(5+3)*4/6";
  int n = strlen(str);
  for (int i = 0; i < n; i++)
  {
    if (isdigit(str[i]))
    {
       pushVal(str[i]- '0');
    }
    else if (str[i] == '(')
    {
          pushChar(str[i]);
    }
    
    else if (str[i] == ')')
    {
       while (top2 != -1 && op[top2] != '(')
        {
            int v1 = popVal();
            int v2 = popVal();
           char c = popOp();
           pushVal(apply(v2 ,v1 ,c));
        }
        popOp();
    }
    else{
        while (top2 != -1 && precedence(op[top2]) >= precedence(str[i]))
        {
            if (op[top2] == '(') break;
            int v1 = popVal();
            int v2 = popVal();
           char c = popOp();
           pushVal(apply(v2 ,v1 ,c));
        }
        pushChar(str[i]);
    }
  }
      while (top2 != -1)
        {
            int v1 = popVal();
            int v2 = popVal();
           char c = popOp();
           pushVal(apply(v2 ,v1 ,c));
    }

    printf("%d" , val[top1]);
    return 0;
}