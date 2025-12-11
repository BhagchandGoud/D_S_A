#include<stdio.h>
#define max 100
#include<string.h>
#include<ctype.h>

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
void pushChar(char character){
    if (top2 == max-1)
    {
        return;
    }

    op[++top2] = character;
}

int popVal(){
    if (top1 == -1)
    {
        return -1;
    }
    return val[top1--];
}
char popChar(){
    if (top2 == -1)
    {
        return -1;
    }
    return op[top2--];
}


int precedence(char op){
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    
    return 0;
}


int apply(int a , int b ,  char op){
               if (op == '+')
           {
            return a+b;
           }

           if (op== '-')
           {
            return a-b;
           }
           if (op == '*')
           {
           return a*b;
           }
           if (op == '/')
           {
           return a/b;
           }
} 




int main(){

    char str[] = "8-5+3*4/6";
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
       if (str[i] >= 48 && str[i] <= 57)
       {
        pushVal(str[i]-'0');
       }
       else if (top2 == -1)
       {
        pushChar(str[i]);
       }
       else{
   while (top2 != -1 && precedence(op[top2]) >= precedence(str[i])) 
   {
            int v1 = popVal();
           int v2 = popVal();
            char c=    popChar();
          pushVal(apply(v2, v1, c)); 
        }
        pushChar(str[i]);
       }
    }

    while (top2 != -1)
    {
      int v1 = popVal();
           int v2 = popVal();
       char c=    popChar();
        pushVal(apply(v2, v1, c)); 
    }
    
    printf("%d" , val[top1]);
    return 0;
}