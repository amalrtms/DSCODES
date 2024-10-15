#include <stdio.h>



int front=-1, rear=-1, i, queue[10], ch, item;
#define MAX 3
void insert();
int delete();
void display();

void main()
{   printf("AMAL ROY USN 1BM23CS025 \n");
    while (1)
    {
        printf(" 1. INSERT \n 2. DELETE \n 3. DISPLAY \n 4. EXIT \n ");
        printf("enter your choice \n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert();
                    break;
            case 2: item=delete();
                    if (item!=-1)
                    {
                        printf("deleted item is:%d\n", item);
                    } break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
    }
}

void insert()
{
    if (rear==MAX-1)
    {
        printf("queue is full.\n");
        return;
    }
    printf("enter element to be inserted: \n");
    scanf("%d",&item);
    if (rear ==-1 && front ==-1)
    {
        rear=0;
        front =0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=item;
    return;
}

int delete()
{
    if (front ==-1 && rear==-1)
    {
        printf("queue is empty.\n");
        return -1;
    }
    item=queue[front];

    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=front+1;
    }
    return item;
}

void display()
{
    if (front==-1 && rear==-1)
    {
        printf("queue is empty.\n");
        return;
    }
    printf("queue: \n");
    for (i=front;i<=MAX-1;i++)
    {
        printf("%d  ", queue[i]);
    }
    printf("\n");
    return;
}
