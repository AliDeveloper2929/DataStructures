#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node* topNode;
public:
    Stack(){
        topNode = NULL;
    }
    void push(int num);
    int pop();
    int getTop();
    bool isEmpty();
    int get_Nth_element(int position);
    void display();
};

void Stack::push(int num){
    Node* newNode = new Node;
    if(newNode == NULL){
        printf("Stack is full.\n");
    }
    else{
        newNode->data = num;
        newNode->next = topNode;
        topNode = newNode;
    }
    return;
}

int Stack::pop(){
    int poppedEle = -1;
    if(topNode == NULL){
        printf("Stack underFlow. No element is stack to pop\n");
    }
    else{
        Node* deletable = topNode;
        poppedEle = topNode->data;
        topNode = topNode->next;
        delete deletable;
    }
    return poppedEle;
}


// this returns top element without deleting it
int Stack::getTop(){
    int top = -1;
    if(topNode == NULL){
        printf("Stack UnderFlow, no element at top\n");
    }
    else{
        top = topNode->data;
    }
    return top;
}

bool Stack::isEmpty(){
    if(topNode == NULL){
        return true;
    }
    else return false;
}

// this function does not delete any element from stack.
int Stack::get_Nth_element(int position){
    int result = -1;
    if(position < 1){
        printf("Give at least position 1 which is top element in stack\n");
    }
    else if(topNode == NULL){
        printf("There is no element in stack\n");
    }
    else{
        Node* temp = topNode;
        for(int i = 0; i<position-1; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("Give position between 1 and %d\n", i+1);
                return -1;
            }
        }
        result = temp->data;
    }
    return result;
}

void Stack::display(){
    if(topNode == NULL){
        printf("There is no element in Stack.\n");
    }
    else{
        Node* temp = topNode;
        printf("Elements of stack: ");
        while(temp != NULL){
            printf("%d, ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    Stack stk;
  //  stk.display();
    for(int i = 0; i<25; i++){
        stk.push(i+1);
        //stk.display();
    }
    int num = stk.get_Nth_element(25);

    Stack* stk2 = new Stack();
    stk2->display();
    for(int i = 0; i<25; i++){
        stk2->push(i+1);
        stk2->display();
    }
    return 0;
}
