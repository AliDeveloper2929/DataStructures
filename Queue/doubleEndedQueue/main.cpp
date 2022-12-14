#include <iostream>

using namespace std;


class DEQueue{
private:
    int Front;
    int rear;
    int sizeOfQ;
    int* Q;

public:
    DEQueue(int sizeOfQ);
    ~DEQueue();
    void display();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();
};

DEQueue::DEQueue(int sizeOfQ) {
    this->sizeOfQ = sizeOfQ;
    Front = -1;
    rear = -1;
    Q = new int [sizeOfQ];
}

DEQueue::~DEQueue() {
    delete [] Q;
}

bool DEQueue::isEmpty() {
    if (Front == rear){
        return true;
    }
    return false;
}

bool DEQueue::isFull() {
    if (rear == sizeOfQ - 1){
        return true;
    }
    return false;
}

void DEQueue::enqueueFront(int x) {
    if (Front == -1){
        cout << "DEQueue Overflow" << endl;
    }
    else {
        Q[Front] = x;
        Front--;
    }
}

void DEQueue::enqueueRear(int x) {
    if (isFull()){
        cout << "DEQueue Overflow" << endl;
    }
    else {
        rear++;
        Q[rear] = x;
    }
}

int DEQueue::dequeueFront() {
    int x = -1;
    if (isEmpty()){
        cout << "DEQueue Underflow" << endl;
    }
    else {
        x = Q[++Front];
    }
    return x;
}

int DEQueue::dequeueRear() {
    int x = -1;
    if (rear == -1){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}

void DEQueue::display() {
    for (int i=Front+1; i<=rear; i++) {
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main() {

    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    DEQueue deq(sizeof(A)/sizeof(A[0]));

    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);

    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();

    cout << endl;

    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);

    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();

    return 0;
}
