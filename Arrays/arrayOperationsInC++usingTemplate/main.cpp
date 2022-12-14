#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

template <class T>
class Array{
private:
    T* A;
    int sizeOfArr;
    int length;

public:

Array(){
    sizeOfArr = 20;
    length = 0;
    A = new T[sizeOfArr];
}

Array(int sizeOfArray){
    sizeOfArr = sizeOfArray;
    length = 0;
    A = new T[sizeOfArr];
}

~Array(){
    delete []A;
}

// following are prototypes of functions:
void  display(); // time complexity => T = O(n). This prints all the elements of an array
void append(T num); // T = O(1) if enough space. Space complexity => S = O(1). this is adds num at the end of the array
void insertElement(int index, T num); // T = O(n),  S = O(1).
void delElement(int index); // T = O(n), S = O(1).
T delElement1(int index); // T = O(n). S = O(1)
int linearSearch(T key); // time complexity: O(n)
int binarySearch(T key); // time complexity: ceil of O(log n) base 2:
int recursiveBinSearch(T key, int low, int high); // space and time complexity is ceil of O(log n) base 2. iterative method is better than this
T getElement(int index);
void setElement(T element, int index); // T = O(1), S = O(1). it replaces a new element with the old one
T getMax();  // T = O(n)
T getMin(); //  T = O(n)
T sumOfElements();
void reverseArray();
void insertInSortedArr3(T element);  // this is the best of all three insertInSortedArr functions.
void insertInSortedArr2(T element);  // this one is better than the 1st one.in terms of time complexity
void insertInSortedArr1(T element);
bool isSorted();
void shiftNegativesToLeft();
void mergeSortedArrays_1(T arr2[], int len_arr2, T outputArr[]);
T* mergeSortedArrays_3(T arr2);
T* mergeSortedArrays_2(T arr2[], int len2);
T* unionOfSets_1(T arr2); // for any set arr1 and arr2. T = O(n^2);
T* unionOfSets_2(T arr2); // for only sorted arr1 and arr2. Because this uses merge algorithm. T = O(len1 + len2) = O(n)
T* subtractionOfSets_1(T arr2); // for any set arr1 and arr2. T = O(n^2);
T* subtractionOfSets_2(T arr2); // for only sorted arr1 and arr2. Because this uses merge algorithm. T = O(len1 + len2) = O(n)
T* intersectionOfSets_1(T arr2);//int A[] = {1, 3, 5, 6, 8}; int B[] = {2, 3, 8, 12, 16, 18};        // for any sets
T* intersectionOfSets_2(T arr2);//intersection(A, B) => elements which exist in both sets = {3, 8};  // for only sorted sets. this uses merge algorithm
};

// end of class
template <class T>
void Array<T>:: display(){
    printf("Array elements are: ");
    for(int i=0; i<length; i++){
        cout<<A[i]<<" ";
    }
    printf("\n");
}

template<class T>
void Array<T>:: append(T num){
    if(length < sizeOfArr) {
        A[length] = num;
        length ++;
    }
    else{
        printf("There is no space in Array.\n");
    }
    return;
}

