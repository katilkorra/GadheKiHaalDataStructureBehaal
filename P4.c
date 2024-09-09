#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char stk[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

char peek() {
    return stk[top];
}

char pop() {
    if (isEmpty())
        return -1;

    char ch = stk[top];
    top--;
    return ch;
}

void push(char oper) {
    if (isFull())
        printf("Stack Full!!!! ");

    else {
        top++;
        stk[top] = oper;
    }
}

int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

void infixToPostfix(char infix[]) {
    char postfix[100];
    int postfixIndex = 0;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char c = infix[i];

        if (checkIfOperand(c)) {
            postfix[postfixIndex++] = c;
        } else {
            while (!isEmpty() && precedence(c) <= precedence(peek())) {
                postfix[postfixIndex++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[postfixIndex++] = pop();
    }

    postfix[postfixIndex] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%99s", infix); // use scanf with a width specifier to prevent buffer overflow

    infixToPostfix(infix);

    return 0;
}
