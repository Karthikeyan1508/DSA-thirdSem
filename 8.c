#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE insertion(NODE);
NODE deletion(NODE);
void inorder(NODE);
NODE getnode();

void main() {
    int option;
    NODE root;
    clrscr();
    root = getnode();
    printf("Enter the data for root node\n");
    scanf("%d", &root->data);
    while (1) {
        printf("\nTree operations\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                root = insertion(root);
                getch();
                clrscr();
                break;
            case 2:
                root = deletion(root);
                getch();
                clrscr();
                break;
            case 3:
                printf("\nInorder traversal\n");
                inorder(root);
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

NODE insertion(NODE root) {
    NODE prev, temp, temp1;
    int item;
    temp1 = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp1->data);
    printf("%d is successfully inserted\n", temp1->data);
    item = temp1->data;
    prev = NULL;
    temp = root;
    while (temp != NULL) {
        prev = temp;
        if (item < temp->data)
            temp = temp->llink;
        else
            temp = temp->rlink;
    }
    if (item < prev->data)
        prev->llink = temp1;
    else
        prev->rlink = temp1;
    return root;
}

NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    return temp;
}

NODE deletion(NODE root) {
    NODE cur, parent, suc, q;
    int item;
    if (root == NULL) {
        printf("No elements in tree\n");
        return root;
    }
    printf("Enter the element to be deleted: ");
    scanf("%d", &item);
    parent = NULL;
    cur = root;
    while (cur != NULL && item != cur->data) {
        parent = cur;
        if (item < cur->data)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (cur == NULL) {
        printf("%d not found", item);
        return root;
    }
    if (cur->llink == NULL)
        q = cur->rlink;
    else if (cur->rlink == NULL)
        q = cur->llink;
    else {
        suc = cur->rlink;
        while (suc->llink != NULL)
            suc = suc->llink;
        suc->llink = cur->llink;
        q = cur->rlink;
    }
    if (cur == parent->llink)
        parent->llink = q;
    else
        parent->rlink = q;
    free(cur);
    printf("%d is successfully deleted\n", item);
    return root;
}

void inorder(NODE root) {
    if (root != 0) {
        inorder(root->llink);
        printf("%d=>", root->data);
        inorder(root->rlink);
    }
}
