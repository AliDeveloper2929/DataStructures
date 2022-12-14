#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

// function prototypes:
struct TreeNode* createBinaryTree(struct TreeNode* Root);
void preOrderUsinRecur(struct TreeNode* root);
void preOrderUsingIter(struct TreeNode* root);
void inOrderUsingRecur(struct TreeNode* root);
void InOrderUsingIter(struct TreeNode* root);
void postOrderUsingRecur(struct TreeNode* root);
void levelOrderUsingRecur(struct TreeNode* root);
int countNodes(struct TreeNode* root);
int countLeafNodes(struct TreeNode* root);
int countNodesWithDeg1(struct TreeNode* root);
int countNodesWithDeg2(struct TreeNode* root);
int countInternalNodes(struct TreeNode* root);



struct TreeNode* createBinaryTree(struct TreeNode* Root){ // Root is always NULL when it is passed .
    Root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int val;
    printf("Enter the value for root node: ");
    scanf("%d", &val);
    Root->data = val;
    Root->lChild = Root->rChild = NULL;

    struct QueueForAddrOfTree Q;
    createQueue(&Q, 100);

    enqueue(&Q, Root);

    while( !isEmpty(Q) ){
        int leftCh, rightCh;
        struct TreeNode* tempNode = dequeue(&Q);
        printf("Enter left child of the node with value %d, if you enter -1, it means NULL: ", tempNode->data);
        scanf("%d", &leftCh);
        if(leftCh!=-1){
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->data = leftCh;
            newNode->lChild = newNode->rChild = NULL;
            tempNode->lChild = newNode;
            enqueue(&Q, tempNode->lChild);
        }

        printf("Enter right child of the node with value %d, if you enter -1, it means NULL: ", tempNode->data);
        scanf("%d", &rightCh);
        if(rightCh!=-1){
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->data = rightCh;
            newNode->lChild = newNode->rChild = NULL;
            tempNode->rChild = newNode;
            enqueue(&Q, tempNode->rChild);
        }
    }
    return Root;
}

void preOrderUsinRecur(struct TreeNode* root){
    if(root != NULL){
        printf("%d, ", root->data);
        preOrderUsinRecur(root->lChild);
        preOrderUsinRecur(root->rChild);
    }
}


void preOrderUsingIter(struct TreeNode* root){
    struct Stack stk;
    createStack(&stk, 100);
    while( !isStackEmpty(stk) || root != NULL ){
        if(root != NULL){
            printf("%d, ", root->data);
            push(&stk, root);
            root = root->lChild;
        }
        else{
            root = pop(&stk);
            root = root->rChild;
        }
    }
}



void inOrderUsingRecur(struct TreeNode* root){
    if(root != NULL){
        inOrderUsingRecur(root->lChild);
        printf("%d, ", root->data);
        inOrderUsingRecur(root->rChild);
    }
}


void InOrderUsingIter(struct TreeNode* root){
    struct Stack stk;
    createStack(&stk, 100);
    while( !isStackEmpty(stk) || root != NULL ){
        if(root != NULL){
            push(&stk, root);
            root = root->lChild;
        }
        else{
            root = pop(&stk);
            printf("%d, ", root->data);
            root = root->rChild;
        }
    }
}

/*
void PostOrderUsingIter(struct TreeNode* root){
    struct Stack stk;
    createStack(&stk, 100);
    long int temp;
    while( !isStackEmpty(stk) || root != NULL ){
        if(root != NULL){
            push(&stk, root);
            root = root->lChild;
        }
        else{
            temp = pop(&stk);
            if(temp > 0){
                push(&stk, -temp);
                root = ((struct TreeNode*)temp->rChild);
            }
            else{
                printf("%d, ", ((struct TreeNode*)temp)->data );
                root = NULL;
            }
        }
    }
}
*/



