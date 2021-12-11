#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;
void insert_at_begin(int);
void insert_at_loc(int,int);
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_from_loc(int);
void delete_from_end();
int count = 0;

int main () {
  int ch, data,loc;
  char choice;

  do {
    printf("1. Insert an element at the beginning of linked list.\n");
    printf("2. Insert an element at a given position in the linked list.\n");
    printf("3. Insert an element at the end of linked list.\n");
    printf("4. Traverse linked list.\n");
    printf("5. Delete an element from beginning.\n");
    printf("6. Delete an element from a given location from the  linked list.\n");
    printf("7. Delete an element from end.\n");
    

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_begin(data);
    break;
    case 2:
      printf("Enter the location \n");
      scanf("%d",&loc);
      printf("enter the value \n");
      scanf("%d",&data);
      insert_at_loc(loc,data);
    
    break;
    case 3:
      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_end(data);
    break;
    case 4:
      traverse();
    break;
    case 5:
      delete_from_begin();
    break;
    case 6:
    printf("Enter the location \n");
      scanf("%d",&loc);
      delete_from_loc(loc);
    break;
    case 7:
      delete_from_end();
    break;
    default :
      printf("Please enter valid input.\n");
    }
printf("Do you want to continue(y/n) \n");
scanf("%s",&choice);
}while(choice=='Y'||choice=='y');
}


void insert_at_begin(int x) {
  struct node *t;

  t = (struct node*)malloc(sizeof(struct node));
  t->data = x;
  count++;

  if (start == NULL) {
    start = t;
    start->next = NULL;
    return;
  }

  t->next = start;
  start = t;
}

void insert_at_loc(int pos,int x)
{
 struct node *t,*temp=start;
 int i=1;

  t = (struct node*)malloc(sizeof(struct node));
  t->data = x;
  count++;
while(i<pos-1)
{
temp=temp->next;
i++;
}
t->next=temp->next;
temp->next=t;

}

void insert_at_end(int x) {
  struct node *t, *temp;

  t = (struct node*)malloc(sizeof(struct node));
  t->data = x;
  count++;

  if (start == NULL) {
    start = t;
    start->next = NULL;
    return;
  }

  temp = start;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = t;
  t->next   = NULL;
}

void traverse() {
  struct node *t;

  t = start;

  if (t == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  printf("There are %d elements in linked list.\n", count);

  while (t->next != NULL) {
    printf("%d\n", t->data);
    t = t->next;
  }
  printf("%d\n", t->data); // Print last node
}

void delete_from_begin() {
  struct node *t;
  int n;

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  n = start->data;
  t = start->next;
  free(start);
  start = t;
  count--;

  printf("%d deleted from the beginning successfully.\n", n);
}

void delete_from_loc(int pos){
  struct node *t=start,*temp;
  int i=1,n;
  

 while(i<pos-1){
   t=t->next;
   i++;
 }
  temp=t->next;
  n = t->data;
  t->next = temp->next;
  free(temp);

}

void delete_from_end() {
  struct node *t, *u;
  int n;

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  count--;

  if (start->next == NULL) {
    n = start->data;
    free(start);
    start = NULL;
    printf("%d deleted from end successfully.\n", n);
    return;
  }

  t = start;

  while (t->next != NULL) {
    u = t;
    t = t->next;
  }

  n = t->data;
  u->next = NULL;
  free(t);

  printf("%d deleted from end successfully.\n", n);
}