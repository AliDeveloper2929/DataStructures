#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "Queue.h"
#include <stdbool.h>

struct Stack{
    int top;
    int sizeOfStack;
    struct TreeNode** arrForStack;
};

void createStack(struct Stack* stk, int sizeStk){
    stk->top = -1;
    stk->sizeOfStack = sizeStk;
    stk->arrForStack = (struct TreeNode**)malloc(stk->sizeOfStack * sizeof(struct TreeNode*));
}

void push(struct Stack* stk, struct TreeNode* node){
    if(stk->top == stk->sizeOfStack-1){
        printf("Stack overflow\n");
    }
    else{
        stk->top++;
        stk->arrForStack[stk->top] = node;
    }
}

struct TreeNode* pop(struct Stack* stk){
    struct TreeNode* temp = NULL;
    if(stk->top == -1){
        printf("Stack underflow\n");
    }
    else{
        temp = stk->arrForStack[stk->top];
        stk->top--;
    }
    return temp;
}

bool isStackEmpty(struct Stack stk){
    if(stk.top == -1)
        return true;
    else
        return false;
}



#endif // STACK_H_INCLUDED
