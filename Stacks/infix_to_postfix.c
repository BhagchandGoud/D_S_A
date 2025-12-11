#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100

char val[max][max];
char op[max];
int top1 = -1 , top2 = -1;

void pushVal(char*num){
    strcpy(val[++top1] , num);
}

void pushOp(char ch){
    if (top2 == max-1)
    {
       return;
    }
    op[++top2] = ch;
}

char *popVal(){
    return val[top1--];
}
char popOp(){
    return  op[top2--];
}


int precedence(char op){
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '/' || op =='*')
    {
        return 2;
    }
    return 0;
}


int main(){
    char str[] = "9-5+3*4/6";
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(str[i]))
        {
           char temp[2] = {str[i] , '\0'};
           pushVal(temp);
        }
        else if (top2 == -1)
        {
            pushOp(str[i]);
        }
        else{
            while (top2 != -1 && precedence(op[top2]) >= precedence(str[i]))
            {
                char *v1 = popVal();
                char *v2 = popVal();
                char temp[max] = "";
                strcat(temp , v2);
                strcat(temp ,v1);
                char opr[2] = {popOp(), '\0'};
                strcat(temp, opr);
                pushVal(temp);
            }
            pushOp(str[i]);
        }
    }
    while (top2 != -1 )
            {
                char *v1 = popVal();
                char *v2 = popVal();
                char temp[max] = "";
                strcat(temp , v2);
                strcat(temp ,v1);
                char opr[2] = {popOp(), '\0'};
                strcat(temp, opr);
                pushVal(temp);
            }

            printf("%s" , val);
            return 0;
}