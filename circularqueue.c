#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
void insert();
int delete();
void display();
int cq[20],front=-1,rear=-1,item,ch,i;
void main(){
    while(1){
        printf("Circular Queue MENU\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:insert();
            break;
            case 2:item=delete();
            if(item!=-1){
                printf("The deleted element is:%d\n",item);
            }
            break;
            case 3:display();
            break;
            case 4:exit(0);
        }
    }
}
void insert(){
    if (front==(rear+1)%MAX){
            printf(" circular queue is full\n");
            return;
        }
    if (rear==-1&&front==-1){
        rear=0;
        front=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    printf("enter the element to be inserted:\n");
    scanf("%d",&item);
    cq[rear]=item;
    return;

}

int delete(){
    if(front==-1&&rear==-1)    {
        printf("circular queue is empty\n");
        return (-1);
    }
    item=cq[front];
    if(front==rear)    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%MAX;
    return item;
}

void display(){
    if(front==-1&&rear==-1)    {
        printf("circular queue is empty\n");
        return;
    }

    printf("CIRCULAR QUEUE\n");
    if (front<=rear){
        for (int i=front;i<=rear;i++){
            printf("%d\n",cq[i]);
        }
    }

   else{
        for(int i=front;i<=MAX-1;i++){
            printf("%d\n",cq[i]);
        }
        for (int i=0;i<=rear;i++){
            printf("%d\n",cq[i]);
        }
    }
   return;
}
