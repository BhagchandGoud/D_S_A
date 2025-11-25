#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 100

int stack[MAX], top = -1;
int minStackArr[MAX], minTop = -1;


void push(int val) {
    stack[++top] = val;

    if (minTop == -1 || val <= minStackArr[minTop]) {
        minStackArr[++minTop] = val;
    }
}

int pop() {
    if (top == -1) return -1;

    int removed = stack[top--];

    if (removed == minStackArr[minTop]) {
        minTop--;
    }

    return removed;
}

int topVal() {
    if (top == -1) return -1;
    return stack[top];
}


int getMin() {
    if (minTop == -1) return INT_MAX;
    return minStackArr[minTop];
}

void display(){
    for (int i = 0; i <= minTop; i++)
    {
        printf("%d ", minStackArr[i]);
    }
    
}

int    MinStack(){
    return  0;
}
void processCommands(char *ops[], int values[][1], int n) {
    for (int i = 0; i < n; i++) {

        if (strcmp(ops[i], "MinStack") == 0) {
            MinStack();
        }

        else if (strcmp(ops[i], "push") == 0) {
            push(values[i][0]);
        }

        else if (strcmp(ops[i], "pop") == 0) {
            pop();
        }

        else if (strcmp(ops[i], "top") == 0) {
            topVal();
        }

        else if (strcmp(ops[i], "getMin") == 0) {
            getMin();
        }
    }
}

int main() {

    char *ops[] = {
        "MinStack","push","push","push","getMin","pop","top","getMin"
    };

    int values[][1] = {
        {}, {-2}, {0}, {-3}, {}, {}, {}, {}
    };

    int n = sizeof(ops) / sizeof(ops[0]);

    processCommands(ops, values, n);
 display();
    return 0;
}
