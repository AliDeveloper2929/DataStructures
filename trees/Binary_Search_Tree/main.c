#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// BST is acronym for Binary Search Tree

struct BST_Node{
    struct BST_Node* leftCh;
    int data;
    struct BST_Node* rightCh;
};

// function prototypes;
struct BST_Node* search_Using_Recur(struct BST_Node* root, int num);
int get_Num_If_Exist(struct BST_Node* root, int num);
bool Num_Exists(struct BST_Node* root, int num);
struct BST_Node* search_Using_Loop_1(struct BST_Node* root, int num);
struct BST_Node* insert_Using_Recur(struct BST_Node* root, int num);
struct BST_Node* insert_Using_Iteration(struct BST_Node* root, int num);
int getHeight(struct BST_Node* root);
struct BST_Node* inorderPredecessor(struct BST_Node* root);
struct BST_Node* inorderSuccessor(struct BST_Node* root);
struct BST_Node* delete_Using_Recur(struct BST_Node* root, int num);




// below function returns the address of the Node with value num if exists. Else it returns NULL.
struct BST_Node* search_Using_Recur(struct BST_Node* root, int num){
    if(root == NULL){
        printf("%d is not found from Binary Search Tree\n", num);
        return NULL;
    }
    if(num == root->data){
        return root;
    }
    if(num < root->data){
        return search_Using_Recur(root->leftCh, num);
    }
    if(num > root->data){
        return search_Using_Recur(root->rightCh, num);
    }
}

int get_Num_If_Exist(struct BST_Node* root, int num){
    if(root == NULL){
        printf("%d is not found from Binary Search Tree\n", num);
        return -1;
    }
    if(root->data == num){
        return root->data;
    }
    if(num > root->data)
        return get_Num_If_Exist(root->rightCh, num);
    if(num < root->data)
        return get_Num_If_Exist(root->leftCh, num);
}

bool Num_Exists(struct BST_Node* root, int num){
    if(root == NULL){
        return false;
    }
    if(root->data == num)
        return true;
    if(num > root->data)
        return Num_Exists(root->rightCh, num);
    if(num < root->data)
        return Num_Exists(root->leftCh, num);
}

struct BST_Node* search_Using_Loop_1(struct BST_Node* root, int num){
    while(root != NULL){
        if(root->data == num)
            return root;
        else if(root->data > num)
            root = root->leftCh;
        else
            root = root->rightCh;
    }
    printf("%d is not found from Binary Search Tree\n", num);
    return NULL;
}

struct BST_Node* search_Using_Loop_2(struct BST_Node* root, int num){
    if(root == NULL){
        printf("%d is not found from Binary Search Tree\n", num);
        return NULL;
    }
    while(root->data != num){
        if(root->data < num)
            root = root->rightCh;
        else
            root = root->leftCh;
        if(root == NULL){
            printf("%d is not found from Binary Search Tree\n", num);
            return NULL;
        }
    }
    return root;
}


struct BST_Node* insert_Using_Recur(struct BST_Node* root, int num){
    if(root == NULL){
        root = (struct BST_Node*)malloc(sizeof(struct BST_Node));
        root->data = num;
        root->leftCh = root->rightCh = NULL;
        return root;
    }
    if(num > root->data){
        root->rightCh = insert_Using_Recur(root->rightCh, num);
    }
    else if(num < root->data){
        root->leftCh = insert_Using_Recur(root->leftCh, num);
    }
    else{
        printf("The duplicates is not allowed in Binary Search tree. %d already exists\n", num);
    }
    return root;
}


struct BST_Node* insert_Using_Iteration(struct BST_Node* root, int num){
    struct BST_Node* temp = root;
    struct BST_Node* tail = NULL;
    while(temp != NULL){
        if(num > temp->data){
            tail = temp;
            temp = temp->rightCh;
        }
        else if(num < root->data){
            tail = temp;
            temp = temp->leftCh;
        }
        else{
            printf("Duplicates are not allowed in binary search tree\n");
            return root;
        }
    }
    temp = (struct BST_Node*)malloc(sizeof(struct BST_Node));
    temp->data = num;
    temp->leftCh = temp->rightCh = NULL;
    if(root == NULL)
        root = temp;
    else if(tail->data > temp->data)
        tail->leftCh = temp;
    else
        tail->rightCh = temp;
    return root;
}



