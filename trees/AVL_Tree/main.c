#include <stdio.h>
#include <stdlib.h>


struct AVL_Node{
    int data;
    struct AVL_Node* left;
    struct AVL_Node* right;
};

struct AVL_Node* getNewNode(int num);
int getHeight(struct AVL_Node* root);
int getBalance(struct AVL_Node* root);
struct AVL_Node* rotate_To_Left(struct AVL_Node* node);
struct AVL_Node* rotate_To_Right(struct AVL_Node* node);
struct AVL_Node* insert(struct AVL_Node* root, int num);
int height(struct AVL_Node* root);
struct AVL_Node* delete_In_AVL(struct AVL_Node* root, int num);


struct AVL_Node* getNewNode(int num){
    struct AVL_Node* newNode = (struct AVL_Node*)malloc(sizeof(struct AVL_Node));
    newNode->data = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getHeight(struct AVL_Node* root){
    if(root == NULL)
        return -1;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if(left > right)
        return left+1;
    else return right+1;
}


int getBalance(struct AVL_Node* root){
    return getHeight(root->left) - getHeight(root->right);
}

struct AVL_Node* rotate_To_Left(struct AVL_Node* node){
    struct AVL_Node* rightOf_node = node->right;
    node->right = rightOf_node->left;
    rightOf_node->left = node;
    return rightOf_node;
}

struct AVL_Node* rotate_To_Right(struct AVL_Node* node){
    struct AVL_Node* leftOf_node = node->left;
    node->left = leftOf_node->right;
    leftOf_node->right = node;
    return leftOf_node;
}

struct AVL_Node* insert(struct AVL_Node* root, int num){
    if(root == NULL){
        root = getNewNode(num);
        return root;
    }
    if(num < root->data)
        root->left = insert(root->left, num);
    else if(num > root->data)
        root->right = insert(root->right, num);
    else{
        printf("Duplicates is not allowed in AVL tree\n");
        return root;
    }

    int balance = getBalance(root);
    if(balance == -2 && num < root->right->data){// right left rotation
        root->right = rotate_To_Right(root->right);
        return rotate_To_Left(root);
    }
    if(balance == -2 && num > root->right->data){// right right rotation
        return rotate_To_Left(root);
    }
    if(balance == 2 && num < root->left->data){// left left rotation
        return rotate_To_Right(root);
    }
    if(balance == 2 && num > root->left->data){// left right rotation
        root->right = rotate_To_Left(root->right);
        return rotate_To_Right(root);
    }
    return root;
}


void inOrder(struct AVL_Node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d, ", root->data);
        inOrder(root->right);
    }
}



int height(struct AVL_Node* root){
    if(root == NULL)
        return -1;
    int left = height(root->left);
    int right = height(root->right);
    return left > right ? left+1 : right+1;
}





struct AVL_Node* delete_In_AVL(struct AVL_Node* root, int num){
    if(root == NULL){
        printf("The number %d is not found from avl tree\n", num);
        return NULL;
    }
    if(num < root->data)
        root->left = delete_In_AVL(root->left, num);
    else if(num > root->data)
        root->right = delete_In_AVL(root->right, num);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
            return root;
        }
        else if(root->left == NULL){
            struct AVL_Node* deletable = root;
            root = root->right;
            free(deletable);
            // return root;
        }
        else if(root->right == NULL){
            struct AVL_Node* deletable = root;
            root = root->left;
            free(deletable);
            // return root;
        }
        else{
            if( height(root->left) > height(root->right) ){
                struct AVL_Node* inorderPred = root->left;
                while(inorderPred->right != NULL)
                    inorderPred = inorderPred->right;
                root->data = inorderPred->data;
                root->left = delete_In_AVL(root->left, inorderPred->data);
            }
            else{
                struct AVL_Node* inorderSucc = root->right;
                while(inorderSucc->left != NULL)
                    inorderSucc = inorderSucc->left;
                root->data = inorderSucc->data;
                root->right = delete_In_AVL(root->right, inorderSucc->data);
            }
        }
    }
    int balance = getBalance(root);
    if(balance == 2){
        if(getBalance(root->left) == -1){
            root->left = rotate_To_Left(root->left);
            return rotate_To_Right(root);
        }
        if(getBalance(root->left) == 1){
            return rotate_To_Right(root);
        }
        if(getBalance(root->left) == 0){
            return rotate_To_Right(root);
        }
    }
    else if(balance == -2){
        if(getBalance(root->left) == -1){
            return rotate_To_Left(root);
        }
        if(getBalance(root->left) == 1){
            root->right = rotate_To_Right(root->right);
            return rotate_To_Left(root);
        }
        if(getBalance(root->left) == 0){
            return rotate_To_Left(root);
        }
    }
    else return root;
}





int main()
{
    struct AVL_Node* root = NULL;
    root = insert(root, 50);
    inOrder(root);
    printf("\n");

    root = insert(root, 80);
    printf("%d\n", root->data);
    inOrder(root);
    printf("\n");


    root = insert(root, 100);
    printf("%d\n", root->data);
    inOrder(root);
    printf("\n");


    root = insert(root, 90);
    printf("%d\n", root->data);
    inOrder(root);
    printf("\n");


    root = delete_In_AVL(root, 100);
    printf("%d\n", root->right->data);
    inOrder(root);
    printf("\n");
    return 0;
}
