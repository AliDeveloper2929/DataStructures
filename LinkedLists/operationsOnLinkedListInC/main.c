#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


struct Node{
    int data;
    struct Node* next;
};

// prototypes of functions:
struct Node* getNewNode(int data);  // T = S = O(1);
struct Node* createLinkedList_1(struct Node* head, int A[], int n);//add elements of array A to the end of the linked list
struct Node* createLinkedList_2(struct Node* head, int A[], int n);// this one is better than the previous one
void displayLinkedList(struct Node* head);  // T = O(n)  n=>number of nodes in LL.  S= O(1);
void displayUsingRecursion(struct Node* head); // T = O(n)   S = O(n)   n=> number of nodes in Linked list
void display_Reversely_Using_Recursion(struct Node* head); // T = O(n)   S = O(n)   n=> number of nodes in Linked list
int count_Nodes_In_LL(struct Node* head);  // T = O(n)  S = O(1)
int count_Nodes_Using_Recursion(struct Node* head); // S = O(n)   T = O(n);
int sum_Of_Ele_In_LL(struct Node* head);             // using loop.  T = O(n)   S = O(1),
int sum_Of_Elements_Using_Recur(struct Node* head);   // S = T = O(n)
int get_Max_From_LL(struct Node* head);   // using loop.  T = O(n), S = O(1).
int get_Max_Using_Recur(struct Node* head);  // T = S = O(n)
int get_Min_Using_Recur(struct Node* head);
int get_Min_From_LL(struct Node* head);
struct Node* search_And_GetAddres(struct Node* head, int num); // this returns the address of the key element if exists. else null
int Search(struct Node* head, int num); // this returns the index of the key element.
struct Node* search_Using_Recur(struct Node* head, int num); // this returns the address of key element
struct Node* moveNodeToHead(struct Node* head, int num);
struct Node* moveNodeToHead2(struct Node* head, int num);
struct Node* insert_AtPosition_N(struct Node* head, int num, int position); //if pos == 1 => means index 0 or the first Node.  T = O(n)
struct Node* insert_AtIndex_N(struct Node* head, int num, int index); // if index == 0  =-> means first or head node.
struct Node* insert_In_Sorted_LL(struct Node* head, int num); // T = O(n)   S = O(1)
struct Node* deleteNode_AtIndex_N(struct Node* head, int index); // this returns pointer to head Node after deleting num at index 'index'  T = O(n)
int delete_And_Get_Node_AtIndex_N(struct Node* head, int index); // this deletes element at index 'index' and returns its value    T = O(n)
bool is_LL_Sorted(struct Node* head);
struct Node* removeDuplicates(struct Node* head);      // this works for both unsorted and sorted Linked list.  T = O(n ^ 2);
struct Node* removeDuplicatesFromSortedLL(struct Node* head);   // this is only for sorted LL. T = O(n), S = O(1)
struct Node* reverse_LL_byLinks(struct Node* head);    // T = O(n)  instead of swapping datas , we prefer modifying links
struct Node* reverse_LL_ByElements(struct Node* head);   // T = O(n)
struct Node* reverse_LL_Using_Recur(struct Node* head, struct Node* prevNode);  // give NULL as an argument to prevNode
struct Node* concetanate_Linked_Lists(struct Node* head1, struct Node* head2);
struct Node* merge_Linked_Lists(struct Node* head1, struct Node* head2);   // T = O(m+n)
bool is_LL_Loop(struct Node* head);
int get_MidElement_In_LL_1(struct Node* head);
int get_MidElement_In_LL_2(struct Node* head);



struct Node* getNewNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


