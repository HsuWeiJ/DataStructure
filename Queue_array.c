#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXQUEUE 5
/*--------------------
Structure
--------------------*/
/*--------------------
Global Variable
--------------------*/
int front=0 ,end=0;
int queue[MAXQUEUE]={0};
/*--------------------
Function 
--------------------*/
char IsEmpty();
void enqueue(int data);
void dequeue ();
int main(void)
{
    enqueue(1);
    enqueue(6);
    enqueue(12);
    dequeue ();
    dequeue ();
    dequeue ();
    enqueue(12);
    enqueue(12);
    enqueue(12);
    enqueue(12);
    enqueue(12);

    system("pause");
    return 0;
}
char IsEmpty()
{
    if(((end-front)% MAXQUEUE)==0)
        return 1;
    else 
        return 0;
}
void enqueue(int data)
{
    if(((end-front+1)% MAXQUEUE) != 0)
    {
        queue[(end++)% MAXQUEUE]=data;
    }
    else
    {
        printf("序列已滿");
    }
}

void dequeue ()
{
    if(IsEmpty())
    {
        printf("序列已空");
    }
    else
    {
        int tem=queue[(front++) % MAXQUEUE];
        printf("\n%d",tem);
    }
}