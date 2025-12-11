#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max  100

int val[max];
char op[max];

int top1 = -1 , top2 = -1;

void pushVal(int num){
    if (top1 == max-1)
    {
       return;
    }
    val[++top1] = num;
}

void pushOp(char ch){
    if (top2 == max-1)
    {
       return;
    }
    op[++top2] = ch;
}

int popVal(){
    return val[top1--];
}

int popOp(){
    return op[top2--];
}
int precendence(char op){
    if(op == '+' || op == '-' )return 1;
    else if(op == '/' || op == '*') return 2;
    return 0;
}

int apply(int a  , int b , char c){
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

int main(){
char str[] = "-9/*+5346";
int n = strlen(str);

for (int i = n-1; i>=0; i--)
{
    if (isdigit(str[i]))
    {
        pushVal(str[i]-'0');
    }
    else{
        while (top2 != -1 && precendence(op[top2]) >= precendence(str[i]))
        {
            int v1 = popVal();
            int v2 = popVal();
            char c = popOp();
            pushVal(apply(v1 ,v2 ,c));
        }
        pushOp(str[i]);
    }
}

printf("%d" , val[top1]);

    return 0;
}