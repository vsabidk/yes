#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("%d pushed to stack\n", item);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void peek() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    pop();
    push(30);
    push(40);
    pop();
    display();
    return 0;
}
