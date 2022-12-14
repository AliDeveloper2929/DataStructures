#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    int size;
    int top;
    char* A;
};

bool isEmpty(struct Stack stk);
bool isParanthesesMatching_1(char* expression);
void push(struct Stack* stk, char character);
char pop(struct Stack* stk);
void pop2(struct Stack* stk);
void display(struct Stack stk);
char top(struct Stack stk);

bool isParanthesesMatching_1(char* expression){
    int i = 0;
    int length = 0;
    while(expression[i] != '\0'){
        i++;
        length++;
    }

    struct Stack stk;
    stk.size = length;
    stk.top = -1;
    stk.A = (char*)malloc(stk.size * sizeof(char));

    for(int i = 0; i<length; i++){
        if(expression[i] == '(' || expression[i] == ')'){
            push(&stk, expression[i]);
            if(stk.top == 0 && expression[i] == ')')
                return false;
            else if(expression[i] == ')'){
                pop2(&stk);
                pop2(&stk);
            }
        }
    }
    if(stk.A[stk.top] == '(')
        return false;
    return true;
}

bool isParanthesesMatching_2(char* exp){

    struct Stack stk;
    stk.size = 500;
    stk.top = -1;
    stk.A = (char*)malloc(stk.size * sizeof(char));


    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(')
            push(&stk, exp[i]);
        else if(exp[i] == ')'){
            if(isEmpty(stk))
                return false;
            else
                pop2(&stk);
        }
    }
    return isEmpty(stk) ? true : false;
}


bool isParanthesesMatching_3(char* exp){
    int i = 0;
    int length = 0;
    while(exp[i] != '\0'){
        i++;
        length++;
    }

    struct Stack stk;
    stk.size = length;
    stk.top = -1;
    stk.A = (char*)malloc(stk.size * sizeof(char));

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(' || exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
                push(&stk, exp[i]);
            }
            else{
                if(isEmpty(stk))
                    return false;
                else{
                    char closingChar;
                    char openingChar = top(stk);
                    switch (openingChar){
                    case '(':
                        closingChar = ')';
                        break;

                    case '[':
                        closingChar = ']';
                        break;
                    case '{':
                        closingChar = '}';
                        break;
                    }
                    if(closingChar == exp[i])
                        pop2(&stk);
                    else
                        return false;
                }
            }
        }
    }
    return isEmpty(stk) ? true:false;
}

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






int main()
{
   /* struct Stack stk;
    stk.size = 50;
    stk.top = -1;
    stk.A = (char*)malloc(stk.size * sizeof(char));
*/
    char A[] = "(){{(}}";
    if(isParanthesesMatching_3(A))
        printf("Match\n");
    else
        printf("Don't match\n");\

    return 0;
}
