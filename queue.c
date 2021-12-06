#include<stdio.h>
#include<stdlib.h>
#define max 100
void enqueue();
void dequeue();
void display();
int a[max];
int rear=-1;
int front=-1;

void enqueue()
{
 if(rear==max-1)
	{
	 printf("queue overflow\n");
	}
 else
 {
   if(front==-1)
	{
	 front+=1;
	}
	 rear+=1;
	 printf("enter the element to be inserted:");
	 scanf("%d",&a[rear]);

 }
}


void dequeue()
{
 if(front==-1 || front>rear)
	{
	 printf("queue is underflow\n");
	}
 else
	{
	 front++;
	}
}


void display()
{ 
 if(front==-1)
	{
	 printf("queue underflow");
	}
 else
	{
	 printf("\nthe queue is :");
	 for(int i=front;i<=rear;i++)
	  {
	    printf("\n%d",a[i]);
	  }
}
}

void main()
{
int ch;
while(1) 
{
printf("\n*** Queue Menu ***");
printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
printf("\n\nEnter your choice(1-4):");
scanf("%d",&ch);
switch(ch)
{
case 1: enqueue();
break;
case 2: dequeue();
break;
case 3: display();
break;
case 4: exit(0);
break;
default: printf("\nWrong Choice!!");
}
}
}



























 
