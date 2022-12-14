#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    int size;
    int top;
    char* A;
};

int precedenceOfOperator(char oper);
char* convert_Infix_To_Postfix(char* exp);
char* convert_Infix_To_Postfix_2(char* exp);
bool isEmpty(struct Stack stk);
void push(struct Stack* stk, char character);
char pop(struct Stack* stk);
void pop2(struct Stack* stk);
void display(struct Stack stk);
char top(struct Stack stk);
bool isOperand(char c);



void push(struct Stack* stk, char character){
    if(stk->top == stk->size-1){
        printf("Stack overFlow\n");
    }
    else{
        stk->top++;
        stk->A[stk->top] = character;
    }
}

char pop(struct Stack* stk){
    char character = ' ';
    if(stk->top == stk->size-1){
        printf("stack underflow\n");
    }
    else{
        character = stk->A[stk->top];
        stk->top--;
    }
    return character;
}

void pop2(struct Stack* stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return;
    }
    if(stk->top == stk->size-1){
        printf("stack underflow\n");
    }
    else{
        stk->top--;
    }
}

char top(struct Stack stk){
    if(stk.top == -1){
        printf("Stack underflow\n");
        return ' ';
    }
    return stk.A[stk.top];
}

bool isEmpty(struct Stack stk){
    if(stk.top == -1)
        return true;
    else
        return false;
}

void display(struct Stack stk){
    if(stk.top == -1){
        printf("There is no element\n");
    }
    else{
        printf("The elements are: ");
        while(stk.top != -1){
            printf("%c, ", stk.A[stk.top]);
            stk.top--;
        }
        printf("\n");
    }
}


int precedenceOfOperator(char oper){
    if( (oper >= 'a' && oper <= 'z') || (oper >= 'A' && oper <= 'Z') ){
        return 3;
    }
    if(oper == '+' || oper == '-')
        return 1;
    if(oper == '*' || oper == '/')
        return 2;
}


// this is for those which parantheses are given or right to left operators are given
char* convert_Infix_To_Postfix(char* exp){
    int length = 0;
    for(int i = 0; exp[i] != '\0'; i++){
        length++;
    }

    struct Stack stk;
    stk.size = length+1;
    stk.top = -1;
    stk.A = (char*)malloc(sizeof(char) * stk.size);

    char* postfix = (char*)malloc((length+1) * sizeof(char));
    int j = 0; // index for postfix
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == ' ')
            continue;
        if(isEmpty(stk) || precedenceOfOperator(exp[i]) > precedenceOfOperator(top(stk)) ){
            push(&stk, exp[i]);
        }
        else{
            while( !isEmpty(stk) && precedenceOfOperator(exp[i]) <= precedenceOfOperator(top(stk)) )
                postfix[j++] = pop(&stk);
            push(&stk, exp[i]);
        }
    }
    while( !isEmpty(stk) )
        postfix[j++] = pop(&stk);
    postfix[j] = '\0';
    return postfix;
}


bool isOperand(char c){
    if( (c >= 'A' && c<='Z') || (c >= 'a' && c <= 'z') )
        return true;
    else
        return false;
}

char* convert_Infix_To_Postfix_2(char* exp){
    int length = 0;
    for(int i = 0; exp[i] != '\0'; i++)
        length++;

    struct Stack stk;
    stk.size = length+1;
    stk.top = -1;
    stk.A = (char*)malloc(stk.size * sizeof(char));

    char* postfix = (char*)malloc( (length+1) * sizeof(char) );
    int j = 0; // index for postfix

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == ' ')
            continue;
        if(isOperand(exp[i]))
            postfix[j++] = exp[i];
        else if( isEmpty(stk) || precedenceOfOperator(exp[i]) > precedenceOfOperator(top(stk)) )
            push(&stk, exp[i]);
        else{
            while( !isEmpty(stk) && precedenceOfOperator(exp[i]) <= precedenceOfOperator(top(stk)) ){
                postfix[j++] = pop(&stk);
            }
            push(&stk, exp[i]);
        }
    }
    while( !isEmpty(stk) )
        postfix[j++] = pop(&stk);
    postfix[j] = '\0';
    return postfix;
}





int main()
{
    char* A = "A+B*(C+D)/F+D*E";

    char* B = convert_Infix_To_Postfix_2(A);
    char* C = convert_Infix_To_Postfix(A);
    printf("%s\n", B);
    printf("%s", C);
    return 0;
}
