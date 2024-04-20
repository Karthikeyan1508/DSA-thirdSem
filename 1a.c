#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 3

int stack[SIZE];
int push(int);
int pop(int);
void display(int);
void main()
{
    int top=-1,option;
    clrscr();
    while(1)
    {
        printf("\nStack operations\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            top=push(top);
            getch();
            clrscr();
            break;
        case 2:
            top=pop(top);
            getch();
            clrscr();
            break;
        case 3:
            display(top);
            getch();
            clrscr();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
int push(int top)
{
    int item;
    if(top==(SIZE-1))
    {
        printf("Stack is full\n");
        return top;
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d",&item);
        stack[++top]=item;
        printf("%d is successfully pushed\n",item);
        return top;
    }

}
int pop(int top)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return top;
    }
    printf("%d is successfully popped\n",stack[top]);
    top--;
    return top;
}
void display(int top)
{
    int i;
    if(top==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Status of stack\n");
        for(i=top; i>=0; i--)
            printf(" %d\n",stack[i]);
    }
}
