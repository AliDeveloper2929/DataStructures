#include <stdio.h>
#include <stdlib.h>


// below is linear search function:
int linearSearch(int Array[], int key, int arrayLen){
    for(int i=0; i<arrayLen; i++){
        if(Array[i]==key)return i;
    }
    printf("Key is not found\n");
    return -1;
}

// below is binary search using iterative method: prerequisite for binary search is array must be sorted
int binarySearch(int Array[], int key, int arrayLen){  // time complexity is: O(log n) base 2.
    int low = 0; int high = arrayLen-1; int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(Array[mid] == key) return mid;
        else if(Array[mid] < key){
            low = mid+1;
        }
        else high = mid-1;
    }
    // when nothing returned.
    printf("%d is not found\n", key);
    return -1;
}

int main()
{
    int A[] = {1, 2, 3, 4, 50};
    printf("%d", linearSearch(A, -8, 5));
    printf("\n");
    printf("%d", binarySearch(A, 50, 5));
    return 0;
}
