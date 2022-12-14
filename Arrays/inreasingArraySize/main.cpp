#include <iostream>

using namespace std;

int main()
{
    int *p = new int[5];  // p is a pointer var in stack. the address returned by new int[] is assigned to p. the memory for 5 int is allocated from heap
    p[0] = 2; p[1] = 4; p[2] = 6; p[3] = 8; p[4] = 12;
    // if we want to increase the memory size allocated from heap we do the following.
    // step1:

    int *q = new int[10];
    // step 2:
    for(int i = 0; i <5; i++){
        q[i] = p[i];
    }
    delete []p;
    p = q;
    q = NULL;
    p[8] = 36;
    for(int i = 0; i <10; i++){
        printf("%d, ", p[i]);}
    return 0;
}
