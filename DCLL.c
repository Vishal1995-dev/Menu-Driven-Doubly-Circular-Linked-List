
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
	struct Node * prev;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void Display(PNODE Head,PNODE Tail)
{
	if(Head==NULL)
	{
		return;
	}
	do
	{
		printf("%d\t",Head->data);
		Head=Head->next;
	}
	while(Head!=Tail->next);
}

void DisplayX(PNODE Head,PNODE Tail)
{
	if(Head==NULL)
	{
		return;
	}
	do
	{
		printf("%d\t",Tail->data);
		Tail=Tail->prev;
	}
	while(Tail!=Head->prev);
}

int Count(PNODE Head,PNODE Tail)
{
	int i=0;
	if(Head==NULL)
	{
		return i;
	}
	do
	{
		i++;
		Head=Head->next;
	}
	while(Head!=Tail->next);
	return i;
}

void InsertFirst(PPNODE Head,PPNODE Tail,int value)
{
	PNODE newn = NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=value;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		newn->next=*Head;
		(*Head)->prev=newn;
		*Head=newn;
	}
	(*Head)->prev=*Tail;
	(*Tail)->next=*Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int value)
{
	PNODE newn = NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=value;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		newn->prev=*Tail;
		(*Tail)->next=newn;
		*Tail=newn;
	}
	(*Head)->prev=*Tail;
	(*Tail)->next=*Head;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int value,int pos)
{
	int cnt=Count(*Head,*Tail);
	printf("\n");
	printf("%d",cnt);
	printf("\n");
	if(pos<1 || pos>cnt+1)
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(Head,Tail,value);
	}
	else if(pos==cnt+1)
	{
		InsertLast(Head,Tail,value);
	}
	else
	{
		int i=0;
		PNODE temp=*Head;
		PNODE newn = NULL;
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=value;
		newn->next=NULL;
		newn->prev=NULL;
		
		for(i=0;i<pos-2;i++)
		{
			temp=temp->next;
			printf("\n%d\t",temp->data);
		}
		newn->next=temp->next;
		newn->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
	}
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if(*Head==NULL)
	{
		return;
	}
	if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		(*Tail)->next=(*Head)->next;
		(*Head)->next->prev=*Tail;
		free(*Head);
		*Head=(*Tail)->next;
	}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	if(*Head==NULL)
	{
		return;
	}
	if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		(*Head)->prev=(*Tail)->prev;
		(*Tail)->prev->next=*Head;
		free(*Tail);
		*Tail=(*Head)->prev;
	}
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int pos)
{
	int cnt=Count(*Head,*Tail);
	if(pos<1 || pos>cnt)
	{
		return;
	}
	if(pos==1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(pos==cnt)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		int i=0;
		PNODE temp=*Head;
		for(i=0;i<pos-2;i++)
		{
			temp=temp->next;
		}
		
		temp->next=temp->next->next;
		free(temp->next->prev);
		temp->next->prev=temp;
	}
}

int main()
{
	PNODE Head = NULL;
	PNODE Tail = NULL;
	
	int choice=1;
	int data=0;
	int pos=0;
	int ret=0;
	
	printf("Doubly Circular Linked List\n");
	while(choice)
	{
		printf("-------------------\n");
		printf("1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Display\n5.Count\n6.Delete First\n7.Delete Last\n8.Delete At Position\n9.Display Reverse\n0.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d",&data);
				InsertFirst(&Head,&Tail,data);
				break;
			case 2:
				printf("Enter data\n");
				scanf("%d",&data);
				InsertLast(&Head,&Tail,data);
				break;
			case 3:
				printf("Enter data\n");
				scanf("%d",&data);
				printf("Enter position\n");
				scanf("%d",&pos);
				InsertAtPos(&Head,&Tail,data,pos);
				break;
			case 4:
				printf("-------------------\n");
				Display(Head,Tail);
				printf("\n");
				break;
			case 5:
				ret=Count(Head,Tail);
				printf("Number of elements are : %d\n",ret);
				break;
			case 6:
				DeleteFirst(&Head,&Tail);
				break;
			case 7:
				DeleteLast(&Head,&Tail);
				break;
			case 8:
				printf("Enter position\n");
				scanf("%d",&pos);
				DeleteAtPos(&Head,&Tail,pos);
				break;
			case 9:
				printf("-------------------\n");
				DisplayX(Head,Tail);
				printf("\n");
				break;
		}
	}
return 0;
}
