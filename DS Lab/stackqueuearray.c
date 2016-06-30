#include<stdio.h>
#define MAX 256
int top,front,rear;
int push(int A[], int elt) {
	if(top == MAX-1) {
		printf("\n Stack is Full! No more elements can be inserted!");
		return 0;
	}
	else {
	top= top+1;
	A[top] = elt;
	}
	return top;
}

int pop(int A[]) {
	int temp;
	if(top == -1) {
		printf("\n The stack is empty!");
		return 0;
	}
	else {
		temp = A[top];
		top = top-1;
	}
	return temp;
	return top;
}
void displaystack(int A[]) {
	int i;
	if(top == -1) 
		printf("\n Stack is empty.");
	else {
		printf("\n The elements of the stack are: \n");
		for(i = top; i >= 0; i--) {
			printf("\n \t %d \n",A[i]);
			printf("\t|____|");
		}
	}
}
void emptystack(int A[]) {
	top=-1;
	displaystack(A);
}
void enqueue(int A[], int elt) {
	if(rear == MAX-1) {
		printf("\n Queue is Full! No more elements can be inserted!");
		return 0;
	}
	else {
		if(front == -1) {
			rear = 0;
			front = 0;
		}
		else {
			rear = rear +1;
			A[rear] = elt;
		}
	}
}

int dequeue(int A[]) {
	int temp;
	if(front == -1) {
		printf("\n The queue is empty!");
		return 0;
	}
	else {
		temp = A[front];
		front = front+1;
	}
	return temp;
	return front;
	return rear;
}
void displayqueue(int A[]) {
	int i;
	if(front == -1) 
		printf("\n Queue is empty.");
	else if (front == rear) {
		front=-1;
		rear= -1;
	}
	else {
		printf("\n The elements of the queue are: ");
		for(i = front; i <= rear; i++)
			printf("%d -> ",A[i]);
	}
}
void emptyqueue(int A[]) {
	front= -1;
	rear= -1;
	displayqueue(A);
}
int queue() {
    int ch,queue[MAX],elt;
    front = -1;
    rear = -1;
    char c;
    do {
    	printf("\n\n\n Queue Operations: ");
    	printf("\n\n 1. Insert into queue.");
    	printf("\n 2. Delete from queue.");
    	printf("\n 3. Display elements of queue.");
    	printf("\n 4. Empty queue.");
    	printf("\n 5. Back.");
    	printf("\n Enter the action to be performed: ");
    	scanf("%d",&ch);
        switch(ch) {
            case 1:
            	do {
                	printf("\n Enter the element to be inserted(-999 to stop): ");
                	scanf("%d",&elt);
                	if(elt != -999)
               			enqueue(queue,elt);
               	}while(elt != -999);
                break;
            case 2:
                dequeue(queue);
                printf("\n Queue is updated!");
                displayqueue(queue);
                break;
            case 3:
            	displayqueue(queue);
            	break;
            case 4:
            	emptyqueue(queue);
            	break;
            case 5:
            	return 0;
            default:
            	printf("\n Option is invalid! Try with numbers 1-5!");
        }
    }while(ch != 5);
}
int stack() {
    int ch,stack[MAX],elt;
    top = -1;
    char c;
    do {
    	printf("\n\n\n Stack Operations: ");
    	printf("\n\n 1. Insert into Stack.");
    	printf("\n 2. Delete from Stack.");
    	printf("\n 3. Display elements of Stack");
    	printf("\n 4. Empty stack.");
    	printf("\n 5. Back.");
    	printf("\n Enter the action to be performed: ");
    	scanf("%d",&ch);
        switch(ch) {
            case 1:
            	do {
    	        	printf("\n Enter the element to be inserted(-999 to stop): ");
    	            scanf("%d",&elt);
    	            if(elt != -999)
		                push(stack,elt);
   	            }while(elt != -999);
                break;
            case 2:
                pop(stack);
                printf("\n Top element is deleted! Stack is updated!");
                displaystack(stack);
                break;
            case 3:
            	displaystack(stack);
            	break;
            case 4:
            	emptystack(stack);
            	break;
            case 5:
            	return 0;
            default:
            	printf("\n Option is invalid! Try with numbers 1-5!");
        }
    }while(ch != 5);
}
main() {
	int ch;
	do {
		printf("\n\n 1. Implementation of Stack.");
		printf("\n 2. Implementation of Queue.");
		printf("\n 3. Exit.");
		printf("\n\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				stack();
				break;
			case 2:
				queue();
				break;
			case 3:
				return 0;
			default:
				printf("\n\n Invalid option! Try with numbers 1-3!");
		}
	}while(ch!=3);
}
