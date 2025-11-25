#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. ISEMPTY\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            val = pop();
            if (val != -1)
                printf("Popped: %d\n", val);
            break;

        case 3:
            val = peek();
            if (val != -1)
                printf("Top element: %d\n", val);
            break;

        case 4:
            if (isEmpty())
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
