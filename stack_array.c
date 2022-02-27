#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXSTACK 2

/*--------------------
Structure
--------------------*/
/*--------------------
Global Variable
--------------------*/
int stack[MAXSTACK]={0};
int top =-1;            //stack???index
/*--------------------
Function 
--------------------*/
char IsEmpty();
int push(int data);
int pop();

int main(void)
{

    pop();
    push(1);
    push(2);
    push(3);
    pop();


    system("pause");
    return 0;
}
char IsEmpty()
{
    if(top==-1)
        return 1;
    else 
        return 0;
}
int push(int data)
{
    if(top==(MAXSTACK-1))
    {
        printf("堆疊已滿");
        return 0;
    }
    else
    {
        stack[++top]=data;
        return 1;
    }
}
int pop()
{
    if(IsEmpty())
    {
        printf("堆疊已空");
        return 0;
    }
    else
    {
        printf("\n%d",stack[top--]);
        return 1;
    }
}
