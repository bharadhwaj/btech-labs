#include <stdio.h>
#include <conio.h>
struct linked_list
{
  int number;
  struct linked_list *next;
};
typedef struct linked_list node;
void create(node *list)
{
  printf("Input a number(type -999 at end): ");
  scanf("%d", &list->number);
  if(list -> number == -999)
    list->next = NULL;
  else
  {
    list->next = (node*)malloc(sizeof(node));
    create(list->next);
  }
  return;
}
void print(node *list)
{
  printf("%d", list->number);
  if(list->next != NULL)
  {
    printf("-->");
    print(list->next);
  }
  else
    return;
}
int count(node *list)
{
  if(list->next == NULL)
    return(0);
  else
    return(1+count(list->next));
}
node* insert(node*head)
{
  node *find(node*p,int a);
  node *new; /*pointer to new node*/
  node *n1; /*pointer to node preceding key node*/
  int key;
  int x; /*new item(number) to be inserted*/
  printf("Value of new item? :");
  scanf("%d",&x);
  printf("Value of key item?(type-999 if last): ");
  scanf("%d",&key);
  if(head->number==key) /*new node is first*/
  {
    new=(node*)malloc(sizeof (node));
    new->number=x;
    new->next=head;
    head=new;
  }
  else/*find key node and insert new node*/
  { /*before the key node*/
    n1=find(head,key); /*find key node*/
    if(n1==NULL)
      printf("\nKey is not found\n");
    else /*insert new node*/
    {
      new=(node*)malloc(sizeof(node));
      new->number=x;
      new->next=n1->next;
      n1->next=new;
    }
  }
  return(head);
}
node *find(node *list,int key)
{
  if (list->next->number==key)
    return(list);
  else if(list->next->next==NULL)
    return(NULL);
  else
    return find(list->next,key);
}
node *delete(node *head)
{
  node *find(node *p, int a);
  int key;
  node *n1;
  node *p;
  printf("\nWhat is the item(number) to be deleted?: ");
  scanf("%d", &key);
  if(head->number == key)
  {
    p = head->next;
    free(head);
    head = p;
  }
  else
  {
    n1 = find(head, key);
    if(n1 == NULL)
      printf("\n Key not found \n");
    else
    {
      p = n1->next->next;
      free(n1->next);
      n1->next = p;
    }
  }
  return(head);
}
void search(node* list)
{
  int pos = 1, flag = 0,num;
  printf("Enter number to search :");
  scanf("%d", &num);
  if(list == NULL)
  {
    printf("\nNo node to search");
    return;
  }
  do
  {
    if(list->number == num)
    {
      flag = 1;
      break;
    }
    pos++;
    list = list->next;
  }
  while(list->next != NULL);

  if(flag == 1)
    printf("\nNode found at position %d", pos);
  else
    printf("\nNode not found");
}

main()
{
  int opt = 0;
  node *head;
  head = (node*) malloc(sizeof(node));
  clrscr();
  create(head);
  while(opt!=5)
  {
    printf("\n1.Add item 2.Delete item 3.Search 4.Display 5.Exit\n");
    printf("Enter option: ");
    scanf("%d", &opt);
    switch(opt)
    {
      case 1: head = insert(head);
	      break;
      case 2: head = delete(head);
	      break;
      case 3: search(head);
	      break;
      case 4: print(head);
	      break;
      case 5: return;
      default: printf("Invalid Input\n");
    }
  }
}
