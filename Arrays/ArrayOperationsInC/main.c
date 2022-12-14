#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Array{
    int A[100];
    int size;
    int length;
};

// following are prototypes of functions:
void display(struct Array arr); // time complexity => T = O(n). This prints all the elements of an array
void append(struct Array* ptr, int num); // T = O(1) if enough space. Space complexity => S = O(1). this is adds num at the end of the array
void insertElement(struct Array* ptr, int index, int num); // T = O(n),  S = O(1).
void delElement(struct Array* ptr, int index); // T = O(n), S = O(1).
int delElement1(struct Array* ptr, int index); // T = O(n). S = O(1)
int linearSearch(struct Array arr, int key); // time complexity: O(n)
int binarySearch(struct Array arr, int key); // time complexity: ceil of O(log n) base 2:
int recursiveBinSearch(struct Array arr, int key, int low, int high); // space and time complexity is ceil of O(log n) base 2. iterative method is better than this
int getElement(struct Array arr, int index);
void setElement(struct Array* ptr, int element, int index); // T = O(1), S = O(1). it replaces a new element with the old one
int getMax(struct Array arr);  // T = O(n)
int getMin(struct Array arr); //  T = O(n)
void reverseArray(struct Array* ptr);
void insertInSortedArr3(struct Array* ptr, int element);  // this is the best of all three insertInSortedArr functions.
void insertInSortedArr2(struct Array* ptr, int element);  // this one is better than the 1st one.in terms of time complexity
void insertInSortedArr1(struct Array* ptr, int element);
bool isSorted(struct Array arr);
void shiftNegativesToLeft(struct Array* ptr);
void mergeSortedArrays_1(int arr1[], int len_arr1, int arr2[], int len_arr2, int outputArr[]);
struct Array* mergeSortedArrays_3(struct Array* arr1, struct Array* arr2);
int* mergeSortedArrays_2(int arr1[], int len1, int arr2[], int len2);
struct Array* unionOfSets_1(struct Array arr1, struct Array arr2); // for any set arr1 and arr2. T = O(n^2);
struct Array* unionOfSets_2(struct Array arr1, struct Array arr2); // for only sorted arr1 and arr2. Because this uses merge algorithm. T = O(len1 + len2) = O(n)
struct Array* subtractionOfSets_1(struct Array* arr1, struct Array* arr2); // for any set arr1 and arr2. T = O(n^2);
struct Array* subtractionOfSets_2(struct Array* arr1, struct Array* arr2); // for only sorted arr1 and arr2. Because this uses merge algorithm. T = O(len1 + len2) = O(n)
struct Array* intersectionOfSets_1(struct Array* arr1, struct Array* arr2);//int A[] = {1, 3, 5, 6, 8}; int B[] = {2, 3, 8, 12, 16, 18};        // for any sets
struct Array* intersectionOfSets_2(struct Array* arr1, struct Array* arr2);//intersection(A, B) => elements which exist in both sets = {3, 8};  // for only sorted sets. this uses merge algorithm


void display(struct Array arr){
    printf("Array elements are: ");
    for(int i=0; i<arr.length; i++){
        printf("%d, ", arr.A[i]);
    }
    printf("\n");
}

void append(struct Array* ptr, int num){
    if(ptr->length < ptr->size) {
        ptr->A[ptr->length] = num;
        ptr->length ++;
    }
    else{
        printf("There is no space in Array.\n");
    }
    return;
}

void insertElement(struct Array* ptr, int index, int num){
    if(ptr->length >= ptr->size){
        printf("There is no space to insert an element.\n");
        return;
    }
    if(index > ptr->length){
        printf("You gave higher index, give less than or equal to %d\n", ptr->length);
        return;
    }
    for(int i = ptr->length; i>index; i--){
        ptr->A[i] = ptr->A[i-1];
    }
    ptr->A[index] = num;
    ptr->length++;
    return;
}

// below function deletes an element from an array at index 'index':
void delElement(struct Array* ptr, int index){
    if(index<ptr->length && index>=0){
        for(int i = index; i<ptr->length-1; i++){
            ptr->A[i] = ptr->A[i+1];
        }
        ptr->length--;
    }
    else printf("Give index between %d and %d to delete.\n", 0,  ptr->length);
    return;
}

// below function deletes an element from an array at index 'index': and returns the deleted element.
int delElement1(struct Array* ptr, int index){
    int deletedEle = ptr->A[index];
    if(index<ptr->length && index>=0){
        for(int i = index; i<ptr->length-1; i++){
            ptr->A[i] = ptr->A[i+1];
        }
        ptr->length--;
        return deletedEle;
    }
    else{
        printf("Give index between %d and %d to delete.\n", 0,  ptr->length);
        return -1;
    }
}

