#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

bool isQueueEmpty(struct Node* front){
    if(front == NULL)
        return true;
    else
        return false;
}

struct Node* enqueue(struct Node* front, int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Queue is full\n");
        return front;
    }
    newNode->data = num;
    newNode->next = NULL;
    if(front == NULL){
        front = newNode;
    }
    else{
        struct Node* temp = front;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return front;
}

struct Node* dequeue(struct Node* front){
    if(front == NULL){
        printf("The queue is empty\n");
    }
    else{
        struct Node* deletable = front;
        front = front->next;
        free(deletable);
    }
    return front;
}

void displayQueue(struct Node* front){
    if(front == NULL){
        printf("The queue is empty\n");
        return;
    }
    printf("Elements at queue: ");
    while(front != NULL){
        printf("%d, ", front->data);
        front = front->next;
    }
    printf("\n");
}


int main()
{   struct Node* frontNode;
    printf("Hello world!\n");
    return 0;
}
