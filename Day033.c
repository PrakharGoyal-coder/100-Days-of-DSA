/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/
#include<stdio.h>
char stack[100];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    return stack[top--];
}
int precedence(char op)
{
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    return 0;
}
int main()
{
    char infix[100],postfix[100];
    int i=0,j=0;
    printf("Enter infix expression:");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        if((infix[i]>='A' && infix[i]<='Z')||(infix[i]>='a' && infix[i]<='z'))
        {
            postfix[j++]=infix[i];
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(infix[i]))
            {
                postfix[j++]=pop();
            }
            push(infix[i]);
         
        }
        i++;
    }
     while(top!=-1)
     {
         postfix[j++]=pop();
     }
     postfix[j]='\0';
     printf("Postfix expression:%s",postfix);
     return 0;    
}