#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*--------------------
Structure
--------------------*/
struct list
{
    int data;
    struct list * next;
};
typedef struct list stack;
typedef stack * Linked_Stack;


/*--------------------
Global Variable
--------------------*/

/*--------------------
Function 
--------------------*/

char IsEmpty();
Linked_Stack push(Linked_Stack * top_ref,int data);
int pop(Linked_Stack * top_ref);

int main(void)
{
    Linked_Stack top=NULL;
    push(&top,1);
    push(&top,2);
    pop(&top);
    pop(&top);
    pop(&top);

    system("pause");
    return 0;
}
char IsEmpty(Linked_Stack * top_ref)
{
    if(*top_ref==NULL)
        return 1;
    else
        return 0;
}
Linked_Stack push(Linked_Stack * top_ref ,int data)
{
    Linked_Stack newnode = (Linked_Stack)malloc(sizeof(stack));
    newnode->data=data;
    newnode->next= *top_ref;
    *top_ref=newnode;
}
int pop(Linked_Stack * top_ref)
{
    if(IsEmpty(top_ref))
    {
        printf("°ïÅ|¤wªÅ");
        return 0;
    }
    else
    {
        printf("\n%d",(*top_ref)->data);
        Linked_Stack tem;
        tem=*top_ref;
        *top_ref=(*top_ref)->next;
        free(tem);
        return 1;
    }
}
