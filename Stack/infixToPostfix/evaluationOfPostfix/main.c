#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct Stack {
    int size;
    int top;
    int* arrayForStack;
};


// prototypes of functions

bool is_Stack_Empty(struct Stack stk);  // T = O(1)
bool is_Stack_Full(struct Stack stk);   // T = O(1)
void push(struct Stack* stk, int num);    // T = O(1)
void display(struct Stack stk);   // T = O(n)
void pop(struct Stack* stk);   // T = O(1)
int pop2(struct Stack* stk);    // T = O(1)
int get_Top_In_Stack(struct Stack stk);   // T = O(1)




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


int get_Top_In_Stack(struct Stack stk){
    if(stk.top == -1){
        printf("The stack is empty\n");
        return -1;
    }
    return stk.arrayForStack[stk.top];
}

bool isOperand(char op){
    if( op >= '0' && op <= '9' )
        return true;
    else
        return false;
}


// this is for such postfix that operators should be '+', '-', '/', '*' and operands should be only digits. Ex: '5', '7' but not '12' '102'.
int eval_Of_Postfix(char* exp){
    int length = 0;
    for(int i =0; exp[i] != '\0'; i++){
        length++;
    }

    struct Stack stk;
    stk.top = -1;
    stk.size = length+1;
    stk.arrayForStack = (int*)malloc( (length+1)*sizeof(int) );

    int result, op1, op2;
    for(int i = 0; exp[i] != '\0'; i++){
        if( isOperand(exp[i]) )
            push(&stk, exp[i]-'0' );
        else{
            op2 = pop2(&stk);
            op1 = pop2(&stk);
            switch(exp[i]){
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '^':
                    result = op1 * op1;
                    while(op2-- != 2)
                        result = result*op1;
                    break;
            }
            push(&stk, result);
        }
    }
    return pop2(&stk);
}



int main()
{
    char* postFix = "823^/23*+";
    printf("result is %d", eval_Of_Postfix(postFix));


    return 0;
}
