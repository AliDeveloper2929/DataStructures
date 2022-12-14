#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

class Array{
private:
    int* A;
    int sizeOfArr;
    int length;

public:

Array(){
    sizeOfArr = 20;
    length = 0;
    A = new int[sizeOfArr];
}

Array(int sizeOfArray){
    sizeOfArr = sizeOfArray;
    length = 0;
    A = new int[sizeOfArr];
}

~Array(){
    delete []A;
}

// following are prototypes of functions:
void  display(); // time complexity => T = O(n). This prints all the elements of an array
void append(int num); // T = O(1) if enough space. Space complexity => S = O(1). this is adds num at the end of the array
void insertElement(int index, int num); // T = O(n),  S = O(1).
void delElement(int index); // T = O(n), S = O(1).
int delElement1(int index); // T = O(n). S = O(1)
int linearSearch(int key); // time complexity: O(n)
int binarySearch(int key); // time complexity: ceil of O(log n) base 2:
int recursiveBinSearch(int key, int low, int high); // space and time complexity is ceil of O(log n) base 2. iterative method is better than this
int getElement(int index);
void setElement(int element, int index); // T = O(1), S = O(1). it replaces a new element with the old one
int getMax();  // T = O(n)
int getMin(); //  T = O(n)
int sumOfElements();
void reverseArray();
void insertInSortedArr3(int element);  // this is the best of all three insertInSortedArr functions.
void insertInSortedArr2(int element);  // this one is better than the 1st one.in terms of time complexity
void insertInSortedArr1(int element);
bool isSorted();
void shiftNegativesToLeft();
void mergeSortedArrays_1(int arr2[], int len_arr2, int outputArr[]);
Array* mergeSortedArrays_3(Array arr2);
int* mergeSortedArrays_2(int arr2[], int len2);
Array* unionOfSets_1(Array arr2); // for any set arr1 and arr2. T = O(n^2);
Array* unionOfSets_2(Array arr2); // for only sorted arr1 and arr2. Because this uses merge algorithm. T = O(len1 + len2) = O(n)
Array* subtractionOfSets_1(Array arr2); // for any set arr1 and arr2. T = O(n^2);
Array* subtractionOfSets_2(Array arr2); // for only sorted arr1 and arr2. Because this uses merge algorithm. T = O(len1 + len2) = O(n)
Array* intersectionOfSets_1(Array arr2);//int A[] = {1, 3, 5, 6, 8}; int B[] = {2, 3, 8, 12, 16, 18};        // for any sets
Array* intersectionOfSets_2(Array arr2);//intersection(A, B) => elements which exist in both sets = {3, 8};  // for only sorted sets. this uses merge algorithm
};

// end of class

