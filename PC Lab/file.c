#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
struct record
{
	int rollno;
	char name[32];
};
typedef struct record record;
struct node
{
	int rollno;
	char name[32];
	struct node *next;
};
typedef struct node node;
node *records = NULL;
int nrecords = 0;
void insert(record r)
{
	node *temp;
	node *new = (node*) malloc(sizeof(node));
	new->rollno = r.rollno;
	strcpy(new->name, r.name);	
	new->next = NULL;
	if(records == NULL)
		records = new;
	else
	{
		temp = records;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
void view()
{
	node *temp = records;
	if(temp == NULL)
		printf("No records found\n");
	else
	{
		printf("\nRecords:\n");
		printf("Roll No | Name\n");
		while(temp != NULL)
		{
			printf("%7d   %s\n", temp->rollno, temp->name);
			temp = temp->next;
		}
	}
}
node* search(int rollno)
{
	node *temp = records;
	while(temp != NULL)
	{
		if(temp->rollno == rollno)
			return temp;
		temp = temp->next;
	}
	return 0;
}

void sort()
{
	node *jtemp;
	int i;
	record temp;
	if(records == NULL)
		printf("No records to sort\n");
	else if(records->next == NULL)
		return;
	else
	{
		for(i = 0; i < nrecords; i++)
		{
			jtemp = records;
			while(jtemp->next != NULL)
			{
				if(jtemp->rollno > jtemp->next->rollno) 
				{
					temp.rollno = jtemp->rollno;
					strcpy(temp.name, jtemp->name);
                    			jtemp->rollno = jtemp->next->rollno;
					strcpy(jtemp->name, jtemp->next->name);
                    			jtemp->next->rollno = temp.rollno;
					strcpy(jtemp->next->name, temp.name);
				}
				jtemp = jtemp->next;
			}
		}
	}
	view();
}

void delete(int rollno)
{
	node *temp, *prev;
	if(records == NULL)
	{
		printf("Error: No records found\n");
		return;
	}
	if(records->rollno == rollno)
	{
		printf("\n Roll Number deleted.");
		temp = records;
		records = records->next;
		nrecords -= 1;
		free(temp);
	}
	else
	{
		temp = search(rollno);
		if(temp == 0)
		{
			printf("No matching record found.\n");
			return;
		}
		prev = records;
		while(prev->next != temp)
			prev = prev->next;
		prev->next = temp->next;
		nrecords -= 1;
		free(temp);
	}
	view();
}
void updatefile(char fname[MAX])
{
	FILE *file = fopen(fname, "w");
	record r;
	node *temp = records;
	fwrite(&nrecords, sizeof(nrecords), 1, file);
	while(temp != NULL)
	{
		r.rollno = temp->rollno;
		strcpy(r.name, temp->name);
		fwrite(&r, sizeof(r), 1, file);
		temp = temp->next;
	}
	fclose(file);
}
int main()
{
	int opt, opt1, i;
	FILE *file;
	node *ntemp;
	char fname[MAX];
	int rollno;
	record temp;
	printf("Enter the filename: ");
		scanf("%s", fname);
	file = fopen(fname, "r");
	if(file == NULL)
	{
        	printf("File not found. Creating new file\n");
		file = fopen(fname, "w+");
		if(file == NULL)
		{
	    		printf("Error: Couldn't create file\n");
            		return 1;
        	}
    	}
    	else
    	{
	    	fread(&nrecords, sizeof(nrecords), 1, file);
	    	printf("Read %d records\n", nrecords);
	    	for(i = 0; i< nrecords; i++)
	    	{
		    	fread(&temp, sizeof(temp), 1, file);
		    	insert(temp);
	    	}
    	}
	fclose(file);
    	do
    	{
		printf("\nOperations: \n-------------\n");
        	printf("\n 1.View \n 2.Search \n 3.Insert \n 4.Delete \n 5.Update \n 6.Sort \n 7.Exit \n");
		printf("Enter your choice(1-7): ");
		scanf("%d", &opt);
		if(opt == 1)
	    		view();
        	if(opt == 2)
        	{
			if(records == NULL)
				printf("\n No records found to search.\n");
			else
			{
				printf("\n Enter roll no. to search: ");
				scanf("%d", &rollno);
				ntemp = search(rollno);
				if(ntemp == 0)
					printf("No matching record found.\n");
				else
					printf("Matching name: %s\n", ntemp->name);
			}
		}
		if(opt == 3)
		{
			do
			{
				printf("Enter roll no. and name: ");
				scanf("%d %s", &temp.rollno, temp.name);
				if(search(temp.rollno) == NULL)
				{
					insert(temp);
					nrecords += 1;
				}
				else
					printf("\n Roll number already inserted. Try with another roll number.");
				printf("\n Want to Insert any other number? Yes: 1 , No: 0? \n");
				scanf("%d",&opt1);
			}while(opt1 != 0);
		}
    		if(opt == 4) 
    		{
    			printf("Enter roll no. of record to delete: ");
			scanf("%d", &rollno);
	    		delete(rollno);
    		}
		if(opt == 5)
		{
			printf("Enter roll no. of record to update: ");
			scanf("%d", &rollno);
			ntemp = search(rollno);
			if(ntemp == 0)
				printf("No matching record found\n");
			else
			{
				printf("Enter new name:");
				scanf("%s", (ntemp->name));
				printf("Record updated.\n");
			}
			view();
		}
		if(opt == 6)
			sort();
    	}while(opt != 7);
    	updatefile(fname);
    	return 0;
}
