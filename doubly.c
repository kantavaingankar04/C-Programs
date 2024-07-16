
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
    struct node *prev;
    struct node *next;
};
struct node *start=NULL;

void insertatbeg()
{
    struct node *tmp;
    int x;
    printf("Enter element to be inserted :");
    scanf("%d",&x);
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        tmp->data=x;
        tmp->prev=NULL;
        start=tmp;
        printf("%d Inserted sucessfully",x);
        return;
    }
    else
    {
        tmp->data=x;
        tmp->prev=NULL;
        tmp->next=start;
        start->prev=tmp;
        start=tmp;
        printf("%d Inserted sucessfully",x);
        return;

    }
}

void insertAtEnd()
{
    struct node *p,*tmp;
    int x;
    printf("Enter element to be inserted :");
    scanf("%d",&x);
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        tmp->data=x;
        tmp->prev=NULL;
        tmp->next=NULL;
        start=tmp;
        printf("%d Inserted sucessfully",x);
        return;
    }
    else
    {
    	while (p->next!=NULL)
	    p=p->next;
        tmp->data=x;
        tmp->next=NULL;
        tmp->prev=p;
        p->next=tmp;
        printf("%d Inserted sucessfully",x);
        return;
    }
}
void delBeg()
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    if(start->next=NULL)
	{
    p=start;
    printf("Element %d deleted",p->data);
    start=NULL;
    free(p);
    return;
}
else
{
	printf("Element %d deleted",start->data);
	p=start;
	p->next->prev=NULL;
	start=p->next;
	free(p);
	return;
}
}
void delEnd()
{
    struct node *p;
    if(start==NULL)
    {printf("List is empty");}
    return;
    if(start->next==NULL)
    {
        p=start;
        printf("%d Deleted",p->data);
        start=NULL;
        free(p);
    p=start;
    return;
}
    else
    {
    	while(p->next!=NULL)
    	p=p->next;
    	printf("Element %d deleted",p->next->data);
    	free(p->next);
    	return;
	}
	p->next=NULL;
}
void display()
{
    struct node *p;
    if(start==NULL)
    {
        printf("\tList is empty");
        return;
    }
    else
	{
		p=start;
		while(p!=NULL)
		{printf("%d\t",p->data);
		p=p->next;
		return;
		}
	}
}
int main()
{
    int choice;
    printf("1: insert at beginning\n2: insert at end\n3: delete first element\n4: delete last element\n5: Display");
    printf("\n0.Exit Program\n");
    while(1)
    {
        printf("\nenter choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("\tProgram Exited");
                return 0;
            break;
            case 1:
                insertatbeg();
            break;
            case 2:
                insertAtEnd();
            break;
            case 3:
                delBeg();
            break;
            case 4:
                delEnd();
            break;
            case 5:
                display();
            break;
            default:
                printf("invalid choice\n");
            break;
        }
    }
    return 0;
}
