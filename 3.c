#include <stdio.h>
#include <conio.h>
#include <string.h>

int h = 0, top = -1, k = 0, i = 0, j = 0, length;
char symbol, infix[20], postfix[20], stack[20];

void infixtopostfix();
int preceed(char);
void push(char);
char pop();

void main() {
    int len;
    printf("Enter infix expression:");
    scanf("%s", infix);
    len = strlen(infix) - 1;
    // Reverse the infix expression
    for (h = 0; h <= len / 2; h++) {
        char temp;
        temp = infix[h];
        infix[h] = infix[len - h];
        infix[len - h] = temp;
    }
    // Replace '(' with ')' and vice versa
    for (h = 0; h < strlen(infix); h++) {
        if (infix[h] == ')') {
            infix[h] = '(';
        } else if (infix[h] == '(') {
            infix[h] = ')';
        }
    }
    infixtopostfix();
    printf("Pre-fix expression is: ");
    for (k = strlen(postfix) - 1; k >= 0; k--) {
        printf("%c", postfix[k]);
    }
    getch();
}

void push(char symbol) {
    stack[++top] = symbol;
}

char pop() {
    char temp;
    temp = stack[top--];
    return temp;
}

void infixtopostfix() {
    char temp;
    length = strlen(infix);
    push('#');
    while (i < length) {
        symbol = infix[i];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                temp = pop();
                while (temp != '(') {
                    postfix[j++] = temp;
                    temp = pop();
                }
                break;
            case '/':
            case '*':
            case '^':
            case '+':
            case '-':
                while (preceed(stack[top]) == preceed(symbol)) {
                    temp = pop();
                    postfix[j++] = temp;
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
        i++;
    }
    while (top > 0) {
        postfix[j++] = pop();
    }
}

int preceed(char symbol) {
    int p;
    switch (symbol) {
        case '^':
            p = 3;
            break;
        case '/':
        case '*':
            p = 2;
            break;
        case '+':
        case '-':
            p = 1;
            break;
        case '(':
        case ')':
            p = 0;
            break;
        case '#':
            p = -1;
            break;
    }
    return p;
}
