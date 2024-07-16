#include<stdio.h>
int stack[100],n,i,choice,top,item;
void pop(void);
void display(void);
void push(void);
int main()
{
  top=-1;
  printf("enter size of stack: ");
  scanf("%d",&n);
  printf("enter \n1:pop,\n2:push,\n3:display,\n4:exit\n");
  do
  {
    printf("enter your choice:  \n ");
    scanf("%d",&choice);
    switch(choice)
     {
        case 1: {
                      pop();
                      break;
                     }
        case 2: {
                      push();
                      break;
                     }
        case 3:  {
                      display();
                      break;
                     }
        case 4:  {
                      printf("exit point");
                      break;
                      }
       default: {
                     printf("wrong choice");
                    }
     }
   }while(choice!=4);
 return 0;
}

  void pop()
 {
   if(top==-1)
   {
     printf("stack underflow \n");
   }
  else
   {
     printf(" poped element is: %d",stack[top]);
     top--;
   }
 }

 void push()
 {
   if(top==n-1)
   {
     printf("stack over flow \n");
   }
  else
  {
    top++;
    printf(" enter item: \n");
  scanf("%d",&stack[top]);
  }
 }

 void display()
  {
   if(top>=0)
   {
     printf("elements in stack are: \n");
     for(i=top;i>=0;i--)
     printf(" %d" ,stack[i]);}
   else
    printf("stack empty");
   }


