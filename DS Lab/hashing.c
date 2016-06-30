#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[10][20];

struct node {
	char data[20];
	struct node *next;
};
typedef struct node node;
node *head[10];

void display(int ch) {
	int i;
	if(ch == 1) {
	printf("Bucket \t String\n\n");
		for(i = 0; i < 10; i++)
			printf("%d \t %s \n",i,str[i]);
	}
	if(ch == 2) {
		printf("Bucket \t String\n\n");
		for(i = 0; i < 10; i++) {
			printf("%d \t",i);
			node *temp = head[i];
			while(temp != NULL) {
				printf("%s -> ",temp->data);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}
void openhashinginsert() {
	int j,sum,hash;
	char temp[20];
	do {
		printf("\n\n Enter the string(STOP to stop): ");
		node *new = (node*) malloc (sizeof(node));
		scanf("%s",new->data);
		new->next = NULL;
		strcpy(temp,new->data);
		if(strcmp(temp,"STOP") != 0) {
			for(j = 0,sum=0; temp[j] != '\0'; j++)
				sum = sum+(int)temp[j];
			hash = sum%10;
			node *t = head[hash];
			if(strcmp(t->data,"NULL") == 0)
				head[hash] = new;
			else {	
				while(t->next != NULL)
					t = t->next;
				t->next = new;
			}
			new->next = NULL;
		}
	}while(strcmp(temp,"STOP") != 0);
	display(2);
}

void closedhashinginsert() {
	int n, i, j, k, hash, A[10], sum=0;
	char temp[20];
	do {
		printf("\n Enter the strings(STOP to stop): ");
		scanf(" %s",temp);
		if(strcmp(temp,"STOP") != 0) {
			for(j = 0,sum=0; temp[j] != '\0'; j++)
				sum = sum+(int)temp[j];
			hash = sum%10;
			for(k = 1; strcmp(str[hash],"NULL") != 0; k++)
				hash = (sum+k)%10;
			strcpy(str[hash],temp);
		}
	}while(strcmp(temp,"STOP") != 0);
	display(1);
	return;
}

void openhashingsearch() {
	int j,sum,hash;
	char temp[20];
	printf("\n\n Enter the string to be searched: ");
	scanf("%s",temp);
	for(j = 0,sum=0; temp[j] != '\0'; j++)
		sum = sum+(int)temp[j];
	hash = sum%10;
	node *t = head[hash];
	if(strcmp(t->data,"NULL") == 0) 
		printf("\n\n Element is not in the hash table!");
	else {
		if(strcmp(t->data,temp) == 0)
			printf("\n\n Element found at position %d !",hash);
		else
			printf("\n\n Element is not in the hash table!");
	}
}

void closedhashingsearch() {
	char temp[20];
	int j,hash,hash1,sum;
	printf("\n Enter the string to be searched: ");
	scanf("%s",temp);
	for(j = 0,sum=0; temp[j] != '\0'; j++)
		sum = sum+(int)temp[j];
	hash = sum%10;
	hash1 = hash;
	while(strcmp(str[hash],temp) != 0){
		hash = (hash+1)%10;
		if(hash == hash1) {
			printf("\n\n Element searched is not in the Hash table!");
			break;
		}
	}
	if(strcmp(str[hash],temp) == 0)
		printf("\n\n Element is found at position %d !",hash);
}

void closedhashing() {
	int ch;
	do {
		printf("\n\n 1. Insert. \n 2. Search. \n 3. Back.");
		printf("\n\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				closedhashinginsert();
				break;
			case 2:
				closedhashingsearch();
				break;
			case 3:
				break;
			default:
				printf("\n\n Invalid entry! Try with numbers 1-3!");
		}
	}while(ch != 3);
}

void openhashing() {
	int ch;
	do {
		printf("\n\n 1. Insert. \n 2. Search. \n 3. Back.");
		printf("\n\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				openhashinginsert();
				break;
			case 2:
				openhashingsearch();
				break;
			case 3:
				break;
			default:
				printf("\n\n Invalid entry! Try with numbers 1-3!");
		}
	}while(ch != 3);
}

main() {
	int ch,i;
	for(i = 0; i < 10; i++) {
		strcpy(str[i],"NULL");
		node *n = (node*) malloc (sizeof(node));
		strcpy(n->data,"NULL");
		head[i] = n;
	}
	
	do {
		printf("\n\n 1. Closed Hashing. \n 2. Open Hashing. \n 3. Exit");
		printf("\n\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				closedhashing();
				break;
			case 2:
				openhashing();
				break;
			case 3:
				break;
			default:
				printf("\n\n Invalid entry! Try with numbers 1-3!");
		}
	}while(ch != 3);
}
