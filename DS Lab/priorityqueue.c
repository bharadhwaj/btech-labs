#include<stdio.h>
#define MAX 256
struct priorityqueue {
	int data[MAX];
	int p[MAX];
}A;
int front = -1, rear = -1;
minheapify(int i, int n) {
	int least, temp;
	int l = 2*i+1, r = 2*i+2;
	if(A.p[l] < A.p[i] && l < n)
		least = l;
	else
		least = i;
	if(A.p[r] < A.p[least] && r < n)
		least = r;
	if(least != i) {
		temp = A.p[least];
		A.p[least] = A.p[i];
		A.p[i] = temp;
		temp = A.data[least];
		A.data[least] = A.data[i];
		A.data[i] = temp;
		minheapify(least,n);
	}
}
void enqueue() {
	int i,n,pr;
	do {
		if(front == -1)
			front++;
		printf("\n Enter the number and its priority(> 0)[Enter priority 0 to STOP]: ");
		scanf("%d %d",&n,&pr);
		if(pr > 0) {
			rear++;
			A.data[rear] = n;
			A.p[rear] = pr;
			for(i = (rear+1)/2; i >= 0; i--)
				minheapify(i,rear+1);
		}
		else
			break;
	}while(pr > 0);
}

void display() {
	int i;
	if(front != -1)
	else {
		printf("\n\n The Priority Queue is[number|priority]: \n");
		for(i = 0; i <= rear; i++)
			printf(" %d|%d -> ",A.data[i],A.p[i]);
	}
}
	
void dequeue() {
	int temp;
	if(rear == -1)
		printf("\n Queue is Empty!");
	else if(front == rear)
		front = rear = -1;
	else {
		temp = A.p[0];
		A.p[0] = A.p[rear];
		A.p[rear] = temp;
		temp = A.data[0];
		A.data[0] = A.data[rear];
		A.data[rear] = A.data[0];
		minheapify(0,rear);
		rear--;
	}
	display();
}
			
main() {
	int ch;
	do {
		printf("\n\n 1. Enqueue. \n 2. Dequeue \n 3. Display \n 4. Exit.");
		printf("\n\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("\n Invalid Entry! Try with numbers 1-4!");
		}
	}while(ch != 4);
}
