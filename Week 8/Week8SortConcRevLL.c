#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node* NODE;
NODE getnode(){
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if (new_node==NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}

NODE insert_end(int item, NODE START){
    NODE new_end = getnode();
    new_end->value = item;
    new_end->next = NULL;
    if (START==NULL){
        return new_end;
    }
    NODE current = START;
    while (current->next!=NULL) {
        current = current->next;
    }
    current->next = new_end;
    return START;
}

NODE reverse(NODE START){
    NODE current,temp;
    current=NULL;
    while (START!=NULL){
        temp=START;
        START=START->next;
        temp->next=current;
        current=temp;
    }
    return current;
}

NODE concatenate(NODE START_1, NODE START_2){
     NODE last1;
     if (START_1==NULL && START_2==NULL){
        return NULL;
     }
     else if(START_1==NULL){
        return START_2;
     }
     else if (START_2==NULL){
        return START_1;
     }
     else{
        last1=START_1;
        while(last1->next!=NULL){
            last1=last1->next;
        }
        last1->next=START_2;
     }
     return START_1;
}

NODE sort(NODE start) {
    NODE temp1, temp2;
    temp1=start;
    while (temp1!=NULL) {
        temp2=temp1->link;
        while (temp2!=NULL) {
            if (temp1->data > temp2->data) {
                int x = temp1->data;
                temp1->data = temp2->data;
                temp2->data = x;
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
    return start;
}


void display(NODE START)
{ NODE temp;

    if(START==NULL)
    {
        printf("linked list is empty");
        return;
    }
     temp=START;
    while(temp!=NULL)
    {
        printf("%d\t",temp->value);
        temp=temp->next;
    }
}

int main(){
    NODE START_1= NULL;
    NODE START_2= NULL;
    int choice, item, pos;
    while(1){
        printf("\nMenu:\n");
        printf("1. Insert in linked list 1\n ");
        printf("2. Insert in linked list 2\n");
        printf("3. Sort in linked list 1\n");
        printf("4. Sort in linked list 2\n");
        printf("5. Reverse in linked list 1\n");
        printf("6. Reverse in linked list 2\n");
        printf("7. Concatenate the two lists\n");
        printf("8. Display LL 1\n");
        printf("9. Display LL 2\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                START_1 = insert_end(item, START_1);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                START_2 = insert_end(item, START_2);
                break;
            case 3:
                printf("Sorting LL1");
                START_1=sort(START_1);
                break;
            case 4:
                printf("Sorting LL2");
                START_2=sort(START_2);
                break;
            case 5:
                printf("LL1 being reversed");
                START_1 =reverse(START_1);
                break;
            case 6:
                printf("LL2 being reversed");
                START_2=reverse (START_2);
                break;
            case 7:
                START_1=concatenate (START_1,START_2);
                break;
            case 8:
                display(START_1);
                break;
            case 9:
                display(START_2);
                break;
            default:
                printf("Invalid choice. \n");
        }
    }
    return 0;
}