/* below function performs linear search. it returns the index of key element.
Time complexity: best case when key element is at index 0: O(1);
                 worst case when key element is at last index or not found: O(n) n=>number of elements.
*/
int linearSearch(struct Array arr, int key){
    for(int i=0; i<arr.length; i++)
        if(arr.A[i] == key) return i;
    return -1;  // if not found
}

/* below is binary search function. array must be sorted. O(log n) base 2*/
int binarySearch(struct Array arr, int key){
    int low = 0; int high = arr.length-1; int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(arr.A[mid] == key) return mid;
        else if(arr.A[mid] < key) low = mid+1;
        else high = mid -1;
    }
    printf("%d is not found from array\n", key);
    return -1;
}

// binary search using tail recursion, instead of tail recursion we should use
//iterative loop method. because space complexity is high in this recursion
int recursiveBinSearch(struct Array arr, int key, int low, int high){
    if(low<=high){
        int mid = (low+high) / 2;
        if(arr.A[mid] == key) return mid;
        else if(arr.A[mid] < key) return recursiveBinSearch(arr, key, mid+1, high);
        else return recursiveBinSearch(arr, key, low, mid-1);
    }
    else {
        printf("%d not found\n", key);
        return -1;
    }
}

// below function returns element at index n;
int getElement(struct Array arr, int index){
    if(index < arr.length && index >=0) return arr.A[index];
    printf("Out of index error\n");
    return -1;
}

// below function sets given element at given index. it replaces a new element with the old one
void setElement(struct Array* ptr, int element, int index){
    if(index >=0 && index < ptr->length){
        ptr->A[index] = element;
        return;
    }
    printf("Give less index, out of index error\n");
    return;
}

//  below function returns the max number in array.
int getMax(struct Array arr){
    if(arr.length == 0) {
        printf("there is no element in an array\n");
        return 0;
    }
    int max = arr.A[0];
    for(int i = 1; i<arr.length; i++){
        if(arr.A[i] > max) max = arr.A[i];
    }
    return max;
}

//  below function returns the min number in array.
int getMin(struct Array arr){
    if(arr.length == 0) {
        printf("there is no element in an array\n");
        return 0;
    }
    int min = arr.A[0];
    for(int i = 1; i<arr.length; i++){
        if(arr.A[i] < min) min = arr.A[i];
    }
    return min;
}

// below function reverses given array.
void reverseArray(struct Array* ptr){
    int i, j;
    for(i = 0, j = ptr->length-1; i<j; i++, j--){
        // swap(ptr->A[i], ptr->A[j]);
        int temp = ptr->A[i];
        ptr->A[i] = ptr->A[j];
        ptr->A[j] = temp;
    }
}


// below function adds inserts nums to a sorted array at a appropriate index
void insertInSortedArr1(struct Array* ptr, int element){
    // first: we check if there is space for a new element
    if(ptr->length >= ptr->size){
        printf("There is no space in an array\n");
        return;
    }
    for(int i =0; i<ptr->length; i++){
        if(ptr->A[i] > element){
            // insert element at index i:
            for(int j=ptr->length; j>i; j--){
                ptr->A[j] = ptr->A[j-1];
            }
            ptr->A[i] = element;
            ptr->length++;
            return;
        }
    }
    // if all nums in array is less than element, we insert element at length index.
    ptr->A[ptr->length] = element;
    ptr->length++;
    return;
}
// this is a better version tha the first one.
void insertInSortedArr2(struct Array* ptr, int element){
    // check if there is free space for a new element
    if(ptr->length >= ptr->size){
        printf("There is no free space for an array\n");
        return;
    }
    for(int i=ptr->length-1; i>=0; i--){
        if(ptr->A[i] > element){
            ptr->A[i+1] = ptr->A[i];
        }
        else{
            ptr->A[i+1] = element;
            ptr->length++;
            return;
        }
    }
    // below statements are executed when all the numbers in array are less than an element.
    ptr->A[0] = element;
    ptr->length++;
    return;
}

// this is even better than the second one
void insertInSortedArr3(struct Array* ptr, int element){
    if(ptr->length == ptr->size){
        printf("There is no space in an array for a new element\n");
        return;
    }
    int i = ptr->length-1;
    while(i>=0 && element < ptr->A[i]){
        ptr->A[i+1] = ptr->A[i];
        i--;
    }
    ptr->A[i+1] = element;
    ptr->length++;
    return;
}

// this function checks if the array is sorted or not. Ex:  2, 4, 6, 7 sorted.
bool isSorted(struct Array arr){
    for(int i = 0; i<arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]) return false;
    }
    return true;
}

