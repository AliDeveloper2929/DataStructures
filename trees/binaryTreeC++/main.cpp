#include <iostream>
#include <stdio.h>
#include "QueueCPP.h"

using namespace std;



class BinaryTree{
private:
    TreeNode* root;
public:
    BinaryTree(){root = NULL;}
    TreeNode* createBinaryTree();
    void preOrder1(){
        printf("PreOrder traversal: ");
        preOrder(root);
        printf("\n");
    }
    void preOrder(TreeNode* p);
    void inOrder1(){
        printf("InOrder traversal: ");
        inOrder(root);
        printf("\n");
    }
    void inOrder(TreeNode* p);
    void postOrder1(){
        printf("PostOrder traversal: ");
        postOrder(root);
        printf("\n");
    }
    void postOrder(TreeNode* p);
    void levelOrder1(){
        printf("LevelOrder traversal: ");
        levelOrder(root);
        printf("\n");
    }
    void levelOrder(TreeNode* p);
    void height1(){
        printf("Height Of created binary tree is: %d\n", height(root));
    }
    int height(TreeNode* p);
};



TreeNode* BinaryTree::createBinaryTree(){
    root = new TreeNode;
    int val;
    printf("Enter the value for root node: ");
    scanf("%d", &val);
    root->data = val;
    root->lChild = root->rChild = NULL;

    QueueForAddrOfTree Q;
    Q.createQueue(100);
    Q.enqueue(root);

    while( !Q.isEmpty() ){
        int leftCh, rightCh;
        TreeNode* tempNode = Q.dequeue();
        printf("Enter left child of the node with value %d, if you enter -1, it means NULL: ", tempNode->data);
        scanf("%d", &leftCh);
        if(leftCh!=-1){
            TreeNode* newNode = new TreeNode;
            newNode->data = leftCh;
            newNode->lChild = newNode->rChild = NULL;
            tempNode->lChild = newNode;
            Q.enqueue(tempNode->lChild);
        }

        printf("Enter right child of the node with value %d, if you enter -1, it means NULL: ", tempNode->data);
        scanf("%d", &rightCh);
        if(rightCh!=-1){
            TreeNode* newNode = new TreeNode;
            newNode->data = rightCh;
            newNode->lChild = newNode->rChild = NULL;
            tempNode->rChild = newNode;
            Q.enqueue(tempNode->rChild);
        }
    }
    return root;
}

void BinaryTree::preOrder(TreeNode* r){
    if(r != NULL){
        printf("%d, ", r->data);
        preOrder(r->lChild);
        preOrder(r->rChild);
    }
}



void BinaryTree::inOrder(TreeNode* r){
    if(r != NULL){
        inOrder(r->lChild);
        printf("%d, ", r->data);
        inOrder(r->rChild);
    }
}

void BinaryTree::postOrder(TreeNode* r){
    if(r != NULL){
        postOrder(r->lChild);
        postOrder(r->rChild);
        printf("%d, ", r->data);
    }
}

void BinaryTree::levelOrder(TreeNode* r){
    QueueForAddrOfTree q;
    q.createQueue(100);
    q.enqueue(r);
    while( !q.isEmpty() ){
        TreeNode* curr = q.dequeue();
        printf("%d, ", curr->data);
        if(curr->lChild != NULL)
            q.enqueue(curr->lChild);
        if(curr->rChild != NULL)
            q.enqueue(curr->rChild);
    }
}

int BinaryTree::height(TreeNode* p){
    if( p!=NULL ){
        int left, right;
        left = height(p->lChild);
        right = height(p->rChild);

        if(left>right)
            return left+1;
        else
            return right+1;
    }
    else{
        return -1;
    }
}

int main()
{

    TreeNode* root = NULL;
    BinaryTree t1;
    root = t1.createBinaryTree();
    t1.inOrder1();
    t1.levelOrder1();
    t1.postOrder1();
    t1.preOrder1();
    t1.height1();
    return 0;
}
