#include <iostream>
#include <stack>

using namespace std;

class Queue{
private:
    stack<int> e_stk;
    stack<int> d_stk;
public:
    Queue(){};
    ~Queue(){};
    void enqueue(int num);
    int dequeue();
};

void Queue::enqueue(int num){
    e_stk.push(num);
}

int Queue::dequeue(){
    if(d_stk.empty()){
        if(e_stk.empty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            while(!e_stk.empty()){
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }

    int dequeuedEle = d_stk.top();
    d_stk.pop();
    return dequeuedEle;
}

int main() {

    int A[] = {1, 3, 5, 7, 9};
    int lenA = sizeof(A)/sizeof(A[0]);
    Queue q;

    cout << "Enqueue: " << flush;
    for (int i=0; i<lenA; i++){
        q.enqueue(A[i]);
        cout << A[i] << flush;
        if (i < lenA-1){
            cout << " <- " << flush;
        }
    }
    cout << endl;

    cout << "Dequeue: " << flush;
    for (int i=0; i<lenA; i++){
        cout << q.dequeue() << flush;
        if (i < lenA-1){
            cout << " <- " << flush;
        }
    }

    return 0;
}


