#include<stdio.h>
#include<conio.h>
#define SIZE 3
int rear=-1,front=-1,queue[20];
void main()
{
    int ch=1,option;
    clrscr();
    while(ch)
    {
        printf("Queue operations\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            qinsert();
            getch();
            clrscr();
            break;
        case 2:
            qdelete();
            getch();
            clrscr();
            break;
        case 3:
            qdisplay();
            getch();
            clrscr();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
}
qinsert()
{
    int num;
    if(rear==(SIZE-1))
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter the element to insert:");
    scanf("%d",&num);
    queue[++rear]=num;
    printf("%d is successfully inserted\n",num);
    if(front==-1)
        front++;
    return;
}
qdelete()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    if(front==rear)
    {
        printf("Deleted element:%d",queue[front]);
        front=-1;
        rear=-1;
        return;
    }
    printf("Deleted element:%d",queue[front]);
    front++;
    return;
}
qdisplay()
{
    int i;
    if(front==-1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("status of queue is\n");
    for(i=front; i<=rear; i++)
        printf("%d\t",queue[i]);
    return;
}

