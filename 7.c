#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node *NODE;
NODE root = NULL;

void create(NODE);
int is_lchild(NODE);
int is_rchild(NODE);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE getnode();

void main() {
    clrscr();
    printf("Tree traversals\n");
    printf("Enter the data for the root: ");
    root = getnode();
    scanf("%d", &root->data);
    create(root);
    printf("\nPreorder traversal:\n");
    preorder(root);
    printf("\nInorder traversal:\n");
    inorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);
    getch();
}

NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void create(NODE root) {
    if (is_lchild(root)) {
        root->lchild = getnode();
        printf("Enter the data: ");
        scanf("%d", &root->lchild->data);
        create(root->lchild);
    }
    if (is_rchild(root)) {
        root->rchild = getnode();
        printf("Enter the data: ");
        scanf("%d", &root->rchild->data);
        create(root->rchild);
    }
}

int is_lchild(NODE root) {
    int ch;
    printf("Create lchild of %d? YES-1 NO-0 : ", root->data);
    scanf("%d", &ch);
    if (ch)
        return 1;
    else
        return 0;
}

int is_rchild(NODE root) {
    int ch;
    printf("Create rchild of %d? YES-1 NO-0 : ", root->data);
    scanf("%d", &ch);
    if (ch)
        return 1;
    else
        return 0;
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d=>", root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d=>", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d=>", root->data);
    }
}
