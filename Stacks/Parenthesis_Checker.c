#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define max 100

char stack[max];
int top = -1;

void push(char val){
    if (top == max-1)
    {
       return ;
    }
    stack[++top] = val;
    
}

int pop(){
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

void display(){
    printf("Stack Elements are :");
    for (int i = top; i >= 0; i--)
    {
       printf("%c" , stack [i]);
    }
    
}



bool  parenthesisChacker(char *str){
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        char ch = str[i];
        if (ch== '(' || ch== '{' || ch == '[')
        {
             push(ch);
        }
        else if ( ch== ')' || ch == '}' || ch == ']'){
            char topChar = pop();
            
       if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                return true;
            }
           else{
            return false;
           }
        }
    }





    return top == -1;
}


int main(){
   char str[] = "([{}])";

    if (!parenthesisChacker(str))
           printf("Invalid Parenthesis\n");
    else
       printf("Valid Parenthesis\n");
    
  
    return 0;
}