// shifting negative nums to left and positives to the right side
void shiftNegativesToLeft(struct Array* ptr){
    int i = 0; int j = ptr->length-1; // i index points to positive nums, j index point to negative nums.
    while(i < j){
        while(ptr->A[i] < 0){i++;}  // after this i points to the positive number from beginning
        while(ptr->A[j] >= 0){j--;}  // after this j points to the negative number from the end
        if(i < j){
            // swap(ptr->A[i], ptr->A[j]);
            int temp = ptr->A[i];
            ptr->A[i] = ptr->A[j];
            ptr->A[j] = temp;
        }
    }
    return;
}

// below function merges two sorted arrays int a new array.
// Ex: int A1[] = {7, 9, 15, 18, 22}; int A2[] = {1, 3, 8, 12, 20}; int outputArr[] = {1, 3, 7, 8, 9, 12, 15, 18, 20, 22};
void mergeSortedArrays_1(int arr1[], int len_arr1, int arr2[], int len_arr2, int outputArr[]){ // we assume outputArr has enough space for elements of arr1 and arr2:
    int i = 0; int j = 0; int k = 0; // i for index of arr1, j for index of arr2, k for index of outputArr
    while(i < len_arr1 && j < len_arr2){
        if(arr1[i] <= arr2[j])
            outputArr[k++] = arr1[i++];
        else if(arr2[j] < arr1[i])
            outputArr[k++] = arr2[j++];
    }
    while(i < len_arr1) outputArr[k++] = arr1[i++];
    while(j < len_arr2) outputArr[k++] = arr2[j++];
}

// this function allocates memory from heap for output array and returns its address
int* mergeSortedArrays_2(int arr1[], int len1, int arr2[], int len2){
    int len3 = len1 + len2;
    int* outputArr = (int*)malloc(len3 * sizeof(int));
    int i =0, j=0, k=0;
    while( i < len1 && j < len2){
        if(arr1[i] <= arr2[j])
            outputArr[k++] = arr1[i++];
        else if(arr2[j] < arr1[i])
            outputArr[k++] = arr2[j++];
    }
    while(i < len1) outputArr[k++] = arr1[i++];
    while(j < len2) outputArr[k++] = arr2[j++];
    return outputArr;
}

struct Array* mergeSortedArrays_3(struct Array* arr1, struct Array* arr2){
    int len3 = arr1->length + arr2->length;
    struct Array* outputArr = (struct Array*)malloc(sizeof(struct Array));
    outputArr->length = len3;
    outputArr->size = len3+1;
    int i=0, j=0, k=0;
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] <= arr2->A[j]){
            outputArr->A[k++] = arr1->A[i++];
        }
        else
            outputArr->A[k++] = arr2->A[j++];
    }
    while(i < arr1->length){
        outputArr->A[k++] = arr1->A[i++];
    }
    while(j < arr2->length){
        outputArr->A[k++] = arr2->A[j++];
    }
    return outputArr;
}


// set operations: union, intersection, difference
// union(int a[], int b[], int c[]) => union of two a and b sets into the c set. union of 2 sets means in set c all elements of both sets must appear only once.
struct Array* unionOfSets_1(struct Array arr1, struct Array arr2){ // this function's parameter is call by value which means space complexity is O(len1 + len2)
    struct Array* newSet = (struct Array*)malloc(sizeof(struct Array));  // T = O(n^2);
    newSet->length = 0;
    for(int i = 0; i<arr1.length; i++){
        newSet->A[i] = arr1.A[i];
        newSet->length++;
    }
    int k = newSet->length;
    for(int j = 0; j<arr2.length; j++){  // j is for index of set b
        int status = 0; // if
        for(int i = 0; i<arr1.length; i++){ // i is for index of set a
            if(arr2.A[j] == arr1.A[i]){
                status = 1;
                break;
            }
        }
        if(status == 0){
            newSet->A[k++] = arr2.A[j];
            newSet->length++;
        }
    }
    newSet->size = newSet->length+1;
    return newSet;
}

// union of two a and b sets, when both are sorted it is better to use merge algorithm
struct Array* unionOfSets_2(struct Array arr1, struct Array arr2){ // this function's parameter is call by value which means space complexity is O(len1 + len2)
    struct Array* newSet = (struct Array*)malloc(sizeof(struct Array));  // T = O(n)
    //newSet->length = 0;
    int i = 0, j = 0, k =0; // i for index of arr1, j for index of arr2, k for index of newSet
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            newSet->A[k++] = arr1.A[i++];
            //newSet->length++;
        }
        else if(arr2.A[j] < arr1.A[i]){
            newSet->A[k++] = arr2.A[j++];
            //newSet->length++;
        }
        else{
            newSet->A[k++] = arr1.A[i];
            i++; j++;
            //newSet->length++;
        }
    }
    while(i < arr1.length){
        newSet->A[k++] = arr1.A[i++];
        //newSet->length++;
    }
    while(j < arr2.length){
        newSet->A[k++] = arr2.A[j++];
        //newSet->length++;
    }
    newSet->length = k;
    newSet->size = k+1;
    return newSet;
}


