#include<stdio.h>
#include<string.h>
#define max 100

char stack[max];
int top = -1;

void push(char ch){
    if (top == max-1)
    {
        return;
    }
    stack[++top] = ch;
    
}


char pop(){
    if (top == -1)
    {
        return -1 ;
    }
    return stack[top--];
    
}

void display(){
    for (int i = top; i >= 0; i--)
    {
        printf("%c " , stack[i]);
    }
    
}


char *swapping(char newStr[]){
    int n = strlen(newStr);
for (int i = 0; i < n/2; i++)
{
    int temp = newStr[i];
    newStr[i] = newStr[n-i-1];
    newStr[n-i-1] = temp;
}
 return newStr;
}



void* RemoveDuplicateLetters(char str[], int length){
    int freq[256] = {0};
    int inStack[256] = {0};

    for (int i = 0; i < length; i++)
        freq[(unsigned char)str[i]]++;

    for (int i = 0; i < length; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]--; 

        if (inStack[ch])
            continue;

        while (top != -1 &&
               stack[top] > ch &&      
               freq[(unsigned char)stack[top]] > 0)  
        {
            inStack[(unsigned char)stack[top]] = 0;
            pop();
        }

        push(ch);
        inStack[ch] = 1;
    }

    char newStr[top + 2];
    int i = 0;

    while (top != -1)
        newStr[i++] = pop();

    newStr[i] = '\0';

    swapping(newStr);

    printf("%s", newStr);
}

int main(){
char s[] = "cbacdcbc";
int n = strlen(s);
RemoveDuplicateLetters(s,n);
    return 0;
}