#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node node;
node *start = NULL;
node *new1, *curr, *temp;

void create();
void display();
void insertstart();
void insertposition();
void insertend();
void deletestart();
void deletepos();
void deleteend();

void main() {
    int ch;
    while (1) {
        printf("\n1. Create \n2. Display \n3. Insert at Beginning \n4. Insert at Position \n5. Insert at End \n6. Delete from Beginning \n7. Delete at Position \n8. Delete at End \n9. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create();
                break;
            case 2: display();
                break;
            case 3: insertstart();
                break;
            case 4: insertposition();
                break;
            case 5: insertend();
                break;
            case 6: deletestart();
                break;
            case 7: deletepos();
                break;
            case 8: deleteend();
                break;
            case 9: exit(0);
        }
    }
}

void create() {
    char ch;
    do {
        new1 = (node*)malloc(sizeof(node));
        printf("\nEnter Value: ");
        scanf("%d", &new1->data);
        if (start == NULL) {
            start = new1;
            new1->link = start;
        } else {
            curr = start;
            while (curr->link != start) {
                curr = curr->link;
            }
            curr->link = new1;
            new1->link = start;
        }
        printf("Do You Want to Add an Element (Y/N)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void display() {
    if (start == NULL) {
        printf("\nLinked List is Empty.");
        return;
    }
    temp = start;
    printf("\nElements in Circular Linked List: \n");
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != start);
    printf("\n");
}

void insertstart() {
    new1 = (node*)malloc(sizeof(node));
    printf("\nEnter Value: ");
    scanf("%d", &new1->data);

    if (start == NULL) {
        start = new1;
        new1->link = start;
    } else {
        new1->link = start;
        start = new1;


        temp = start;
        while (temp->link != start) {
            temp = temp->link;
        }
        temp->link = start;
    }
}

void insertend() {
    new1 = (node*)malloc(sizeof(node));
    printf("\nEnter Value: ");
    scanf("%d", &new1->data);

    if (start == NULL) {
        start = new1;
        new1->link = start;
    } else {
        curr = start;
        while (curr->link != start) {
            curr = curr->link;
        }
        curr->link = new1;
        new1->link = start;
    }
}

void insertposition() {
    int i = 1, pos;
    new1 = (node*)malloc(sizeof(node));
    printf("\nEnter Value: ");
    scanf("%d", &new1->data);

    if (start == NULL) {
        start = new1;
        new1->link = start;
        return;
    }

    printf("\nEnter Position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        new1->link = start;
        start = new1;


        temp = start;
        while (temp->link != start) {
            temp = temp->link;
        }
        temp->link = start;
        return;
    }

    temp = start;
    while (temp->link != start && i < pos - 1) {
        temp = temp->link;
        i++;
    }

    if (i == pos - 1) {
        new1->link = temp->link;
        temp->link = new1;
    } else {
        printf("\nPosition not found.\n");
    }
}

void deletestart() {
    if (start == NULL) {
        printf("\nLinked List is Empty.\n");
        return;
    }

    node *temp = start;
    if (start->link == start) {
        start = NULL;
    } else {
        temp = start;
        while (temp->link != start) {
            temp = temp->link;
        }
        start = start->link;
        temp->link = start;
    }
    free(temp);
    printf("\nFirst Element Deleted.\n");
}

void deletepos() {
    int i = 1, pos;
    if (start == NULL) {
        printf("\nLinked List is Empty.\n");
        return;
    }

    printf("\nEnter Position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        deletestart();
        return;
    }

    temp = start;
    node *prev = NULL;
    while (temp != start && i < pos) {
        prev = temp;
        temp = temp->link;
        i++;
    }

    if (temp == start) {
        printf("\nPosition Not Found.\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
    printf("\nElement at Position %d Deleted\n", pos);
}

void deleteend() {
    if (start == NULL) {
        printf("\nLinked List is Empty.\n");
        return;
    }

    node *temp = start;
    if (start->link == start) {
        start = NULL;
    } else {
        temp = start;
        while (temp->link != start) {
            temp = temp->link;
        }
        temp->link = start;
    }
    free(temp);
    printf("\nLast Element Deleted.\n");
}
