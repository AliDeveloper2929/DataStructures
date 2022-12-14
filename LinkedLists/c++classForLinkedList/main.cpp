#include <iostream>

using namespace std;


class Node{
public:
    int data;
    Node* next;
};


class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();
    void display_LL();
    void insert_At_Index(int index, int num);
    void Delete(int index);
    int Delete_And_Get(int index);
    int count_Nodes_In_LL();
};

void LinkedList::display_LL(){
    Node* p = head;
    if(head == NULL){
        printf("There is no element in Linked List\n");
        return;
    }
    printf("Elements of Linked List: ");
    while(p!= NULL){
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}


void LinkedList::insert_At_Index(int index, int num){
    if(head == NULL){
        if(index == 0){
            Node* newNode = new Node;
            newNode->data = num;
            newNode->next = head;
            head = newNode;
        }
        else
            printf("The linked list is empty, so give only 0 as an index\n");

        return;
    }

    Node* temp = head;
    if(index == 0){
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = head;
        head = newNode;
        return;
    }
    if(index < 0){
        printf("Index must be greater than or equal to 0\n");
        return;
    }

    for(int i = 0; i<index-1; i++){
        temp = temp->next;
        if(temp == NULL){
            printf("You gave higher index, give index less than or equal to %d\n", i+1);
            return;
        }
    }
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = temp->next;
    temp->next = newNode;
}


void LinkedList::Delete(int index){
    if(head == NULL){
        printf("There is no element in Linked List to delete\n");
        return;
    }
    if(index < 0){
        printf("Index must be greater than or equal to 0\n");
        return;
    }
    if(index == 0){ //means deleting first node
        Node* temp = head; // this temp is for freeing the memory
        head = head->next;
        delete temp;
    }
    else{
        Node* deletableNode = head;
        Node* Node_Before_Deletable = NULL;
        for(int i = 0; i<index; i++){
            Node_Before_Deletable = deletableNode;
            deletableNode = deletableNode->next;
            if(deletableNode == NULL){
                printf("There is no element with index %d, give index less than or equal to %d\n", index,  i);
                return;   // if index is high, we return head without any changes.
            }
        }
        Node_Before_Deletable->next = deletableNode->next;
        delete deletableNode;
    }
    return;
}


int LinkedList::Delete_And_Get(int index){
    int deletedNode;
    if(head == NULL){
        printf("There is no element in Linked List to delete\n");
        return -1;
    }
    if(index < 0){
        printf("Index must be greater than or equal to 0\n");
        return -1;
    }
    if(index == 0){ //means deleting first node
        deletedNode = head->data;
        Node* temp = head; // this temp is for freeing the memory
        head = head->next;
        delete temp;
    }
    else{
        Node* deletableNode = head;
        Node* Node_Before_Deletable = NULL;
        for(int i = 0; i<index; i++){
            Node_Before_Deletable = deletableNode;
            deletableNode = deletableNode->next;
            if(deletableNode == NULL){
                printf("There is no element with index %d, give index less than or equal to %d\n", index,  i);
                return -1;   // if index is high, we return head without any changes.
            }
        }
        deletedNode = deletableNode->data;
        Node_Before_Deletable->next = deletableNode->next;
        delete deletableNode;
    }
    return deletedNode;
}


int LinkedList::count_Nodes_In_LL(){  // T = O(n)  S = O(1)
    int countOfNodes = 0;
    Node* temp = head;
    while(temp != NULL){
        countOfNodes++;
        temp = temp->next;
    }
    return countOfNodes;
}

LinkedList::LinkedList(int A[], int n){
    Node* temp = head;
    for(int i = 0; i<n; i++){
        if(head !=NULL){
            Node* newNode = new Node;
            newNode->data = A[i];
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
        }
        else{
            Node* newNode = new Node;
            newNode->data = A[0];
            newNode->next = NULL;
            head = newNode;
            temp = head;
        }
    }
}

LinkedList::~LinkedList(){  // this is for deleting elements of Linked List.
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }
}



int main()
{

    int A[] = {1, 4, 8, -9, 12, 25, 32, 17};
    int lenA = sizeof(A)/sizeof(int);

    LinkedList* head1 = new LinkedList(A, lenA);
    head1->display_LL();
    head1->insert_At_Index(0, 25);
    //head1.display_LL();
    head1->insert_At_Index(0, 8);
    head1->display_LL();
    head1->~LinkedList();
    head1->display_LL();
    //head1.Delete(2);


    //printf("Count is %d\n", head1.count_Nodes_In_LL());




   /* LinkedList* head2 = new LinkedList();
    LinkedList* head3 = new LinkedList;
    head2->insert_At_Index(0, 78);
    head2->insert_At_Index(0, 8);
    head2->display_LL();
    head2->Delete(1);
    head2->display_LL();
    //head3->display_LL();
    */
    return 0;
}
