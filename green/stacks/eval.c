#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char postfix[]) {
    int i = 0;
    char c;
    int a, b;

	    while ((c = postfix[i]) != '\0') {
        if (isdigit(c)) {
            push(c - '0');  // convert char digit to int
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            b = pop();
            a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX];
    int result, i = 0, c;

    printf("Enter postfix expression: ");
    while ((c = getchar()) != '\n') {
        postfix[i++] = (char)c;
    }
    postfix[i] = '\0';

    result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);

    return 0;
}
