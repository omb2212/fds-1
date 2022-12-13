#include <stdio.h>
#define SIZE 5

int q[SIZE];
int front=-1, rear=-1;
	
void enqueue(int x){
	if((rear+1)%SIZE==front){
		printf("Queue is full\n");
		return;
	}
	rear=(rear+1)%SIZE;
	q[rear]=x;
	if(front==-1) front=0;
}

int dequeue(){
	if(front==-1){
		printf("Queue is Empty !\n");
		return -1;
	}
	
	int x=q[front];
	front++;
	if(front==rear){
		front=rear=-1;
		return x;
	}else{
		front=(front+1)%SIZE;
	}
}
	

void traverse(){
	int i;
	if(front==-1){
		printf("\nQueue is Empty!\n");
	}else if(front<=rear){
		for(i=front;i<=rear;i++){
			printf("%d\t", q[i]);
		}
	}else{
		for(i=front;i<SIZE;i++){
			printf("%d\t",q[i]);
		}
		for(i=0;i<=rear;i++){
			printf("%d\t",q[i]);
		}
	}
	
}

int main(){
	enqueue(5);
	enqueue(7);
	enqueue(7);
	traverse();
	dequeue();
	dequeue();
	dequeue();
	traverse();
	enqueue(5);
	enqueue(8);
	enqueue(6);
	traverse();
	return 0;
}
