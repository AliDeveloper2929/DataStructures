#include <iostream>

using namespace std;

int main()
{
    // 3 methods of creating 2D array
    // method 1. in this method all elements are in stack.
    int A[3][4] ={{1, 2, 3, 4}, {4, 5, 6, 7}, {5, 8, 10, 65}};  // overall 3*4 =12 elements.
    A[0][2] = 5;     // 3 is changed to 5;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            printf("%d ", A[i][j]);

        }
        printf("\n");
    }


    // method 2.
    // we first declare an array of 3 pointers in stack
   /* int* A[3]; // here 3 int pointer are in stack.
    A[0] = new int[4]; // memory for 4 int is allocated from heap. and its address is assigned to A[0] which is in stack
    A[1] = new int[4];
    A[2] = new int[4];
    A[0][2] = 15;


    // method 3. in this method there will be only one pointer variable in stack and all other things will be in heap.
    (int*)* A;  // declaration of double pointer. int* is pointer in heap.  p is a pointer to (int*)
    A = new int*[3];  // we are allocating mem from heap for 3 (int*) => pointer to int.
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];
*/
    return 0;
}