void postOrderUsingRecur(struct TreeNode* root){
    if(root != NULL){
        postOrderUsingRecur(root->lChild);
        postOrderUsingRecur(root->rChild);
        printf("%d, ", root->data);
    }
}

void levelOrderUsingRecur(struct TreeNode* root){
    struct QueueForAddrOfTree q;
    createQueue(&q, 100);
    enqueue(&q, root);
    while( !isEmpty(q) ){
        struct TreeNode* curr = dequeue(&q);
        printf("%d, ", curr->data);
        if(curr->lChild != NULL)
            enqueue(&q, curr->lChild);
        if(curr->rChild != NULL)
            enqueue(&q, curr->rChild);
    }
}


int countNodes(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        int left, right;
        left = countNodes(root->lChild);
        right = countNodes(root->rChild);
        return left+right+1;
    }
}

int countLeafNodes(struct TreeNode* root){
    if(root->lChild == NULL && root->rChild == NULL)
            return 1;
    if(root->lChild == NULL)
        return countLeafNodes(root->rChild);
    if(root->rChild == NULL)
        return countLeafNodes(root->lChild);
    return countLeafNodes(root->lChild) + countLeafNodes(root->rChild);
}


int countLeafNodes2(struct TreeNode* root){
    if(root != NULL){
        int left, right;
        left = countLeafNodes2(root->lChild);
        right = countLeafNodes2(root->rChild);
        if(root->lChild == NULL && root->rChild == NULL){
            return left+right+1;
        }
        else{
            return left+right;
        }
    }
    else
        return 0;
}


int countNodesWithDeg2(struct TreeNode* root){
    if(root != NULL){
        int left, right;
        left = countNodesWithDeg2(root->lChild);
        right = countNodesWithDeg2(root->rChild);
        if(root->lChild != NULL && root->rChild != NULL){
            return left+right+1;
        }
        else{
            return left+right;
        }
    }
    else
        return 0;
}

int countNodesWithDeg1(struct TreeNode* root){
    if(root != NULL){
        int left, right;
        left = countNodesWithDeg1(root->lChild);
        right = countNodesWithDeg1(root->rChild);
        if((root->lChild != NULL && root->rChild == NULL) || (root->lChild == NULL && root->rChild != NULL)){
            return left+right+1;
        }
        else{
            return left+right;
        }
    }
    else
        return 0;
}

int countInternalNodes(struct TreeNode* root){
    if(root != NULL){
        int left, right;
        left = countInternalNodes(root->lChild);
        right = countInternalNodes(root->rChild);
        if(root->lChild != NULL || root->rChild != NULL){
            return left+right+1;
        }
    }
    else
        return 0;
}



int main()
{
    struct TreeNode* root1 = NULL;
    root1 = createBinaryTree(root1);
    printf("\nPreorder using recursion: ");
    preOrderUsinRecur(root1);
    printf("\nPreOrder using iteration: ");
    preOrderUsingIter(root1);
    printf("\n");
    printf("Inorder using recursion: ");
    inOrderUsingRecur(root1);
    printf("\nInorder using iteration: ");
    InOrderUsingIter(root1);
    printf("\n");
    printf("Postorder using recursion: ");
    postOrderUsingRecur(root1);
   // printf("\nPost order using iteration: ")
  //  PostOrderUsingIter(root1);
    printf("\nLevel order using recursion: ");
    levelOrderUsingRecur(root1);
    printf("\nNumber of nodes in binary tree is %d\n", countNodes(root1));
    printf("Count of leaf nodes in binary tree is %d\n", countLeafNodes(root1));
    printf("Count of leaf nodes in binary tree is %d\n", countLeafNodes2(root1));
    printf("Count of nodes with degree 1 in binary tree is %d\n", countNodesWithDeg1(root1));
    printf("Count of nodes with degree 2 in binary tree is %d\n", countNodesWithDeg2(root1));
    printf("Count of internal nodes is: %d\n", countInternalNodes(root1));

    return 0;
}
