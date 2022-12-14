#include <stdio.h>
#include <stdlib.h>

// below function computes number of different shapes of unlebeled binary trees which are created using N nodes.
// Ex: if N = 2 => we can create only 2 differently shaped binary trees. if n = 3; there are 5 binary trees that are differently shaped.
int numOfBT(int num_of_nodes){
    int x = 2*num_of_nodes;
    int multiplication_1 = 1;
    int multiplication_2 = 1;
    for(int i = 0; i<num_of_nodes; i++){
        multiplication_1 = multiplication_1 * x;
        x--;
    }
    for(int i = 0; i<num_of_nodes; i++){
        multiplication_2 = multiplication_2*x;
        x--;
    }
    int answer = multiplication_1 / multiplication_2 / (num_of_nodes+1);
    return answer;
}

int factorial(int n){
    int result = 1;
    while(n!=0){
        result *= n;
        n--;
    }
}

// below function computes number of lebeled binary trees which are created using N nodes.
// Ex: if N = 2 => we can create 2 differently shaped binary trees with each shape 2 another binary tree with different value. So overall 4.
int numOfBTpermut(int num_of_nodes){
    int x = 2*num_of_nodes;
    int multiplication_1 = 1;
    int multiplication_2 = 1;
    for(int i = 0; i<num_of_nodes; i++){
        multiplication_1 = multiplication_1 * x;
        x--;
    }
    for(int i = 0; i<num_of_nodes; i++){
        multiplication_2 = multiplication_2*x;
        x--;
    }
    int answerForDiffShapes = multiplication_1 / multiplication_2 / (num_of_nodes+1);
    int answer = answerForDiffShapes * factorial(num_of_nodes);
    return answer;
}



int main()
{

    int n = 5;
    printf("Number of binary trees for numOfNodes = %d is %d", n, numOfBTpermut(n));
    return 0;
}
