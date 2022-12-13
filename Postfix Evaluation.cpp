//lab 7:understanding evalution of prefix/postfix usinf stack as an adt
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 100
int stk[size];
int top=-1;
int isEmpty(){
    if(top==-1)
        return 1;
    else return 0;
}
int isFull(){
    if(top==size-1)
        return 1;
    else return 0;
}
void push(int x){
    if(isFull()){
        printf("Stack does not have space\n");
        exit(1);
    }
    else stk[++top]=x;
}
int pop(){
    if(isEmpty()){
        printf("Expression is Wrong\n");
        exit(1);
    }
    else 
        return(stk[top--]);
}
int isOperand(char x){
    if(x>='0' && x<='9')
        return 1;
    else return 0;
}
int isOperator(char x){
    switch(x){
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
int eval(int n1, int n2, char x)
{
    switch(x){
        case '+':
            return (n1+n2);
        case '-':
            return (n1-n2);
        case '*':
            return (n1*n2);
        case '/':
            return (n1/n2);
        case '%':
            return (n1%n2);
    }
}
int main(){
    char s[100];
    scanf("%s",s);
    int l = strlen(s);
    for(int i=0; i<l;i++){
        if(isOperand(s[i])) 
            push(s[i]-'0');
        else if(isOperator(s[i])){
            int n1=pop();
            int n2=pop();
            int t = eval(n2,n1,s[i]);
            push(t);
        }
    }
    if(top==0)
        printf("\nEvaluation is succesful, result is : %d\n",pop());
    else
        printf("Something wrong with the expression\n");
    return 0;
}
