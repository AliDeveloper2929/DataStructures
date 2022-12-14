#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdbool.h>

struct TreeNode{
    struct TreeNode* lChild;
    struct TreeNode* rChild;
    int data;
};


struct QueueForAddrOfTree{
    int sizeQ;
    int frontQ;
    int rearQ;
    struct TreeNode** arrForQ;
};


void createQueue(struct QueueForAddrOfTree* q, int sizeOfQ){
    q->frontQ = q->rearQ = 0;
    q->sizeQ = sizeOfQ;
    q->arrForQ = (struct TreeNode**)malloc( q->sizeQ * sizeof(struct TreeNode*) );
}



void enqueue(struct QueueForAddrOfTree* q, struct TreeNode* node){
    if(q->rearQ == q->sizeQ-1 && q->frontQ == 0){
        printf("There is no space in queue, queue is full\n");
    }
    else if(q->frontQ - q->rearQ == 1){
         printf("There is no space in queue, queue is full\n");
    }
    else{
        if(q->rearQ == q->sizeQ-1)
            q->rearQ = -1;
        q->rearQ++;
        q->arrForQ[q->rearQ] = node;
    }
}

struct TreeNode* dequeue(struct QueueForAddrOfTree* q){
    struct TreeNode* returningNode = NULL;
    if(q->frontQ == q->rearQ){
        printf("The queue is empty no element at queue\n");
    }
    else{
        if(q->frontQ == q->sizeQ-1)
            q->frontQ = -1;
        returningNode = q->arrForQ[++q->frontQ];
    }
    return returningNode;
}

bool isEmpty(struct QueueForAddrOfTree q){
    return q.frontQ == q.rearQ ;
}




#endif // QUEUE_H_INCLUDED
