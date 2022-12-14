#include <stdio.h>
#include <stdlib.h>



struct Queue{
    int size;
    int front;
    int rear;
    int* arrForQueue;
};


void enqueue(struct Queue* q, int num){
    if(q->rear == q->size-1){
        printf("The queue is full, no space\n");
    }
    else{
        q->arrForQueue[++q->rear] = num;
    }
}


int deque(struct Queue* q){
    int x = -1;
    if(q->front == q->rear){
        printf("There is no element at queue\n");
    }
    else{
        x = q->arrForQueue[++q->front];
    }
    return x;
}

void deque2(struct Queue* q){
    if(q->front == q->rear)
        printf("No element at queue\n");
    else
        q->front++;
}

void display(struct Queue q){
    if(q.front == q.rear)
        printf("No element at queue\n");
    else{
        printf("Elements at queue: ");
        for(int i = q.front+1; i<=q.rear; i++){
            printf("%d, ", q.arrForQueue[i]);
        }
        printf("\n");
    }
}

bool isQueueEmpty(struct Queue q){
    if(q.front == q.rear && q.rear < q.size-1)
        return true;
    else
        return false;
}


bool isQueueFull(struct Queue q){
    if(q.rear == q.size-1)
        return true;
    else
        return false;
}


int main()
{
    struct Queue q;
    printf("Enter size of queue: ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;
    q.arrForQueue = (int*)malloc(q.size * sizeof(int));

    display(q);
    for(int i = 0; i<15; i++){
        enqueue(&q, i+1);
        display(q);
    }

    for(int i = 0; i<12; i++){
        deque2(&q);
        display(q);
    }



    for(int i = 0; i<4; i++){
        enqueue(&q, i+1);
        display(q);
    }
    for(int i = 0; i<6; i++){
        deque2(&q);
        display(q);
    }


    return 0;
}
