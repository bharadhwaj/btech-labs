#include<stdio.h>
#include<stdlib.h>
struct stack {
	int data;
	struct stack *next;
};
typedef struct stack stack;
struct queue {
	int data;
	struct queue *next;
};
typedef struct queue queue;
stack *head = NULL, *temps, *current;
queue *front = NULL, *rear = NULL, *temp; 
void push(int elt) {
	stack *new = (stack *) malloc (sizeof(stack));
	new->data = elt;
	if(head == NULL) {
		head = new;
		head->next = NULL;
	}
	else {
		temps = head;
		new->next = temps;
		head = new;
	}
}
void pop() {
	if (head == NULL)
		printf("\nSTACK UNDERFLOW!");
	else {
		temps = head;
		head = head->next;
		free(temps);
	}
}
void displaystack() {
	current = head;
	if (head == NULL)
		printf("\nSTACK is empty!");
	else {
		printf("\n Elements on stack are: \n\n");
		while(current != NULL) {
			printf("\n \t %d \n",current->data);
			printf("\t|____|");
			current = current->next;
		}
	}
}
void emptystack() {
	while(head != NULL) {
		pop();
		head = head->next;
	}
	displaystack();
	head = NULL;
}
void enqueue(int elt) {
	queue *new = (queue *) malloc (sizeof(queue));
	new->data = elt;
	new->next = NULL;
	if(rear == NULL) {
		rear = new;
		front = rear;
	}
	else {
		rear->next = new;
		rear = new;
	}
}
void dequeue() {
	if(front ==  NULL)
		printf("\n\n Queue is empty.");
	else {
		temp = front;
		front = front->next;
		free(temp);
	}
	printf("\n Queue is updated!");
}
void displayqueue() {
	temp = front;
	if(front == NULL)
		printf("\n Queue is empty!");
	else {
		printf("\n\n The elements in queue are: \n \t");
		while (temp != NULL) {
			printf("%d -> ",temp->data);
			temp = temp->next;
		}
	}
}
void emptyqueue() {
	if(front == NULL)
		printf("\n\n Queue is already empty.");
	else {
		while(front != NULL) {
			dequeue();
			front = front->next;
		}
	}
	displayqueue();
	front = NULL;
	rear = NULL;
}
int stacks() {
	int elt,ch;
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
		                push(elt);
   	            }while(elt != -999);
                break;
			case 2:
				pop();
				printf("\n Top element is deleted! Stack is updated!");
				displaystack();
				break;
			case 3:
				displaystack();
				break;
			case 4:
				emptystack();
				break;
			case 5:
				return 0;
			default:
				printf("\n Invalid option! Try with numbers 1-3!");
		}
	}while(ch != 5);
}
int queues() {
	int ch,elt;
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
               			enqueue(elt);
               	}while(elt != -999);
               	break;
			case 2:
				dequeue();
				displayqueue();
				break;
			case 3:
				displayqueue();
				break;
			case 4:
				emptyqueue();
				break;
			case 5:
				return 0;
			default:
				printf("\n\n Invalid option! Try with numbers 1-3!");
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
				stacks();
				break;
			case 2:
				queues();
				break;
			case 3:
				return 0;
			default:
				printf("\n\n Invalid option! Try with numbers 1-3!");
		}
	}while(ch!=3);
}
