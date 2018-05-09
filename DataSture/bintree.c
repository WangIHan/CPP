#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    struct treenode *stk[100];
    int length;
    int top;
}Stack;

typedef struct treenode *nodepointer;
typedef struct treenode {
    char data;
    struct treenode *lchild;
    struct treenode *rchild;
}Bintree;

void stackInit(struct stack **stk) {
    *stk = (struct stack *)malloc(sizeof(struct stack));
    (*stk)->length = 0;
    (*stk)->top = -1;
};

struct treenode *pop(struct stack *stk) {                //pop the first element in the stack
    int i;
    nodepointer pb = stk->stk[0];
    for(i = 0; i < stk->top-1; i++) {
        stk->stk[i] = stk->stk[i+1];
    }
    stk->top--;
    stk->length--;
    return pb;
}

void push(struct stack *stk, nodepointer node) {
    if(!stk) {
        printf("stack is empty,exit.\n");
        return;
    }
    stk->stk[stk->length++] = node;
    stk->top++;
}

void clear(struct stack *stk) {
    stk->top = -1;
    stk->length = 0;
}


void Create(nodepointer *root, struct stack *stk) {
    int flag = 1;
    char buffer[20];
    *root = (nodepointer)malloc(sizeof(struct treenode));
    nodepointer p = *root;
    printf("please enter a string to create binary tree.\n");
    scanf("%s", &buffer[0]);
    p->data = buffer[0];
    p->lchild = NULL;
    p->rchild = NULL;
    push(stk, p);
    printf("1");
    while(buffer[flag] != '\0') {
        p = pop(stk);
        if(buffer[flag] == '#' && buffer[flag+1] == '#') {
            flag += 2;
            pop(stk);
        }
        if(buffer[flag] != '#' && buffer[flag+1] == '#') {
            p->lchild = (nodepointer)malloc(sizeof(struct treenode));
            p->lchild->data = buffer[flag];
            p->lchild->lchild = NULL;
            p->lchild->rchild = NULL;
            flag += 2;
            push(stk, p->lchild);
        } 
        if(buffer[flag] == '#' && buffer[flag+1] != '#') {
            p->rchild = (nodepointer)malloc(sizeof(struct treenode));
            p->rchild->data = buffer[+1];
            p->rchild->rchild = NULL;
            p->rchild->lchild = NULL;
            flag += 2;
            push(stk, p->rchild);
        }
        if(buffer[flag] != '#' && buffer[flag+1] != '#') {
            p->lchild = (nodepointer)malloc(sizeof(struct treenode));
            p->lchild->data = buffer[flag];
            p->rchild->data = buffer[flag+1];
            p->lchild->lchild = NULL;
            p->lchild->rchild = NULL;
            p->rchild->lchild = NULL;
            p->rchild->rchild = NULL;
            push(stk, p->lchild);
            push(stk, p->rchild);
            flag += 2;
        }    
    }
}

void preOrderTraverse(nodepointer root) {
    nodepointer p = root;
    if(!p) 
        return;
    else {
        preOrderTraverse(p->lchild);
        printf("%c", p->data);
        preOrderTraverse(p->rchild);
    }
}

int main(int argc, char **argv) {
    struct stack *stk = NULL;
    nodepointer root = NULL;
    stackInit(&stk);
    Create(&root, stk);
    preOrderTraverse(root);
    return 0;
}
