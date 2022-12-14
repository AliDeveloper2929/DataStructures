#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* getNewNode(int num);
void display_Doubly_LL(struct Node* head);
struct Node* insert_In_Doubly_LinkedList(struct Node* head, int num, int index);
struct Node* delete_In_Doubly_LL(struct Node* head, int index);
struct Node* reverse_Doubly_LL(struct Node* head);






struct Node* getNewNode(int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void display_Doubly_LL(struct Node* head){
    if(head == NULL){
        printf("The Doubly Linked List is empty\n");
        return;
    }
    printf("The elements of doubly linked list: ");
    while(head != NULL){
        printf("%d, ", head->data);
        head = head->next;
    }
}

struct Node* insert_In_Doubly_LinkedList(struct Node* head, int num, int index){
    if(head == NULL){
            if(index != 0)
                printf("The Doubly Linked List is empty. So give index 0 only\n");
            else{
                struct Node* newNode = getNewNode(num);
                newNode->next = head;
                head = newNode;
            }
            return head;
    }
    if(index < 0){
        printf("Index cannot be less than 0\n");
        return head;
    }
    struct Node* newNode = getNewNode(num);
    if(index == 0){
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else{
        struct Node* nodeBeforeTemp = NULL;
        struct Node* temp = head;
        for(int i = 0; i<index; i++){
            nodeBeforeTemp = temp;
            temp = temp->next;
            if(temp == NULL && i+1 == index){
                nodeBeforeTemp->next = newNode;
                newNode->prev = nodeBeforeTemp;
                return head;
            }
            if(temp == NULL && i+2 <= index){
                printf("You gave higher index. Give index less than %d\n", i+2);
                return head;
            }
        }
        temp->prev = newNode;
        newNode->next = temp;
        newNode->prev = nodeBeforeTemp;
        nodeBeforeTemp->next = newNode;
    }
    return head;
}


struct Node* delete_In_Doubly_LL(struct Node* head, int index){
    if(head == NULL){
        printf("There is no element in Doubly Linked List to delete\n");
        return head;
    }
    if(index == 0){
        struct Node* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else{
        struct Node* temp = head;
        struct Node* before_temp = NULL;
        for(int i = 0; i<index; i++){
            before_temp = temp;
            temp = temp->next;
            if(temp ->next == NULL && i+1 == index){
                //delete last node which is temp;
                before_temp ->next = NULL;
                free(temp);
                return head;
            }
            if(temp->next == NULL){
                printf("You gave higher index, give index less than %d", i+2);
                return head;
            }
        }
        struct Node* nodeAfterTemp = temp->next;
        nodeAfterTemp->prev = before_temp;
        before_temp->next = nodeAfterTemp;
        free(temp);
    }
    return head;
}

struct Node* reverse_Doubly_LL(struct Node* head){
    if(head == NULL){
        printf("The Doubly Linked List is empty\n");
        return head;
    }
    if(head->next == NULL)
        return head;
    // linked list consists of at least 2 elements
    struct Node* A = head;
    struct Node* B = A->next;
    while(true){
        A->next = A->prev;
        A->prev = B;
        if(B ==NULL){
            head = A;
            return head;
        }
        A = B;
        B = B->next;
    }
}


struct Node* reverse_Doubly_LL_2(struct Node* head){
    if(head == NULL){
        printf("The Doubly Linked List is empty\n");
        return head;
    }
    if(head->next == NULL)
        return head;
    // linked list consists of at least 2 elements
    struct Node* temp = head;
    while(true){
        struct Node* temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;
        if(temp->prev == NULL){
            head = temp;
            return head;
        }
        temp = temp->prev;
    }
}

void display_Circular_Doubly_LL(struct Node* head){
    struct Node* temp = head;
    do{
        printf("%d, ", temp->data);
        temp = temp->next;
    }while(temp != head);
}




int main()
{
    struct Node* head = NULL;
    head = insert_In_Doubly_LinkedList(head, 10, 0);
    head = insert_In_Doubly_LinkedList(head, 20, 1);
    head = insert_In_Doubly_LinkedList(head, 15, 2);
    head = insert_In_Doubly_LinkedList(head, 2, 1);
    display_Doubly_LL(head);
    //head = delete_In_Doubly_LL(head, 5);
    head = reverse_Doubly_LL_2(head);
    display_Doubly_LL(head);
    head = reverse_Doubly_LL_2(head);
    display_Doubly_LL(head);
    return 0;
}