struct BST_Node* delete_Using_Recur(struct BST_Node* root, int num){
    if(root == NULL){
        printf("\nNumber %d is not found from Binary Search Tree\n", num);
        return NULL;
    }
    if(num < root->data)
        root->leftCh = delete_Using_Recur(root->leftCh, num);
    else if(num > root->data)
        root->rightCh = delete_Using_Recur(root->rightCh, num);
    else{
        if(root->leftCh == NULL && root->rightCh == NULL){
            free(root);
            root = NULL;
            // return root;
        }
        else if(root->leftCh == NULL){
            struct BST_Node* deletableNode = root;
            root = root->rightCh;
            free(deletableNode);
            // return root;
        }
        else if(root->rightCh == NULL){
            struct BST_Node* deletableNode = root;
            root = root->leftCh;
            free(deletableNode);
            // return root;
        }
        else{
            if( getHeight(root->leftCh)>getHeight(root->rightCh) ){
                struct BST_Node* inorderPre = inorderPredecessor(root);
                root->data = inorderPre->data;
                root->leftCh = delete_Using_Recur(root->leftCh, inorderPre->data);
            }
            else{
                struct BST_Node* inorderSuc = inorderSuccessor(root);
                root->data = inorderSuc->data;
                root->rightCh = delete_Using_Recur(root->rightCh, inorderSuc->data);
            }
        }
    }
    return root;
}



int getHeight(struct BST_Node* root){
    if(root == NULL)
        return -1;
    int left = getHeight(root->leftCh);
    int right = getHeight(root->rightCh);
    if(left > right)
        return left+1;
    else return right+1;
}


struct BST_Node* inorderPredecessor(struct BST_Node* root){
    if(root->leftCh == NULL){
        printf("This root does not have inorder predecessor\n");
        return root;
    }
    struct BST_Node* inorderPre = root->leftCh;
    while(inorderPre->rightCh != NULL)
        inorderPre = inorderPre->rightCh;
    return inorderPre;
}

struct BST_Node* inorderSuccessor(struct BST_Node* root){
    if(root->rightCh == NULL){
        printf("This root does not have inorder Successor\n");
        return root;
    }
    struct BST_Node* inorderSuc = root->rightCh;
    while(inorderSuc->leftCh != NULL)
        inorderSuc = inorderSuc->leftCh;
    return inorderSuc;
}


void inOrder(struct BST_Node* root){
    if(root != NULL){
        inOrder(root->leftCh);
        printf("%d, ", root->data);
        inOrder(root->rightCh);
    }
}




int main()
{

    struct BST_Node* root = NULL;

    root = insert_Using_Recur(root, 50);
    inOrder(root);
    printf("\n");

    root = insert_Using_Recur(root, 20);
    inOrder(root);
    printf("\n");

    root = insert_Using_Recur(root, 80);
    inOrder(root);
    printf("\n");

    root = insert_Using_Recur(root, 70);
    inOrder(root);
    printf("\n");

    root = insert_Using_Recur(root, 30);
    inOrder(root);
    printf("\n");

    root = insert_Using_Recur(root, 10);
    inOrder(root);
    printf("\n");

    root = insert_Using_Recur(root, 30);
    inOrder(root);
    printf("\n");

    root = insert_Using_Iteration(root, 25);
    inOrder(root);
     printf("\n");

    root = delete_Using_Recur(root, 50);
    inOrder(root);
    printf("\n");



    //struct BST_Node* inorPre = inorderSuccessor(root);
    //printf("\n%d", getHeight(root));
    return 0;
}
