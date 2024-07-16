#include<stdio.h>
int queue[100],n,i,choice,front,rear,item;
void deletee(void);
void display(void);
void insert(void);
int main()
{
    front=-1;
    rear=-1;
    printf("enter size of queue\n");
    scanf("%d",&n);
    printf("enter \n1:delete, \n2:insert, \n3: display, \n4: exit");
    do
    {
        printf("please enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            deletee();
            break;
        }
        case 2:
        {
            insert();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("exit point\n");
            break;
        }
        default:
        {
            printf("wrong choice\n");
        }

        }
    }
    while(choice!=4);
    return 0;
}
void insert()
{
    if(rear==n-1)
    {
        printf("queue over flow\n");
    }
    else
    {
        if(front==-1)
            front=0;

        printf("enter element\n");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;

    }
}

void deletee()
{
    if(front==-1||front>rear)
    {
        printf("underflow\n");
    }
    else
    {
        printf("deleted elementt is : %d" ,queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1)
    {
        printf("\nqueue empty\n");
    }
    else
    {
        printf("elements of queue are: \n");
        for(i=front; i<=rear; i++)
        {
            printf("%d",queue[i]);
        }
    }
}


