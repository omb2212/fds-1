#include <stdio.h>
#include <string.h>
#define size 100
char stack[size];
int top = -1;
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char x)
{
    if (top == size - 1)
    {
        return;
    }
    stack[++top] = x;
}
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}
char top_element()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}
int operator_precedence(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
    case '%':
        return 2;
    }
}
int is_operand(char x)
{
    if (('a' <= x && 'z' >= x) || ('0' <= x && '9' >= x))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_operator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return 1;
    default:
        return 0;
    }
}
int main()
{
    char string[100], str_length;
    printf("Enter an expression: ");
    scanf("%s", &string);
    // str_length=strlen(s);
    for (int i = 0; i < strlen(string); i++)
    {
        if (is_operand(string[i]))
        {
            printf("%c ", string[i]);
        }
        else if (is_operator(string[i]))
        {
            if (isempty())
            {
                push(string[i]);
            }
            else
            {
                while (operator_precedence(string[i]) <= operator_precedence(top_element()) && (!isempty()))
                {
                    printf("%c ", pop());
                }
                push(string[i]);
            }
        }
    }
    while (!isempty())
    {
        printf("%c ", pop());
    }
    return 0;
}
