#include<stdio.h>
#define size 5
int que[size];
int front=-1,rear=-1;
void frontele()
{
	if(front==-1)
	{
		printf("Q is empty");
	}
	else
	{
		printf("\nfront element is %d\t",que[front]);
	}
}
void rearele()
{
	if(rear==-1)
	{
		printf("Q is empty");
	}
	else
	{
		printf("\nrear element is %d\t",que[rear]);
	}
}
void enq(int x)
{
	if(rear==size-1)
	{
		printf("Q is full\n");
		return;
	}
	que[++rear]=x;
	if(front==-1)
	{
		front=0;
		return;
	}
}
int deq()
{
	if(front==-1)
	{
		printf("Q is empty\n");
		return 0; 
	}
	int x=que[front];
	front++;
	if(front>rear)
	{
		front=rear=-1;
	}
	return x;
}
void traverse()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",que[i]);
	}
}
void isfull()
{
	if(rear=size-1)
	{
		printf("Q is full");
	}
	else
	{
		printf("Q is not full");
	}
}
void isempty()
{
	if(front=-1)
	{
		printf("Q is empty");
	}
	else
	{
		printf("Q is not empty");
	}
}
int main()
{
	enq(4);
	enq(5);
	//traverse();
	enq(6);
	enq(7);
	//traverse();
	deq();
	//traverse();
	enq(8);
	traverse();
	//enq(9);
	//enq(10);
	//frontele();
	//rearele();
	return 0;
}
