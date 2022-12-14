#ifndef QUEUECPP_H_INCLUDED
#define QUEUECPP_H_INCLUDED
#include <stdbool.h>

class TreeNode{
public:
    TreeNode* lChild;
    TreeNode* rChild;
    int data;
};


class QueueForAddrOfTree{
private:
    int sizeQ;
    int frontQ;
    int rearQ;
    TreeNode** arrForQ;
public:
    QueueForAddrOfTree(){frontQ = rearQ = 0; sizeQ = 50; arrForQ = new TreeNode*[sizeQ];};
    QueueForAddrOfTree(int sizeOfQ);
    void createQueue(int sizeOfQ);
    void enqueue(TreeNode* node);
    TreeNode* dequeue();
    bool isEmpty();
};


void QueueForAddrOfTree::createQueue(int sizeOfQ){
    frontQ = rearQ = 0;
    sizeQ = sizeOfQ;
    arrForQ = new TreeNode*[sizeQ];
}



void QueueForAddrOfTree::enqueue(TreeNode* node){
    if(rearQ == sizeQ-1 && frontQ == 0){
        printf("There is no space in queue, queue is full\n");
    }
    else if(frontQ - rearQ == 1){
         printf("There is no space in queue, queue is full\n");
    }
    else{
        if(rearQ == sizeQ-1)
            rearQ = -1;
        rearQ++;
        arrForQ[rearQ] = node;
    }
}

TreeNode* QueueForAddrOfTree::dequeue(){
    TreeNode* returningNode = NULL;
    if(frontQ == rearQ){
        printf("The queue is empty no element at queue\n");
    }
    else{
        if(frontQ == sizeQ-1)
            frontQ = -1;
        returningNode = arrForQ[++frontQ];
    }
    return returningNode;
}

bool QueueForAddrOfTree::isEmpty(){
    return frontQ == rearQ ;
}



#endif // QUEUECPP_H_INCLUDED
