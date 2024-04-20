#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode();
NODE insert_front(NODE);
NODE delete_front(NODE);
NODE insert_rear(NODE);
NODE delete_rear(NODE);
void display(NODE);

void main() {
    NODE head;
    int option;
    //clrscr();
    head = getnode();
    head->link = head;
    while (1) {
        printf("\nCircular linked list operations\n");
        printf("1. Insert to rear\n2. Insert to front\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                head = insert_rear(head);
                getch();
                clrscr();
                break;
            case 2:
                head = insert_front(head);
                getch();
                clrscr();
                break;
            case 3:
                head = delete_front(head);
                getch();
                clrscr();
                break;
            case 4:
                head = delete_rear(head);
                getch();
                clrscr();
                break;
            case 5:
                display(head);
                getch();
                clrscr();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    return temp;
}

NODE insert_front(NODE head) {
    NODE temp, first;
    temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    printf("%d is successfully inserted\n", temp->data);
    temp->link = head->link;
    head->link = temp;
    return head;
}

NODE delete_front(NODE head) {
    NODE ptr;
    if (head->link == head) {
        printf("No nodes\n");
        return head;
    }
    ptr = head->link;
    printf("%d is successfully deleted\n", ptr->data);
    head->link = ptr->link;
    free(ptr);
    return head;
}

NODE insert_rear(NODE head) {
    NODE ptr, temp;
    ptr = head->link;
    while (ptr->link != head)
        ptr = ptr->link;
    temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    printf("%d is successfully inserted\n", temp->data);
    ptr->link = temp;
    temp->link = head;
    return head;
}

NODE delete_rear(NODE head) {
    NODE ptr, prev;
    if (head->link == head) {
        printf("No nodes\n");
        return head;
    }
    ptr = head->link;
    while (ptr->link != head) {
        prev = ptr;
        ptr = ptr->link;
    }
    printf("%d is successfully deleted\n", ptr->data);
    prev->link = head;
    free(ptr);
    return head;
}

void display(NODE head) {
    NODE temp;
    if (head->link == head)
        printf("No nodes\n");
    else {
        for (temp = head->link; temp->link != head; temp = temp->link)
            printf("%d=>", temp->data);
        printf("%d", temp->data);
    }
}
