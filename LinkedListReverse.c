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
link LinkedListReverse(link head);

int main(void)
{
    link head=NULL;
    ins(&head,1);
    ins(&head,2);
    ins(&head,3);
    ins(&head,4);
    ins(&head,5);

    link newhead=LinkedListReverse(head);
    for(int i=0;i<5;i++)
    {
        printf("%3d",newhead->value);
        newhead=newhead->next;
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
link LinkedListReverse(link head)
{
    link rev=NULL,traversal=head;
    link ptr;
    while(traversal!=NULL)
    {
        ptr=traversal;
        traversal=traversal->next;
        ptr->next=rev;
        rev=ptr;
    }
    return rev;
}