#include <stdio.h>
#include <string.h>
#define max 100

char stack[max];
int top = -1;

void push(char ch)
{
    if (top == max - 1)
    {
        return;
    }
    stack[++top] = ch;
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%s", stack[i]);
    }
}

void reverseStr(char *str)
{
    int length = strlen(str);
    char reverse[length + 1];
    int i = 0, j = 0;
    while (str[i] != '\0' && i < length)
    {
        push(str[i]);
        i++;
    }

    while (top != -1)
    {
        reverse[j++] = pop();
    }

    reverse[j] = '\0';

    printf("%s", reverse);
}

int main()
{
    char str[] = "bhagchand";
    reverseStr(str);

    return 0;
}