#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    int* arrayForStack;
    int size;
    int top;  // top is the index of the top ELement Of Stack. Initially stack will be empty so no array is created.
};



/* below functions are for Stack objects that are declared in main memory.
And memory for Stack structure(object) is allocated from stack section of memory not from heap. However, memory for the arrayForStack member of Stack structure(object)
is allocated from heap.
*/


// prototypes of functions
void create_Stack(struct Stack* stk);
bool is_Stack_Empty(struct Stack stk);  // T = O(1)
bool is_Stack_Full(struct Stack stk);   // T = O(1)
void push(struct Stack* stk, int num);    // T = O(1)
void display(struct Stack stk);   // T = O(n)
void pop(struct Stack* stk);   // T = O(1)
int pop2(struct Stack* stk);    // T = O(1)
int get_Top_In_Stack(struct Stack stk);   // T = O(1)
int get_Nth_ele(struct Stack stk, int position);  // T = O(1)
void delete_K_elements(struct Stack* stk, int k); // T = O(n)


void create_Stack(struct Stack* stk){
    printf("Enter the size of an array for stack: ");
    scanf("%d", &stk->size);
    stk->top = -1;
    stk->arrayForStack = (int*)malloc(sizeof(int) * stk->size);
}


bool is_Stack_Empty(struct Stack stk){
    if(stk.top == -1){
        return true;
    }
    return false;
}

bool is_Stack_Full(struct Stack stk){
    if(stk.top == stk.size-1)
        return true;
    return false;
}

void push(struct Stack* stk, int num){
    if(stk->top == stk->size-1){
        printf("Stack overflow.\n");
    }
    else{
        stk->top++;
        stk->arrayForStack[stk->top] = num;
    }
    return;
}

void display(struct Stack stk){
    if(stk.top == -1){
        printf("The stack is empty\n");
        return;
    }
    printf("Elements of stack: ");
    while(stk.top != -1){
        printf("%d, ", stk.arrayForStack[stk.top]);
        stk.top--;
    }
    printf("\n");
    return;
}


void pop(struct Stack* stk){
    if(stk->top == -1){
        printf("The stack is empty. There is no element to pop, to delete from stack\n");
        return;
    }
    stk->top--;
}

int pop2(struct Stack* stk){
    int poppedEle = -1;
    if(stk->top == -1){
        printf("Stack underflow\n");
    }
    else{
        poppedEle = stk->arrayForStack[stk->top];
        stk->top--;
    }
    return poppedEle;
}


// this returns the value of the top most element of the stack without deleting that element from the stack.
int get_Top_In_Stack(struct Stack stk){
    if(stk.top == -1){
        printf("The stack is empty\n");
        return -1;
    }
    return stk.arrayForStack[stk.top];
}

// this function deletes elements from top to bottom until it reacheas nth element from stack and it returns nth element.
// suppose 7 is top element here 7, 5, 6, 1 .if n == 1 returns 7, n == 3 delete 7, 5 and return 6.
int get_Nth_Ele_From_Top(struct Stack* stk, int position){
    if(stk->top == -1){
        printf("The stack is empty\n");
        return -1;
    }
    if(position > stk->top+1 || position<1){
        printf("Give position higher than 0 and less than %d\n", stk->top+2);
        return -1;
    }
    for(int i = 0; i<position-1; i++){
        pop(stk);
    }
    return stk->arrayForStack[stk->top];
}


// this returns n th element from top without deleting any elements
int get_Nth_ele(struct Stack stk, int position){
    int x = -1;
    if(position < 1 || position > stk.top+1){
        printf("Give between 1 and %d as argument\n", stk.top+1);
    }
    else{
        x = stk.arrayForStack[stk.top - position+1];
    }
    return x;
}

void delete_K_elements(struct Stack* stk, int k){
    if(stk->top == -1){
        printf("The stack is empty\n");
        return;
    }
    if(k > stk->top+1){
        printf("There are not %d elements is Stack, there are %d elements, so give %d as argument\n", k, stk->top+1, stk->top+1);
        return;
    }
    for(int i = 0; i<k; i++)
        pop(stk);
}






int main()
{
    struct Stack stk1;
    create_Stack(&stk1);
   // display(stk1);
    int i;
    for(i = 1; i<21 && !is_Stack_Full(stk1); i++){
        push(&stk1, i);
        //display(stk1);
         //printf("Top element in stack is %d\n", get_Top_In_Stack(stk1));
    }
    display(stk1);


    printf("%d", get_Nth_ele(stk1, 20));
    display(stk1);




    return 0;
}
