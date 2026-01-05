#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

/* Return operator precedence */
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
    
}

/* Push to stack */
void push(char c) {
    stack[++top] = c;
}

/* Pop from stack */
char pop() {
    return stack[top--];
}

int main() {
    char infix[50], postfix[50];
    int i, k = 0;

    /* Read infix expression */
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        /* If operand, add to postfix */
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        /* If '(', push to stack */
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        /* If ')', pop until '(' */
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();  // remove '('
        }

        /* Operator */
        else {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    /* Print postfix expression */
    printf("%s", postfix);

    return 0;
}
