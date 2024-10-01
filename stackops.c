#include<conio.h>
#include<stdio.h>
#define MAX 5
int s[10],top=-1,i,item,ch;
void main(){
    while ()
    {
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n5.ISEMPTY\n6.ISFULL\n7.TOP\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        swich(ch){
            case 1:push();
            break;
            case 2:item=pop();
            if(item!=-1){
                printf("POPPED ELEMENT=%d",item);
            }
            break;
            case 3:display();
            break;
            case 5:ISEMPTY();
            break;
            case 6:ISFULL();
            break;
            case 7:TOP();
            break;
            case 4:exit(0);}
        getch()
    }
}
void push(){
    if(top=MAX-1){
        printf("STACK OVERFLOW");
        return;
    }
    printf("Enter element to be pushed:\n");
    scanf("%d",&item);
    top=top+1;
    s[top]=item;
}
int pop(){
    if(top==-1){
        printf("STACK underflow");
        return -1;
    }
    item=s[top];
    top=top-1;
    return item;
}
void display(){
    if(top==-1){
        printf("Stack is Empty");
        return;
    }
    printf("Stack Contents is\n");
    for(i=top;i>=0,i--){
        printf("Element is %d",s[i])
    }
}
void ISEMPTY(){
    if(top==-1){
        printf("Stack is Empty");
        return;}
}
void ISFULL(){
    if(top=MAX-1){
        printf("Stack is full");
        return;}
}
void TOP(){
    printf("Topmost element is: %d",s[top]);
    return;
}
