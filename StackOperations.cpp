#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
void push(int x){
	if(top == SIZE - 1 ){
		printf("The stack is full\n");
		}
	else{
		top = top + 1;
		stack[top] = x; 
}
}
int pop(){
	if(top==-1){
		printf("The stack is empty \n");
		return -1;
	}
	return stack[top--];
}
int is_Empty(){
	if(top==-1){
		printf("The stack is empty\n");
		return 1;
	}
	else{
		printf("The stack is not empty\n");
		return 0;
	}
}
int is_full(){
	if (top = SIZE-1){
		printf("the stack is full\n");
		return 1;
	}
	else{
		printf("The stack is not full\n");
		return 0;
	}
}
void traverse(){
	int i;
	for(i=top; i>=0; i--){
		printf("%d\n", stack[i]);
	}
	printf("\n");
}
int main(){
	push(3);
	push(5);
	push(9);
	traverse();
	pop();
	traverse();
	push(10);
	push(11);
	pop();
	traverse();
	is_Empty();
}

