#include<stdio.h>
struct node
{
int data;
struct node *link;
};
struct node *start=NULL;
int insertatbeg()
{
int x;
printf("Enter The Elements to be inserted= ");
scanf("%d",&x);
struct node *tmp;
tmp=(struct node*)malloc(sizeof(struct node));
if(start==NULL)
{
tmp->data=x;
tmp->link=NULL;
start=tmp;
printf("%d inserted at the beginning\n",x);
return start;
}
else
{
tmp->link=start;
tmp->data=x;
start=tmp;
printf("%d inserted at the beginning\n",x);
return start;
}
return 0;
}
int insertatend()
{
int x;
printf("Enter The Elements to be Inserted= ");
scanf("%d",&x);
struct node *tmp,*p;
tmp=(struct node*)malloc(sizeof(struct node));
p=start;if(start==NULL)
{tmp->link=NULL;
tmp->data=x;
start=tmp;
printf("Element Inserted at the End is %d\n",x);
return start;
}
else
{while(p->link!=NULL)
{p=p->link;}
p->link=tmp;
tmp->data=x;
tmp->link=NULL;
printf("Element Inserted at the End is %d\n",x);
return start;
}
return 0;
}
struct node *insert_pos()
{struct node *p,*tmp;
int i;
int x, pos;
printf("Enter The value to be inserted= ");
scanf("%d",&x);
printf("Enter the Position= ");
scanf("%d",&pos);
tmp=(struct node*)malloc(sizeof(struct node));
tmp->data=x;
if(pos==1)
{tmp->link=start;
start=tmp;
return start;
}
p=start;
for(i=1;i<pos-1&&p!=NULL;i++)
p=p->link;
if(p==NULL)
printf("There are less than %d elements",pos);else
{tmp->link=p->link;
p->link=tmp;
}
return start;
}
void *addbefore()
{int elements,item;
struct node *tmp,*p;
printf("Enter the elements to be sorted= ");
scanf("%d",&elements);
printf("Enter the value before which you want to insert a node= ");
scanf("%d",&item);
if(start==NULL)
{printf("List is Empty");}
if(start->link==item)
{tmp=(struct node*)malloc(sizeof(struct node));
tmp->data=elements;
tmp->link=start;
start=tmp;
return start;
}
p=start;
while(p->link!=NULL)
{if
(p->link->data==item)
{tmp=(struct node*)malloc(sizeof(struct node));
tmp->data=elements;
tmp->link=p->link;
p->link=tmp;
return start;
}
p=p->link;
}
printf("%d not present in the list", item);
return start;
}
void *addafter()
{int elements,item;struct node *tmp,*p;
printf("Enter the elements to be sorted= ");
scanf("%d",&elements);
printf("Enter the value after which you want to insert a node= ");
scanf("%d",&item);
p=start;
while(p!=NULL)
{if
(p->data==item)
{tmp=(struct node*)malloc(sizeof(struct node));
tmp->data=elements;
tmp->link=p->link;
p->link=tmp;
return start;
}
p=p->link;
}
printf("%d not present in the list",item);
return start;
}
int deleteatbeg()
{struct node *p;
if(start==NULL)
{printf("LIST IS EMPTY\n");
return start;
}
else if(start->link==NULL)
{p=start;
printf("%d has been deleted from end\n",p->data);
free(p);
start=NULL;
return start;
}
else
{printf("Element %d has been deleted from the beginning\n",start->data);
p=start;
start=start->link;
free(p);
return start;
}return 0;
}
void *deleteatend()
{struct node *p;
if(start==NULL)
{printf("LIST IS EMPTY\n");
return start;
}
else if(start->link==NULL)
{p=start;
printf("%d has been deleted from end\n",p->data);
free(p);
start=NULL;
return start;
}
else
{p=start;
while(p->link->link!=NULL)
{p=p->link;}
printf("Element %d has been deleted from the End\n",p->link->data);
free(p->link);
p->link=NULL;
}
}
struct node *del_inbetween()
{struct node *tmp, *p;
int element;
printf("Enter the elements to be deleted= ");
scanf("%d",&element);
if(start==NULL)
{printf("List is Empty");
return start;
}
if(start->data==element)
{tmp=start;start=start->link;
free(tmp);
return start;
}
p=start;
while(p->link!=NULL)
{if
(p->link->data==element)
{tmp=p->link;
p->link=tmp->link;
free(tmp);
return start;
}
p=p->link;
}
printf("Element %d not found",element);
return start;
}
int delete_pos()
{struct node *tmp,*p;
int pos,i;
printf("Enter the position to be deleted= ");
scanf("%d",&pos);
if(start==NULL)
{printf("List is Empty");
return start;
}
if(pos==1)
{p=start;
free(p);
start=start->link;
return start;
}
p=start;
for(i=0;i<pos-2&&p!=NULL;i++)
{p=p->link;
}
if(p==NULL)
{printf("There are less than %d elements",pos);
}
else
{tmp=p->link;
p->link=tmp->link;
printf("Elements %d deleted from position %d \n",tmp->data,pos);
free(tmp);
}
}
void count()
{struct node *p;
int cnt=0;
p=start;
while(p!=NULL)
{p=p->link;
cnt++;
}
printf("Number of elements are %d\n",cnt);
}
void search()
{struct node *p;
int pos=1, element;
printf("Enter the elements to be search= ");
scanf("%d",&element);
p=start;
while(p!=NULL)
{if
(p->data==element)
{printf("Item %d found at position %d \n",element,pos);
return;
}
p=p->link;
pos++;
}
printf("Item %d not found at position %d\n",element);
}
int reverse()
{struct node *prev,*ptr,*next;
prev=NULL;
ptr=start;
while(ptr!=NULL)
{
next=ptr->link;
ptr->link=prev;
prev=ptr;
ptr=next;
}
start=prev;
return start;
}
void display()
{struct node *p;
if(start==NULL)
{printf("LIST IS EMPTY\n");
return;
}
p=start;
while(p!=NULL)
{printf("%d\t",p->data);
p=p->link;
}
printf("\n");
}
void main()
{int choice;
printf("1.Insert at beginning\n");
printf("2.Insert at end\n");
printf("3.Insert at a given point\n");
printf("4.Insert before a node\n");
printf("5.Insert after a node\n");
printf("6.Delete at beginning\n");
printf("7.Delete at end\n");
printf("8.Deletion at a given position\n");printf("9.Deletion in between the nodes\n");
printf("10.Count\n");
printf("11.Search\n");
printf("12.Reversal\n");
printf("13.Display\n");
printf("14.Quit\n");
while(1)
{printf("Enter your choice = ");
scanf("%d",&choice);
switch(choice)
{case 1: {
insertatbeg();
break;
}
case 2: {
insertatend();
break;
}
case 3: {
*insert_pos();
break;
}
case 4: {
*addbefore();
break;
}
case 5: {
*addafter();
break;
}
case 6: {
deleteatbeg();
break;
}
case 7: {
deleteatend();
break;
}
case 8: {
delete_pos();
break;
}
case 9: {
*del_inbetween();break;
}
case 10:{
count();
break;
}
case 11:{
search();
break;
}
case 12:{
reverse();
break;
}
case 13:{
display();
break;
}
case 14: exit(1);
};
printf("\n");
}
}

