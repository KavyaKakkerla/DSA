//THIS A PRIORITY QUEUE
//pq

#include<stdio.h>
#include<stdlib.h>
struct node *createnode(int e,int p);
void enq(int e,int p);
void deque();
void display();

struct node{
	int data;
	int priority;
	struct node* next;
	};
struct node*front=NULL;

struct node *createnode(int element,int priority)
{
	struct node*nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=element;
	nn->priority=priority;
	nn->next=NULL;
	return nn;
}

void enq(int e,int p)
{
	struct node*nn;
	struct node*temp=front;
	nn=createnode(e,p);
	if(front == NULL || p < front->priority)
	{
		nn->next=front;
		front=nn;
	}
	else
	{
		
		while(temp->next!=NULL&&temp->next->priority <= p)
		{
			temp=temp->next;
		}
		//temp->next=nn;you did mistake here by assigning first
		nn->next=temp->next;
		temp->next=nn;
	}
}

void deque()
{
	struct node*temp;
	temp=front;
	if(front == NULL)
	{
		printf("THE QUEUE IS EMPTY\n");
	
	}
	else
	{
	
		front=front->next;
		free(temp);
	}
}

void display()
{
	struct node*temp=front;
	if(temp==NULL)
	{
		printf("the queue is empty\n");
		return;
	}
	else
	{
		while(temp!=NULL)
			{
				printf("%d-%d ",temp->data,temp->priority);
				temp=temp->next;
			}
	}
	printf("\n");
}

int main()
{	int e;
	enq(1,1);
	//display();
	enq(2,2);
	enq(3,3);
	enq(4,4);
	enq(5,5);
	display();
	deque();
	display();
	return 0;
}
	
