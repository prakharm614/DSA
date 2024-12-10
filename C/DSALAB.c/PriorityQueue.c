#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
void push(struct Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}
char pop(struct Stack *stack)
{
    return (!isEmpty(stack)) ? stack->array[stack->top--] : '\0';
}
char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int getPrecedence(char op)
{switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
void infixToPostfix(char *infix, char *postfix)
{
    struct Stack *stack = createStack(MAX_SIZE);
    int i, j;
    i = j = 0;
 while (infix[i] != '\0'){
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(')
        {
            push(stack, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[j++] = pop(stack);
            }
            (!isEmpty(stack) && peek(stack) != '(') ? printf("Invalid infix expression\n") : pop(stack);
            i++;}
        else
        {
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(peek(stack)))
            {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i++]);}
    }
    while (!isEmpty(stack))
    {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}
int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
