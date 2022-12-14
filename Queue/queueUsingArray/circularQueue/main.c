#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue{
    int front;
    int rear;
    int size;
    int* arrForQueue;
};

void enque(struct Queue* q, int num);
int deque(struct Queue* q);
void deque2(struct Queue* q);
void displayQueue(struct Queue q);
bool isQueueFull(struct Queue q);
bool isQueueEmpty(struct Queue q);


void enque(struct Queue* q, int num){
    if(q->front == 0 && q->rear == q->size-1)
        printf("Queue is full \n");
    else if(q->front -q->rear == 1)
        printf("Queue is full\n");
    else{
        if(q->rear == q->size-1 && q->front != 0)
            q->rear = -1;
        q->rear++;
        q->arrForQueue[q->rear] = num;
    }
}

// using mod % to get the index of the next queue in circular queue;
void enque2(struct Queue* q, int num){
    if( q->front == (q->rear+1)%q->size )
        printf("Queue is full\n");
    else{
        q->rear = (q->rear+1)%q->size;
        q->arrForQueue[q->rear] = num;
    }
}


int deque(struct Queue* q){
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is empty\n");
    else{
        if(q->front == q->size-1)
            q->front = -1;
        q->front++;
        x = q->arrForQueue[q->front];
    }
    return x;
}
// using mod % to get the index of the next queue in circular queue;
int deque3(struct Queue* q){
    int x = -1;
    if(q->rear == q->front)
        printf("Queue is empty\n");
    else{
        q->front = (q->front+1)%q->size;
        x = q->arrForQueue[q->front];
    }
    return x;
}

void deque2(struct Queue* q){
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        if(q->front == q->size-1)
            q->front = -1;
        q->front++;
    }
    return;
}

void displayQueue(struct Queue q){
    if(q.rear == q.front){
        printf("Queue is empty. No element to display\n");
    }
    else if(q.rear > q.front){
        printf("Elements at queue: ");
        for(int i = q.front+1; i<=q.rear; i++){
            printf("%d, ", q.arrForQueue[i]);
        }
        printf("\n");
    }
    else{
        printf("Elements at queue: ");
        int first = q.front+1;
        int last = q.rear;
        while(first != q.size){
            printf("%d, ", q.arrForQueue[first]);
            first++;
        }
        first = 0;
        while(first != last+1){
            printf("%d, ", q.arrForQueue[first]);
            first++;
        }
        printf("\n");
    }
}

// using mod % to get the index of the next queue in circular queue;
void displayQueue2(struct Queue q){
    if(q.front == q.rear)
        printf("The queue is empty\n");
    else{
        int i = q.front+1;
        do{
            printf("%d, ", q.arrForQueue[i]);
            i = (i+1)%q.size;
        }while(i != (q.rear+1)%q.size);
        printf("\n");
    }
}




bool isQueueEmpty(struct Queue q){
    if(q.rear == q.front)
        return true;
    else
        return false;
}


bool isQueueFull(struct Queue q){
    if(q.front == 0 && q.rear == q.size-1)
        return true;
    else if(q.front-q.rear == 1)
        return true;
    else
        return false;
}


int main()
{
    struct Queue q;
    q.front = 0;
    q.rear = 0;
    q.size = 8;
    q.arrForQueue = (int*)malloc( q.size * sizeof(int));


    if(isQueueEmpty(q))
        printf("empty\n");
    else
        printf("Not empty\n");
    //displayQueue(q);
    for(int i = 0; i<7; i++){
        enque(&q, i+1);
        displayQueue(q);
    }
    enque(&q, 9);
    displayQueue(q);

    deque2(&q);
    displayQueue(q);
    enque(&q, 9);
    displayQueue(q);
    enque(&q, 19);
    displayQueue(q);

    for(int i = 0; i<7; i++){
        deque2(&q);
    }
    displayQueue(q);




    return 0;
}
