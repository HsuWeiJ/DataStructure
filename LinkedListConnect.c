#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*--------------------
Structure
--------------------*/
typedef struct list
{
    int value;
    struct list *next;
}node;
typedef node * link; 
/*--------------------
Global Variable
--------------------*/
/*--------------------
Function 
--------------------*/
void ins(link * head_ref,int val);
link LinkedListConnect(link head1,link head2);
int main(void)
{
    link head1=NULL;
    link head2=NULL;
    ins(&head1,1);
    ins(&head1,2);
    ins(&head2,3);
    ins(&head2,4);

    link ptr=LinkedListConnect(head1,head2);

    for(int i=0;i<4;i++)
    {
        printf("%3d",ptr->value);
        ptr=ptr->next;
    }
        

    system("pause");
    return 0;
}
void ins(link * head_ref,int val)
{
    link ptr= * head_ref;
    link newnode=(link )malloc(sizeof(node));
    newnode->value=val;
    newnode->next=NULL;
    if(ptr!=NULL)
    {
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;
    }
    else
        * head_ref=newnode;
}
link LinkedListConnect(link head1,link head2)
{
    link ptr=head1;
    if(head1==NULL)
        return head2;
    else if(head2==NULL)
        return head1;
    else
    {
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=head2;
        return head1;
    }
}