// intersection of 2 a and b sets. int A[] = {1, 3, 5, 6, 8}; int B[] = {2, 3, 8, 12, 16, 18}; intersection(A, B) => elements which exist in both sets = {3, 8};
// below function is for any sets. T = O(n ^ 2); Space = O(1);
struct Array* intersectionOfSets_1(struct Array* arr1, struct Array* arr2){
    struct Array* newSet = (struct Array*)malloc(sizeof(struct Array));
    newSet->length = 0;
    int k = 0; // for index of newSet
    for(int i = 0; i<arr1->length; i++){
        for(int j = 0; j<arr2->length; j++){
            if(arr1->A[i] == arr2->A[j]){
                newSet->A[k++] = arr1->A[i];
            }
        }
    }
    if(k == 0){
        printf("There is no equal elements, no intersection\n");
        //free(newSet);
    }
    else newSet->length = k;
    newSet->size = k+1;
    return newSet;
}

// below function is only for sorted sets of A and B
struct Array* intersectionOfSets_2(struct Array* arr1, struct Array* arr2){
    struct Array* newSet = (struct Array*)malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0; // i for index of arr1, j for index of arr2, k for index of newSet
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else {
            newSet->A[k++] = arr1->A[i];
            i++; j++;
        }
    }
    if(k == 0) printf("There is no intersection\n");
    newSet->length = k;
    newSet->size = k+1;
    return newSet;
}

// difference of set A and set B: A={1,2,3} and B={3,5}, then A−B={1,2} -> this is a set which  only exist in A not in B.
struct Array* subtractionOfSets_1(struct Array* arr1, struct Array* arr2){
    struct Array* newSet = (struct Array*)malloc(sizeof(struct Array));
    int k = 0; // for index of newSet
    for(int i = 0; i<arr1->length; i++){
        int status = 0;
        for(int j = 0; j<arr2->length; j++){
            if(arr1->A[i] == arr2->A[j]){
                status = 1;
                break;
            }
        }
        if(status == 0){
            newSet->A[k++] = arr1->A[i];
        }
    }
    newSet->length = k;
    if(newSet->length == 0){
        printf("Subtraction is 0.\n");
    }
    newSet->size = k+1;
    return newSet;
}

// this is for only sorted arrays
struct Array* subtractionOfSets_2(struct Array* arr1, struct Array* arr2){
    struct Array* newSet = (struct Array*)malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0; // i for arr1, j for arr2, k for newSet
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            newSet->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i]) j++;
        else {
            i++; j++;
        }
    }
    while(i < arr1->length)
        newSet->A[k++] = arr1->A[i++];
    newSet->length = k;
    if(newSet->length == 0) printf("There is no difference\n");
    newSet->size = k+1;
    return newSet;
}





int main()
{
    struct Array arr = {{0, -8, 4, -9, 5, -1, 25, -82, 3, -78}, 10, 10};
   /* for(int i=0; i<8; i++){
        insert(&arr, i, i+1);
        display(arr);
    }
    //reverseArray(&arr);
    insertInSortedArr2(&arr, -5);
    //insertInSortedArr3(&arr, 5);
    insert(&arr, 5, 81);
    if(isSorted(arr)) printf("array is sorted\n");
    else printf("array is not sorted\n");
    */
   /* int a1[] = {2, 5, 9, 15, 26};
    int a2[] = {1, 4, 8 ,18, 30, 36};
    int* a3;
    a3 = mergeSortedArrays_2(a1, 5, a2, 6);
    for(int i=0; i<11; i++) printf("%d, ", a3[i]);
    */

    struct Array arr1 = {{-16, 5, 15, 17, 24, 29, 325}, 10, 7};
    struct Array arr4 = {{-16, 5, 15, 17, 28, 29, 325}, 10, 7};
    struct Array arr2 = {{-8, 0, 2, 16, 18, 24, 27, 31, 32, 39, 45, 92, 95, 326}, 50, 14};
    struct Array* arr3;
    arr3 = subtractionOfSets_2(&arr1, &arr2);
   // for(int i = 0; i<arr3->length; i++) printf("%d, ", arr3->A[i]);
    printf("\n");
   // display(*arr3);
    display(arr);
    return 0;
}
