#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* topNode;
};


// prototypes of functions
void push(struct Stack* stk, int num);
void pop(struct Stack* stk);
int pop_And_Get(struct Stack* stk);
int Get_Top(struct Stack stk);
int get_Nth_ele_from_top(struct Stack stk, int position);
void display(struct Stack stk);
bool isEmpty(struct Stack stk);



void push(struct Stack* stk, int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if(stk->topNode == NULL){
        stk->topNode = newNode;
        return;
    }
    newNode->next = stk->topNode;
    stk->topNode = newNode;
    return;
}

void pop(struct Stack* stk){
    if(stk->topNode == NULL){
        printf("Stack underflow, stack is empty\n");
        return;
    }
    struct Node* deletable = stk->topNode;
    stk->topNode = stk->topNode->next;
    free(deletable);
    return;
}

// this deletes top node and returns its value
int pop_And_Get(struct Stack* stk){
    int x = -1;
    if(stk->topNode == NULL){
        printf("Stack underflow, stack is empty\n");
        return x;
    }
    struct Node* deletable = stk->topNode;
    x = stk->topNode->data;
    stk->topNode = stk->topNode->next;
    free(deletable);
    return x;
}

// this returns top Node's value without deleting any element
int Get_Top(struct Stack stk){
    if(stk.topNode == NULL){
        printf("Stack underflow, stack is empty\n");
        return -1;
    }
    return stk.topNode->data;
}


// this doesnot delete any element, just returns the value of the node at position n from top.
int get_Nth_ele_from_top(struct Stack stk, int position){ // if pos == 1; return topNode value
    if(stk.topNode == NULL){
        printf("The stack is empty\n");
        return -1;
    }
    if(position < 1){
        printf("The position must be at least 1 which is top Node\n");
        return -1;
    }

    for(int i = 0; i<position-1; i++){
        stk.topNode = stk.topNode->next;
        if(stk.topNode == NULL){
            printf("There are only %d elements in stack. Give position between 1 and %d\n", i+1, i+1);
            return -1;
        }
    }
    return stk.topNode->data;
}

void display(struct Stack stk){
    if(stk.topNode == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(stk.topNode != NULL){
        printf("%d, ", (stk.topNode)->data);
        stk.topNode = stk.topNode->next;
    }
    printf("\n");
}

bool isEmpty(struct Stack stk){
    if(stk.topNode == NULL)
        return true;
    return false;
}



int main()
{
    struct Stack stk;
    stk.topNode = NULL;
    display(stk);
    for(int i = 0; i< 25; i++){
        push(&stk, i+1);
        display(stk);
    }
    printf("%d", get_Nth_ele_from_top(stk, 28));
    return 0;
}