void displayLinkedList(struct Node* head){
    printf("\nElements of Linked List are: ");
    while(head != NULL){
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}


/*We add elements of array A to the end of the linked list. This is for linked list whose head Node is declared in main function, locally*/
struct Node* createLinkedList_1(struct Node* head, int A[], int n){
    for(int i=0; i<n; i++){
        if(head == NULL){
            head = getNewNode(A[i]);
        }
        else{
            struct Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = getNewNode(A[i]);
        }
    }
    return head;
}


// this one is better than the previous one
struct Node* createLinkedList_2(struct Node* head, int A[], int n){
    if(head == NULL){
        head = getNewNode(A[0]);
        struct Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        for(int i = 1; i< n; i++){
            temp->next = getNewNode(A[i]);
            temp = temp->next;
        }
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        for(int i=0; i<n; i++){
            temp->next = getNewNode(A[i]);
            temp = temp->next;
        }
    }
    return head;
}

void displayUsingRecursion(struct Node* head){
    if(head == NULL){     // this is for termination base for recursion
        printf("\n");
        return;
    }
    printf("%d, ", head->data);
    displayUsingRecursion(head->next);
}
//  or
void displayUsingRecursion_2(struct Node* head){
    if(head != NULL){     // this is for continuation base for recursion
        printf("%d, ", head->data);
        displayUsingRecursion_2(head->next);
    }
}

void display_Reversely_Using_Recursion(struct Node* head){
    if(head != NULL){
        display_Reversely_Using_Recursion(head->next);
        printf("%d, ", head->data);
    }
}


// below function returns number of nodes in a linked list
int count_Nodes_In_LL(struct Node* head){  // T = O(n)  S = O(1)
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

int count_Nodes_Using_Recursion(struct Node* head){
    if(head != NULL){
        return count_Nodes_Using_Recursion(head->next) + 1;
    }
    return 0;
}


// below function returns the sum of all the elements in a linked list.
int sum_Of_Ele_In_LL(struct Node* head){
    int sum = 0;
    while(head != NULL){
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int sum_Of_Elements_Using_Recur(struct Node* head){
    if(head == NULL){
        return 0;
    }
    else{
        return head->data + sum_Of_Elements_Using_Recur(head->next);
    }
}


int get_Max_From_LL(struct Node* head){
    if(head == NULL){
        printf("The Linked List is empty.\n");
        return 0;
    }
    int maxNum = head->data;
    while(head != NULL){
        if(head->data > maxNum)
            maxNum = head->data;
        head = head->next;
    }
    return maxNum;
}

int get_Max_Using_Recur(struct Node* head){
    if(head == NULL)
        return -2147483648;
    else{
        int val_Of_Curr_Node = head->data;
        int returnedMax = get_Max_Using_Recur(head->next);
        return val_Of_Curr_Node > returnedMax ? val_Of_Curr_Node : returnedMax;
    }
}


int get_Min_From_LL(struct Node* head){
    if(head == NULL){
        printf("There is no element in Linked List\n");
        return 0;
    }
    int min = head->data;
    while(head != NULL){
        if(head ->data < min)
            min = head->data;
        head = head->next;
    }
    return min;
}

int get_Min_Using_Recur(struct Node* head){
    if(head == NULL){
        return 2147483647;
    }
    else{
        int returnedVal = get_Min_From_LL(head->next);
        return head->data < returnedVal ? head->data : returnedVal;
    }
}



// if num exists in Linked List, functions returns the index of num in linked list else returns 0;
int Search(struct Node* head, int num){
    if(head == NULL){
        printf("The Linked List is empty. No element\n");
        return -1;
    }
    int index = 0;
    while(head != NULL){
        if(head->data == num){
            return index;
        }
        else{
            index++;
            head = head->next;
        }
    }
    printf("The number %d is not found from Linked List\n", num);
    return -1;
}


struct Node* search_And_GetAddres(struct Node* head, int num){
    if(head == NULL){
        printf("The Linked List is empty. No element\n");
        return NULL;
    }
    while(head != NULL){
        if(head->data == num)
            return head;
        else
            head = head->next;
    }
    printf("The number %d is not found from Linked List\n", num);
    return NULL;
}

struct Node* search_Using_Recur(struct Node* head, int num){
    if(head == NULL)
        return NULL;
    if(head->data == num)
        return head;
    else
        return search_Using_Recur(head->next, num);
}


// this function moves Node with value num to head Node.
struct Node* moveNodeToHead(struct Node* head, int num){
    if(head == NULL) return NULL;
    if(head->data == num){
        return head;
    }
    // below statements are executed only when the linked list is not empty and the key element is not in 1st node. If LL is empty or num is in head node below isn't executed.
    struct Node* temp1 = head;        // temp1 is pointer to head node
    struct Node* temp2 = head->next;  // temp2 is pointer to node after head node.
    while(temp2 != NULL){
        if(temp2->data == num){
            temp1->next = temp2->next;
            temp2->next = head;
            head = temp2;
            return head;
        }
        else{
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    return NULL;
}


//
struct Node* moveNodeToHead2(struct Node* head, int num){
    struct Node* prev = NULL;
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->data != num){
            prev = temp;
            temp = temp->next;
        }
        else{
            prev->next = temp->next;
            temp->next = head;
            head = temp;
            return head;
        }
    }
    printf("Element not found");
    return NULL;
}



struct Node* insert_AtPosition_N(struct Node* head, int num, int position){
    if(head == NULL){
        if(position == 1){ // we insert at head node
            head = (struct Node*)malloc(sizeof(struct Node));
            head->data = num;
            head->next = NULL;
            return head;
        }
        printf("\nThere is no element in Linked List. So you can only insert at position 1\n");
        return NULL;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;

    if(position == 1){ // insert at beginning
        temp->next = head;
        head = temp;
    }
    else if(position < 1){
        printf("\nThe min position to insert element in Linked List is 1 which is head Node.\nPosition 1 means the first or head node in Linked List\n");
        return head;
    }
    else{
        struct Node* tempToTraverse = head;
        // Ex: if pos = 3 and Linked List is: Node1, Node2,        Node3, Node4. Result: Node1, Node2, NodeTemp, Node3, Node4
        // which means if pos = n, I have to go n-1 th Node.
        for(int i = 1; i<position-1; i++){ //  if pos == 3, this loop executes 2 times. So after loop ends, tempToTraverse points to Node
            tempToTraverse = tempToTraverse->next;
            if(tempToTraverse == NULL){
                printf("\nThere are only %d elements in Linked List. So you can insert new element at max position %d\n", i, i+1);
                return head;
            }
        }
        temp->next = tempToTraverse->next;
        tempToTraverse->next = temp;
    }
    return head;
}

struct Node* insert_AtIndex_N(struct Node* head, int num, int index){
    if(head == NULL){
        if(index == 0){ // we insert at head node
            head = (struct Node*)malloc(sizeof(struct Node));
            head->data = num;
            head->next = NULL;
            return head;
        }
        printf("\nThere is no element in Linked List. So you can only insert at index 0\n");
        return NULL;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;

    if(index == 0){ // insert at beginning
        temp->next = head;
        head = temp;
    }
    else if(index < 0){
        printf("\nThe min index to insert element in Linked List is 0 which is head Node.\nIndex 0 means the first or head node in Linked List\n");
        return head;
    }
    else{
        struct Node* tempToTraverse = head;
        // Ex: if index = 3 and Linked List is: Node1, Node2, Node3,        Node4. Result: Node1, Node2, Node3, NodeTemp, Node4
        // which means if index = n, I have to go n th Node which is at index n-1.
        for(int i = 0; i<index-1; i++){ //  if index == 3, this loop executes 2 times. So after loop ends, tempToTraverse points to Node
            tempToTraverse = tempToTraverse->next;
            if(tempToTraverse == NULL){
                printf("\nThere are only %d elements in Linked List. So you can insert new element at max index %d\n", i+1, i+1);
                return head;
            }
        }
        temp->next = tempToTraverse->next;
        tempToTraverse->next = temp;
    }
    return head;
}



struct Node* insert_At_Last(struct Node* head, int num){
    if(head == NULL){
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = num;
        head ->next = NULL;
    }
    else{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;
        struct Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}


// below function is for only sorted linked list.
struct Node* insert_In_Sorted_LL(struct Node* head, int num){
    if(!is_LL_Sorted(head)){
        printf("This function is only for sorted Linked List. Given Linked List is unsorted\n ");
        return head;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;

    if(head == NULL || num < head->data){
        newNode->next = head;
        head = newNode;
    }
    else{
        struct Node* temp = head;
        struct Node* nodeBefore_temp = NULL;
        while(temp!=NULL && num >= temp->data){
            nodeBefore_temp = temp;
            temp = temp->next;
        }// when this loop exits , it means either all elements are less than num (this is when temp == NULL) or appropriate position is found for num (this is when num < temp->data).
        nodeBefore_temp->next = newNode;
        newNode->next = temp;
    }
    return head;
}



struct Node* deleteNode_AtIndex_N(struct Node* head, int index){ //if index== 0: delete headNode
    if(head == NULL){
        printf("There is no element in Linked List to delete\n");
    }
    else if(index < 0) printf("Index must be greater than or equal to 0\n");
    else if(index == 0){ //means deleting first node
        struct Node* temp = head; // this temp is for freeing the memory
        head = head->next;
        free(temp);
    }
    else{
        struct Node* deletableNode = head;
        struct Node* Node_Before_Deletable = NULL;
        for(int i = 0; i<index; i++){
            Node_Before_Deletable = deletableNode;
            deletableNode = deletableNode->next;
            if(deletableNode == NULL){
                printf("There is no element with index %d, give index less than or equal to %d\n", index,  i);
                return head;   // if index is high, we return head without any changes.
            }
        }
        Node_Before_Deletable->next = deletableNode->next;
        free(deletableNode);
    }
    return head;
}


int delete_And_Get_Node_AtIndex_N(struct Node* head, int index){ //if index== 0: delete headNode and return value of deleted node
    int deletedNode;
    if(head == NULL){
        printf("There is no element in Linked List to delete\n");
    }
    else if(index < 0) printf("Index must be greater than or equal to 0\n");
    else if(index == 0){ //means deleting first node
        deletedNode = head->data;
        struct Node* temp = head; // this temp is for freeing the memory
        head = head->next;
        free(temp);
    }
    else{
        struct Node* deletableNode = head;
        struct Node* Node_Before_Deletable = NULL;
        for(int i = 0; i<index; i++){
            Node_Before_Deletable = deletableNode;
            deletableNode = deletableNode->next;
            if(deletableNode == NULL){
                printf("There is no element with index %d, give index less than or equal to %d\n", index,  i);
                return head;   // if index is high, we return head without any changes.
            }
        }
        deletedNode = deletableNode->data;
        Node_Before_Deletable->next = deletableNode->next;
        free(deletableNode);
    }
    return deletedNode;
}


bool is_LL_Sorted(struct Node* head){
    if(head == NULL){
        printf("The Linked List is empty\n");
        return false;
    }
    if(head->next == NULL) return true;
    else{
        while(head->next != NULL){
            if(head->data > head->next->data)
                return false;
            head = head->next;
        }
        return true;
    }
}


// this function removes duplicates in LL and returns the head node.
struct Node* removeDuplicates(struct Node* head){
    struct Node* temp1 = head;
    while(temp1 != NULL){
        if(temp1->next == NULL)
            return head;
        struct Node* temp2 = temp1->next;
        struct Node* nodeBeforeTemp2 = temp1;
        while(temp2 != NULL){
            if(temp1->data == temp2->data){
                // temp2 is now deletable node.
                struct Node* deletableNode = temp2;
                nodeBeforeTemp2 ->next = temp2->next;
                temp2 = temp2->next;
                free(deletableNode);

            }
            else{
                nodeBeforeTemp2 = temp2;
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    return head;
}



struct Node* removeDuplicatesFromSortedLL(struct Node* head){
    if(head == NULL){
        printf("There is no element in a Linked List\n");
        return head;
    }
    if(!is_LL_Sorted(head)){
        printf("Given Linked List is unsorted. Give Sorted Linked List(from min to max)\n");
        return head;
    }
    struct Node* temp = head;
    struct Node* nodeAfter_temp = temp->next;
    while(nodeAfter_temp != NULL){
        if(temp->data != nodeAfter_temp->data){
            temp = nodeAfter_temp;
            nodeAfter_temp = nodeAfter_temp->next;
        }
        else{
            // remove nodeAfter_temp
            temp->next = nodeAfter_temp->next;
            free(nodeAfter_temp);
            nodeAfter_temp = temp->next;
        }
    }
    return head;
}



struct Node* reverse_LL_byLinks(struct Node* head){
    if(head == NULL){
        printf("The linked list is empty\n");
        return head;
    }
    struct Node* prevNode = NULL;
    struct Node* currentNode = head;
    struct Node* nextNode;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

struct Node* reverse_LL_Using_Recur(struct Node* head, struct Node* prevNode){
    if(head == NULL){
        return prevNode;
    }
    struct Node* temp = reverse_LL_Using_Recur(head->next, head);
    head->next = prevNode;
    return temp;
}



struct Node* reverse_LL_ByElements(struct Node* head){
    if(head == NULL){
        printf("The linked list is empty\n");\
        return head;
    }
    int lengthOfLL = count_Nodes_In_LL(head);
    int* A = (int*)malloc(lengthOfLL * sizeof(int));
    int i = lengthOfLL-1;
    struct Node* temp = head;
    while(temp != NULL){
        A[i--] = temp->data;
        temp = temp->next;
    }
    temp = head;
    i = 0;
    while(temp != NULL){
        temp->data = A[i++];
        temp = temp->next;
    }
    return head;
}


// this appends elements of head2 Linked list to the end of the head1 linked list.
struct Node* concetanate_Linked_Lists(struct Node* head1, struct Node* head2){
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    struct Node* temp = head1;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}




struct Node* merge_Linked_Lists(struct Node* head1, struct Node* head2){
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    struct Node* merged_LL = NULL;
    struct Node* temp = merged_LL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            if(merged_LL != NULL){
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
            else{
                merged_LL = head1;
                temp = merged_LL;
                head1 = head1->next;
            }
        }
        else{
            if(merged_LL != NULL){
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
            }
            else{
                merged_LL = head2;
                temp = merged_LL;
                head2 = head2->next;
            }
        }
    }

    if(head1 ==  NULL)
        temp->next = head2;
    else
        temp->next = head1;
    return merged_LL;
}


bool is_LL_Loop(struct Node* head){
    struct Node* temp1 = head;
    do{
        head = head->next;

        temp1 = temp1->next;
        if(temp1 == NULL)
            return false;

        temp1 = temp1->next;
        if(temp1 == NULL)
            return false;
    }while(head != temp1);
    return true;
}

int get_MidElement_In_LL_1(struct Node* head){
    int length = count_Nodes_In_LL(head);
    // we return node at index length/2
    struct Node* temp = head;
    for(int i = 0; i<length/2; i++){
        temp = temp->next;
    }
    return temp->data;
}


int get_MidElement_In_LL_2(struct Node* head){
    if(head == NULL){
        printf("The Linked List is empty. Head node is NULL\n");
        return -1;
    }
    struct Node* midNode = head;
    struct Node* lastNode = head;
    while(true){
        if(lastNode->next == NULL)
            return midNode->data;
        midNode = midNode->next;
        lastNode = lastNode->next;
        if(lastNode->next ==NULL) return midNode->data;
        lastNode = lastNode->next;
    }
}


int main()
{

    struct Node* head2 = NULL;

    int A[] = {1, 8, 9, 17, 25, 312, 425, 1020, 2000, 3000, 25000, 30000, 125200};

    int lenA = sizeof(A) / sizeof(int);

    head2 = createLinkedList_1(head2, A, lenA);
    printf("Mid element is %d\n", get_MidElement_In_LL_1(head2));
    printf("Mid element is %d", get_MidElement_In_LL_2(head2));

    //head = deleteNode_AtIndex_N(head, 2);
    //displayLinkedList(head);
    //printf("Dleted Node is %d\n", delete_And_Get_Node_AtIndex_N(head, 14));
    //displayLinkedList(head);






    return 0;
}
