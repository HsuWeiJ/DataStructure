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
link LinkedListDelete(link head,link target);

int main(void)
{
    link head=NULL;
    int delet=3;
    int i;
    ins(&head,1);
    ins(&head,2);
    ins(&head,3);
    ins(&head,4);
    ins(&head,5);
    link target=head;

    printf("請輸入想刪掉的數字\n");
    scanf("%d",&delet);

    for( i=0;i<5;i++)
    {
        if(target->value==delet)
        {
            head=LinkedListDelete(head,target);
            break;
        }
        else
        {
            target=target->next;
        }
        
    }
    link ptr=head;
    for( i=0;i<4;i++)
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
link LinkedListDelete(link head,link target)
{
    link ptr=head;
    if(head->value==target->value)
    {
        head=head->next;
    }
    else
    {
        while( ptr->next!=target)
            ptr=ptr->next;
        if(target->next==NULL)
        {
            ptr->next=NULL;
        }
        else
        {
            ptr->next=target->next;
        }
    }
    free(target);
    return head;
}