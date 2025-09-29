#include <stdio.h>
#include <ctype.h>  
#include <string.h> 
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = c;
    }
}
char pop()
{
    char val;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else return stack[top--];
}

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];
        if (isalnum(c))
        {
            postfix[k] = c;
            k = k + 1;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[k] = pop();
                k = k + 1;
            }
            pop();
        }
        else
        {
            while (top != -1 && prec(stack[top]) >= prec(c))
            {
                postfix[k] = pop();
                k = k + 1;
            }
            push(c);
        }
    }
    while (top != -1)
    {
        postfix[k] = pop();
        k = k + 1;
    }
    postfix[k] = '\0';
}
int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
