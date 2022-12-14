#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};


// prototypes of functions:
bool is_LL_Circular(struct Node* head);
void display_Cicular_LL(struct Node* head);
void display_Circular_LL_Recur(struct Node* head);
struct Node* create_Circular_LL(struct Node* head, int A[], int n);
struct Node* insert_In_Circular_LL(struct Node* head, int num, int index);
struct Node* delete_InCircular_LL(struct Node* head, int index);



bool is_LL_Circular(struct Node* head){
    if(head ==NULL){
        printf("The Linked List is empty\n");
        return false;
    }
    struct Node* temp = head;
    while(temp->next !=head){
        if(temp->next == NULL)
            return false;
        temp = temp->next;
    }
    return true;
}

void display_Cicular_LL(struct Node* head){

    if(head ==NULL){
        printf("The Circular Linked List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("\nElements of Circular Linked List: ");
    do{
        printf("%d, ", temp->data);
        temp = temp->next;
    }while(temp !=head);

    return;
}

/*void display_Circular_LL_Recur(struct Node* head){
    static int flag = 0;
    static struct Node* staticHead = head;
    if(head != staticHead || flag == 0){
        flag = 1;
        printf("%d, ", head->data);
        display_Circular_LL_Recur(head->next);
    }
    flag = 0;
}
*/

struct Node* create_Circular_LL(struct Node* head, int A[], int n){
    struct Node* temp = head;
    for(int i = 0; i<n; i++){
        if(head !=NULL){
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = A[i];
            newNode->next = head;
            temp->next = newNode;
            temp = temp->next;
        }
        else{
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = A[0];
            newNode->next = newNode;
            head = newNode;
            temp = head;
        }
    }
    return head;
}


struct Node* insert_In_Circular_LL(struct Node* head, int num, int index){
    if(index<0){
        printf("Index cannot be less than 0\n");\
        return head;
    }

    if(head == NULL){
        if(index == 0){
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = num;
            newNode->next = newNode;
            head = newNode;
        }
        else
            printf("The Circular Linked List is empty, so give index 0 only\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;

    if(index == 0){
        newNode->next = head;
        head = newNode;
        struct Node* temp = head->next;

        while(temp->next != head->next)
            temp = temp->next;
        temp->next = head;
        // return head;
    }
    else{
        struct Node* temp = head;
        for(int i = 0; i<index-1; i++){
            temp = temp->next;
            if(temp->next == head && i+1 == index-1){
                temp->next = newNode;
                newNode->next = head;
                return head;
            }
            if(temp == head ){
                printf("The index is high. Give less than or equal to %d\n", i+1);
                return head;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}


struct Node* delete_InCircular_LL(struct Node* head, int index){ //if index== 0: delete headNode
    if(head == NULL){
        printf("There is no element in Linked List to delete\n");
        return head;
    }
    if(index < 0){
        printf("Index must be greater than or equal to 0\n");
        return head;
    }
    if(index == 0){ //means deleting first node
        struct Node* temp = head; // this temp is for freeing the memory
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        temp = head;
        head = head->next;
        free(temp);
        // return head;
    }
    else{
        struct Node* deletableNode = head;
        struct Node* Node_Before_Deletable = NULL;
        for(int i = 0; i<index; i++){
            Node_Before_Deletable = deletableNode;
            deletableNode = deletableNode->next;
            if(deletableNode->next == head && i == index){
                Node_Before_Deletable->next = head;
                free(deletableNode);
                return head;
            }
            if(deletableNode == head){
                printf("There is no element with index %d, give index less than or equal to %d\n", index,  i);
                return head;   // if index is high, we return head without any changes.
            }
        }
        Node_Before_Deletable->next = deletableNode->next;
        free(deletableNode);
    }
    return head;
}



int main()
{
    int A[] = {1, 5, 2, 3, 4, 7, 8, 9};
    int lenA = sizeof(A)/sizeof(int);
    struct Node* head = NULL;

    head = create_Circular_LL(head, A, lenA);

    display_Cicular_LL(head);
    head = delete_InCircular_LL(head, 12);
    display_Cicular_LL(head);

    if(is_LL_Circular(head))printf("Circular");
    else printf("vcfds");


    return 0;
}