void Array:: display(){
    printf("Array elements are: ");
    for(int i=0; i<length; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
}

void Array:: append(int num){
    if(length < sizeOfArr) {
        A[length] = num;
        length ++;
    }
    else{
        printf("There is no space in Array.\n");
    }
    return;
}

void Array:: insertElement(int index, int num){
    if(length >= sizeOfArr){
        printf("There is no space to insert an element.\n");
        return;
    }
    if(index > length){
        printf("You gave higher index, give less than or equal to %d\n", length);
        return;
    }
    for(int i = length; i>index; i--){
        A[i] = A[i-1];
    }
    A[index] = num;
    length++;
    return;
}

// below function deletes an element from an array at index 'index':
void Array:: delElement(int index){
    if(index<length && index>=0){
        for(int i = index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
    }
    else printf("Give index between %d and %d to delete.\n", 0,  length);
    return;
}

// below function deletes an element from an array at index 'index': and returns the deleted element.
int Array:: delElement1(int index){
    int deletedEle = A[index];
    if(index<length && index>=0){
        for(int i = index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
        return deletedEle;
    }
    else{
        printf("Give index between %d and %d to delete.\n", 0,  length);
        return -1;
    }
}

/* below function performs linear search. it returns the index of key element.
Time complexity: best case when key element is at index 0: O(1);
                 worst case when key element is at last index or not found: O(n) n=>number of elements.
*/
int Array:: linearSearch(int key){
    for(int i=0; i<length; i++)
        if(A[i] == key) return i;
    printf("Search is unsuccessful\n");
    return -1;  // if not found
}

/* below is binary search function. array must be sorted. O(log n) base 2*/
int Array:: binarySearch(int key){
    int low = 0; int high = length-1; int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(A[mid] == key) return mid;
        else if(A[mid] < key) low = mid+1;
        else high = mid -1;
    }
    printf("%d is not found from array\n", key);
    return -1;
}

// binary search using tail recursion, instead of tail recursion we should use
//iterative loop method. because space complexity is high in this recursion
int Array:: recursiveBinSearch(int key, int low, int high){
    if(low<=high){
        int mid = (low+high) / 2;
        if(A[mid] == key) return mid;
        else if(A[mid] < key) return recursiveBinSearch(key, mid+1, high);
        else return recursiveBinSearch(key, low, mid-1);
    }
    else {
        printf("%d not found\n", key);
        return -1;
    }
}

// below function returns element at index n;
int Array:: getElement(int index){
    if(index < length && index >=0) return A[index];
    printf("Out of index error\n");
    return -1;
}

// below function sets given element at given index. it replaces a new element with the old one
void Array:: setElement(int element, int index){
    if(index >=0 && index < length){
        A[index] = element;
        return;
    }
    printf("Give less index, out of index error\n");
    return;
}

//  below function returns the max number in array.
int Array:: getMax(){
    if(length == 0) {
        printf("there is no element in an array\n");
        return 0;
    }
    int maxEle = A[0];
    for(int i = 1; i<length; i++){
        if(A[i] > maxEle) maxEle = A[i];
    }
    return maxEle;
}

//  below function returns the min number in array.
int Array:: getMin(){
    if(length == 0) {
        printf("there is no element in an array\n");
        return 0;
    }
    int minEle = A[0];
    for(int i = 1; i<length; i++){
        if(A[i] < minEle) minEle = A[i];
    }
    return minEle;
}


int Array:: sumOfElements(){
    int total = 0;
    for(int i = 0; i<length; i++){
        total+=A[i];
    }
    return total;
}


// below function reverses given array.
void Array:: reverseArray(){
    if(length == 0){
        printf("There is no element in an array\n");
        return;
    }
    int i, j;
    for(i = 0, j = length-1; i<j; i++, j--){
        // swap(A[i], A[j]);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("Array is reversed\n");
    return;
}


// below function adds inserts nums to a sorted array at a appropriate index
void Array:: insertInSortedArr1(int element){
    // first: we check if there is space for a new element
    if(length >= sizeOfArr){
        printf("There is no space in an array\n");
        return;
    }
    for(int i =0; i<length; i++){
        if(A[i] > element){
            // insert element at index i:
            for(int j=length; j>i; j--){
                A[j] = A[j-1];
            }
            A[i] = element;
            length++;
            return;
        }
    }
    // if all nums in array is less than element, we insert element at length index.
    A[length] = element;
    length++;
    return;
}
// this is a better version tha the first one.
void Array:: insertInSortedArr2(int element){
    // check if there is free space for a new element
    if(length >= sizeOfArr){
        printf("There is no free space for an array\n");
        return;
    }
    for(int i=length-1; i>=0; i--){
        if(A[i] > element){
            A[i+1] = A[i];
        }
        else{
            A[i+1] = element;
            length++;
            return;
        }
    }
    // below statements are executed when all the numbers in array are less than an element.
    A[0] = element;
    length++;
    return;
}

// this is even better than the second one
void Array:: insertInSortedArr3(int element){
    if(length == sizeOfArr){
        printf("There is no space in an array for a new element\n");
        return;
    }
    int i = length-1;
    while(i>=0 && element < A[i]){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = element;
    length++;
    return;
}

// this function checks if the array is sorted or not. Ex:  2, 4, 6, 7 sorted.
bool Array:: isSorted(){
    for(int i = 0; i<length-1; i++){
        if(A[i] > A[i+1]) return false;
    }
    return true;
}

// shifting negative nums to left and positives to the right side
void Array:: shiftNegativesToLeft(){
    int i = 0; int j = length-1; // i index points to positive nums, j index point to negative nums.
    while(i < j){
        while(A[i] < 0){i++;}  // after this i points to the positive number from beginning
        while(A[j] >= 0){j--;}  // after this j points to the negative number from the end
        if(i < j){
            // swap(ptr->A[i], ptr->A[j]);
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    return;
}

// below function merges two sorted arrays int a new array.
// Ex: int A1[] = {7, 9, 15, 18, 22}; int A2[] = {1, 3, 8, 12, 20}; int outputArr[] = {1, 3, 7, 8, 9, 12, 15, 18, 20, 22};
void Array:: mergeSortedArrays_1(int arr2[], int len_arr2, int outputArr[]){ // we assume outputArr has enough space for elements of arr1 and arr2:
    int i = 0; int j = 0; int k = 0; // i for index of arr1, j for index of arr2, k for index of outputArr
    while(i < length && j < len_arr2){
        if(A[i] <= arr2[j])
            outputArr[k++] = A[i++];
        else if(arr2[j] < A[i])
            outputArr[k++] = arr2[j++];
    }
    while(i < length) outputArr[k++] = A[i++];
    while(j < len_arr2) outputArr[k++] = arr2[j++];
}

// this function allocates memory from heap for output array and returns its address
int* Array:: mergeSortedArrays_2(int arr2[], int len2){
    int len3 = length + len2;
    int* outputArr = new int[len3];
    int i =0, j=0, k=0;
    while( i < length && j < len2){
        if(A[i] <= arr2[j])
            outputArr[k++] = A[i++];
        else if(arr2[j] < A[i])
            outputArr[k++] = arr2[j++];
    }
    while(i < length) outputArr[k++] = A[i++];
    while(j < len2) outputArr[k++] = arr2[j++];
    return outputArr;
}

Array* Array:: mergeSortedArrays_3(Array arr2){
    int len3 = length + arr2.length;
    Array* outputArr = new Array(len3); // this creates an outputArr variable which is pointer to the object of class Array. So object is in heap.
    outputArr->length = len3;
    int i=0, j=0, k=0;
    while(i < length && j < arr2.length){
        if(A[i] <= arr2.A[j]){
            outputArr->A[k++] = A[i++];
        }
        else
            outputArr->A[k++] = arr2.A[j++];
    }
    while(i < length){
        outputArr->A[k++] = A[i++];
    }
    while(j < arr2.length){
        outputArr->A[k++] = arr2.A[j++];
    }
    return outputArr;
}


// set operations: union, intersection, difference
// union(int a[], int b[], int c[]) => union of two a and b sets into the c set. union of 2 sets means in set c all elements of both sets must appear only once.
Array* Array:: unionOfSets_1(Array arr2){ // this function's parameter is call by value which means space complexity is O(len1 + len2)
    Array* newSet = new Array(length+arr2.length);  // T = O(n^2);
    newSet->length = 0;
    for(int i = 0; i<length; i++){
        newSet->A[i] = A[i];
        newSet->length++;
    }
    int k = newSet->length;
    for(int j = 0; j<arr2.length; j++){  // j is for index of set b
        int status = 0; // if
        for(int i = 0; i<length; i++){ // i is for index of set a
            if(arr2.A[j] == A[i]){
                status = 1;
                break;
            }
        }
        if(status == 0){
            newSet->A[k++] = arr2.A[j];
            newSet->length++;
        }
    }
    return newSet;
}

// union of two a and b sets, when both are sorted it is better to use merge algorithm
Array* Array:: unionOfSets_2(Array arr2){ // this function's parameter is call by value which means space complexity is O(len1 + len2)
    Array* newSet = new Array(length + arr2.length);  // T = O(n)
    //newSet->length = 0;
    int i = 0, j = 0, k =0; // i for index of arr1, j for index of arr2, k for index of newSet
    while(i < length && j < arr2.length){
        if(A[i] < arr2.A[j]){
            newSet->A[k++] = A[i++];
            //newSet->length++;
        }
        else if(arr2.A[j] < A[i]){
            newSet->A[k++] = arr2.A[j++];
            //newSet->length++;
        }
        else{
            newSet->A[k++] = A[i];
            i++; j++;
            //newSet->length++;
        }
    }
    while(i < length){
        newSet->A[k++] = A[i++];
        //newSet->length++;
    }
    while(j < arr2.length){
        newSet->A[k++] = arr2.A[j++];
        //newSet->length++;
    }
    newSet->length = k;
    return newSet;
}


// intersection of 2 a and b sets. int A[] = {1, 3, 5, 6, 8}; int B[] = {2, 3, 8, 12, 16, 18}; intersection(A, B) => elements which exist in both sets = {3, 8};
// below function is for any sets. T = O(n ^ 2); Space = O(1);
Array* Array:: intersectionOfSets_1(Array arr2){
    Array* newSet = new Array(length + arr2.length);
    newSet->length = 0;
    int k = 0; // for index of newSet
    for(int i = 0; i<length; i++){
        for(int j = 0; j<arr2.length; j++){
            if(A[i] == arr2.A[j]){
                newSet->A[k++] = A[i];
            }
        }
    }
    if(k == 0){
        printf("There is no equal elements, no intersection\n");
        //free(newSet);
    }
    else newSet->length = k;
    return newSet;
}

// below function is only for sorted sets of A and B
Array* Array :: intersectionOfSets_2(Array arr2){
    Array* newSet = new Array(length+arr2.length);
    int i = 0, j = 0, k = 0; // i for index of arr1, j for index of arr2, k for index of newSet
    while(i < length && j < arr2.length){
        if(A[i] < arr2.A[j])
            i++;
        else if(arr2.A[j] < A[i])
            j++;
        else {
            newSet->A[k++] = A[i];
            i++; j++;
        }
    }
    if(k == 0) printf("There is no intersection\n");
    newSet->length = k;
    return newSet;
}

// difference of set A and set B: A={1,2,3} and B={3,5}, then A−B={1,2} -> this is a set which  only exist in A not in B.
Array* Array:: subtractionOfSets_1(Array arr2){
    Array* newSet = new Array(length + arr2.length);
    int k = 0; // for index of newSet
    for(int i = 0; i<length; i++){
        int status = 0;
        for(int j = 0; j<arr2.length; j++){
            if(A[i] == arr2.A[j]){
                status = 1;
                break;
            }
        }
        if(status == 0){
            newSet->A[k++] = A[i];
        }
    }
    newSet->length = k;
    if(newSet->length == 0){
        printf("Subtraction is 0.\n");
    }
    return newSet;
}

// this is for only sorted arrays
Array* Array:: subtractionOfSets_2(Array arr2){
    Array* newSet = new Array(length + arr2.length);
    int i = 0, j = 0, k = 0; // i for arr1, j for arr2, k for newSet
    while(i < length && j < arr2.length){
        if(A[i] < arr2.A[j]){
            newSet->A[k++] = A[i++];
        }
        else if(arr2.A[j] < A[i]) j++;
        else {
            i++; j++;
        }
    }
    while(i < length)
        newSet->A[k++] = A[i++];
    newSet->length = k;
    if(newSet->length == 0) printf("There is no difference\n");
    return newSet;
}





int main()
{

    int sizeArr;
    do{
        printf("Enter the size of an array: ");
        scanf("%d", &sizeArr);
        if(sizeArr<0)printf("Invalid size for an Array\n");
        printf("\n");
    }while(sizeArr<0);
    Array* arr1 = new Array(sizeArr);


    int choice;
    int index, element;
    do{
        printf("\n\n______________________________________________MENU_______________________________________________\n");
        printf("1 => Insert || 2 => Delete || 3 => Search || 4 => Sum || 5 => Display || 6 => Reverse array\n");
        printf("7 => Replace element with other one || 8 => Get minimum element || 9 => Get maximum element || 10 => Exit\n");

        printf("\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the index to insert %d: ", element);
            scanf("%d", &index);
            arr1->insertElement(index, element);
            break;
        case 2:
            printf("Enter the index of an element to delete it: ");
            scanf("%d", &index);
            arr1->delElement(index);
            break;
        case 3:
            printf("Enter the element you want to search: ");
            scanf("%d", &element);
            index = arr1->linearSearch(element);
            printf("Element index is %d\n", index);
            break;
        case 4:
            printf("Sum of elements is %d\n", arr1->sumOfElements());
            break;
        case 5:
            arr1->display();
            break;
        case 6:
            arr1->reverseArray();
            break;
        case 7:
            printf("Enter the element you want to insert: ");
            scanf("%d", &element);
            printf("Enter index to put it: "); scanf("%d", &index);
            arr1->setElement(element, index);
            break;
        case 8:
            printf("The minimum element is %d\n", arr1->getMin());
            break;
        case 9:
            printf("The maximum element is %d\n", arr1->getMax());
        }
    }while(choice < 10 && choice>0);
    if(choice == 10) printf("\n\nThanks for using our program\n");
    else printf("\nEnter valid choice\n");
    return 0;
}
