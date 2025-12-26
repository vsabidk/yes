#include <stdbool.h>

#define MAX 10000

char stack[MAX];
int top = -1;

void push(char el) {
    if (top == MAX - 1) {
        return; // Overflow ignored
    }
    stack[++top] = el;
}

char pop() {
    if (top == -1) {
        return '\0'; // Underflow
    }
    return stack[top--];
}

int match(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int valid(char b) {
    if (b == '{' || b == '}' || b == '(' || b == ')' || b == '[' || b == ']')
        return 1;
    return 0;
}

bool isValid(char* s) {
    top = -1;
    char ch;
    int i = 0;
    int isB = 1; // assume balanced initially

    while ((ch = s[i]) != '\0') {
        if (valid(ch)) {
            if (ch == '(' || ch == '{' || ch == '[') {
                push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                char popped = pop();
                if (popped == '\0' || !match(popped, ch)) {
                    isB = 0;
                    break;
                }
            }
        }
        i++;
    }

    if (top != -1) // unmatched openings
        isB = 0;

    return isB == 1;
}
