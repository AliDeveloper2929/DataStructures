#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* top){
    if(top == NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("Elements of stack: ");
        while(top != NULL){
            printf("%d, ", top->data);
            top = top->next;
        }
        printf("\n");
    }
}


struct Node* push(struct Node* top, int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("The stack overflow\n");
    }
    else{
        newNode->data = num;
        newNode->next = top;
        top = newNode;
    }
    return top;
}

struct Node* pop(struct Node* top){
    if(top == NULL){
        printf("Stack underflow\n");
    }
    else{
        struct Node* deletable = top;
        top = top->next;
        free(deletable);
    }
    return top;
}

bool isEmpty(struct Node* top){
    if(top == NULL){
        return true;
    }
    else
        return false;
}


int getTop(struct Node* top){
    return top->data;
}

int pop_And_Get(struct Node** top){    // question here
    int x = **top->data;
    struct Node* deletable = (*top);
    **top = **top->next;
    free(deletable);
    return x;
}


int main()
{
    struct Node* topNode = NULL;
    topNode = push(topNode, 5);
    display(topNode);
    topNode = push(topNode, 25);
    display(topNode);
    int first = pop_And_Get(&topNode);
    printf("%d", first);
    return 0;
}