template<class T>
void Array<T>:: insertElement(int index, T num){
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
template <class T>
void Array<T>:: delElement(int index){
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
template<class T>
T Array<T>:: delElement1(int index){
    T deletedEle = A[index];
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
template <class T>

int Array<T>:: linearSearch(T key){
    for(int i=0; i<length; i++)
        if(A[i] == key) return i;
    printf("Search is unsuccessful\n");
    return -1;  // if not found
}

/* below is binary search function. array must be sorted. O(log n) base 2*/
template<class T>
int Array<T>:: binarySearch(T key){
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
template<class T>
int Array<T>:: recursiveBinSearch(T key, int low, int high){
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
template <class T>
T Array<T>:: getElement(int index){
    if(index < length && index >=0) return A[index];
    printf("Out of index error\n");
    return -1;
}

// below function sets given element at given index. it replaces a new element with the old one
template<class T>
void Array<T>:: setElement(T element, int index){
    if(index >=0 && index < length){
        A[index] = element;
        return;
    }
    printf("Give less index, out of index error\n");
    return;
}

//  below function returns the max number in array.
template<class T>
T Array<T>:: getMax(){
    if(length == 0) {
        printf("there is no element in an array\n");
        return 0;
    }
    T maxEle = A[0];
    for(int i = 1; i<length; i++){
        if(A[i] > maxEle) maxEle = A[i];
    }
    return maxEle;
}

//  below function returns the min number in array.
template <class T>
T Array<T>:: getMin(){
    if(length == 0) {
        printf("there is no element in an array\n");
        return 0;
    }
    T minEle = A[0];
    for(int i = 1; i<length; i++){
        if(A[i] < minEle) minEle = A[i];
    }
    return minEle;
}

template<class T>
T Array<T>:: sumOfElements(){
    T total = 0;
    for(int i = 0; i<length; i++){
        total+=A[i];
    }
    return total;
}


// below function reverses given array.
template<class T>
void Array<T>:: reverseArray(){
    if(length == 0){
        printf("There is no element in an array\n");
        return;
    }
    int i, j;
    for(i = 0, j = length-1; i<j; i++, j--){
        // swap(A[i], A[j]);
        T temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("Array is reversed\n");
    return;
}


// below function adds inserts nums to a sorted array at a appropriate index
template<class T>
void Array<T>:: insertInSortedArr1(T element){
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
template<class T>
void Array<T>:: insertInSortedArr2(T element){
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
template<class T>
void Array <T>:: insertInSortedArr3(T element){
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
template <class T>
bool Array<T>:: isSorted(){
    for(int i = 0; i<length-1; i++){
        if(A[i] > A[i+1]) return false;
    }
    return true;
}

// shifting negative nums to left and positives to the right side
template<class T>
void Array<T>:: shiftNegativesToLeft(){
    int i = 0; int j = length-1; // i index points to positive nums, j index point to negative nums.
    while(i < j){
        while(A[i] < 0){i++;}  // after this i points to the positive number from beginning
        while(A[j] >= 0){j--;}  // after this j points to the negative number from the end
        if(i < j){
            // swap(ptr->A[i], ptr->A[j]);
            T temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    return;
}

// below function merges two sorted arrays int a new array.
// Ex: int A1[] = {7, 9, 15, 18, 22}; int A2[] = {1, 3, 8, 12, 20}; int outputArr[] = {1, 3, 7, 8, 9, 12, 15, 18, 20, 22};
template<class T>
void Array<T>:: mergeSortedArrays_1(T arr2[], int len_arr2, T outputArr[]){ // we assume outputArr has enough space for elements of arr1 and arr2:
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
template<class T>
T* Array<T>:: mergeSortedArrays_2(T arr2[], int len2){
    int len3 = length + len2;
    T* outputArr = new T[len3];
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

template<class T>
T* Array<T>:: mergeSortedArrays_3(T arr2){
    int len3 = length + arr2.length;
    T* outputArr = new T(len3); // this creates an outputArr variable which is pointer to the object of class Array. So object is in heap.
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
template<class T>
T* Array<T>:: unionOfSets_1(T arr2){ // this function's parameter is call by value which means space complexity is O(len1 + len2)
    T* newSet = new T(length+arr2.length);  // T = O(n^2);
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
template<class T>
T* Array <T>:: unionOfSets_2(T arr2){ // this function's parameter is call by value which means space complexity is O(len1 + len2)
    T* newSet = new Array(length + arr2.length);  // T = O(n)
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
template<class T>
T* Array<T>:: intersectionOfSets_1(T arr2){
    T* newSet = new Array(length + arr2.length);
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
template<class T>
T* Array<T> :: intersectionOfSets_2(T arr2){
    T* newSet = new Array(length+arr2.length);
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
template<class T>
T* Array<T>:: subtractionOfSets_1(T arr2){
    T* newSet = new T(length + arr2.length);
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
template<class T>
T* Array<T>:: subtractionOfSets_2(T arr2){
    T* newSet = new T(length + arr2.length);
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
    /*Array* arr1 = new Array(30);
    Array* arr2 = new Array(30);
    for(int i = 0; i<20; i++){
        arr1->append(i+1);      // 1, 2, ...20
        arr2->append(i+10);     // 10, 11,.... 29
    }
    arr1->display();
    printf("\n");
    arr2->display();
    printf("\n");
    Array* arr3 = arr1->subtractionOfSets_1(*arr2);
    arr3->display();

    Array arr4(15);
    arr4.insertElement(0, 8);
    arr4.display();
    */
    Array<char> arr1(5);
    arr1.append('a');
    arr1.append('b');

    arr1.display();
    return 0;
}
