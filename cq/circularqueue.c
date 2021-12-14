#include<stdio.h>
#include<stdlib.h>
#define max 6

int c_queue[max];
int front=-1;
int rear=-1;

void enqueue()
	{
	int item;
	if((rear==max-1 && front==0) || (rear+1==front))
		{
		printf("queue is full");
		}
	else 
		{
		
		printf("enter an element\n");
		scanf("%d",&item);
		if(rear==-1)
		{
		front=0;
		rear=0;
		}
		else if(rear==max-1)
		rear=0;
		else
		rear++;
		c_queue[rear]=item;
	    }
	}

void dequeue()
	{
	if(rear==front)
		{
		rear=-1;
		front=-1;
		printf("queue is empty\n");
		}
	else if(front==-1)
		{
		printf("queue is empty\n");
		}
	else if(front==max-1)
		{
		front=0;	
		}
	else
		{
		front++;
		}
	}


void display()
	{
	int i,j;
	if(front==-1&&rear==-1)
		printf("queue is underflow");
	if(front>rear)
	{
	for(i=front;i<max;i++)
		printf("\t%d",c_queue[i]);
	for(j=0;i<=rear;j++)
		printf("\t%d",c_queue[i]);
	}
	else
	{
	for(i=front;i<=rear;i++)
		printf("%d",c_queue[i]);
	}
	}


void main()
{
int ch;

while(1)
{
printf("enter a choice\n 1)enqueue  2)dequeue 3)display 4)exit \n");
scanf("%d",&ch);
if(ch==1)
enqueue();
else if(ch==2)
dequeue();
else if(ch==3)
display();
else
exit(0);
}
}
