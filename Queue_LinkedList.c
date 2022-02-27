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
typedef struct list QueueNode;
typedef QueueNode * Linked_Queue;

typedef struct queue
{
    Linked_Queue head;
    Linked_Queue tail;
    int size;
}queue;
typedef queue * link;

/*--------------------
Global Variable
--------------------*/
/*--------------------
Function 
--------------------*/
void InitializeQueue(link q);
void enqueue(link q , int key);
void dequeue(link q );


int main(void)
{
    link q=(link)malloc(sizeof(queue));
    InitializeQueue(q);

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,4);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    system("pause");
    return 0;
}
void InitializeQueue(link q)
{
    q->head=NULL;
    q->tail=NULL;
    q->size=0;
}
void enqueue(link q , int key)
{
    Linked_Queue newnode = (Linked_Queue)malloc(sizeof(QueueNode));
    newnode->data=key;
    if(q->tail==NULL)
    {
        q->head=newnode;
        q->tail=newnode;
    }
    else
    {
        q->tail->next=newnode;
        q->tail=newnode;
    }
    newnode->next=NULL;
    q->size++;   
}
void dequeue(link q )
{
    if(q->head==NULL)
    {
        printf("¦î¦C¤wªÅ\n");
    }
    else
    {
        printf("%d",q->head->data);
        Linked_Queue tem =q->head;
        q->head=q->head->next;
        q->size--;
        free(tem);
    }
}