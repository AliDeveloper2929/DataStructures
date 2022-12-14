#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getLengthOfString(char A[]){
    // char A[] = {'s', 'a', 'l', 'o', 'm', '\0'};
    int i = 0;
    int length = 0;
    while(A[i] != '\0'){
        length++; i++;
    }
    return length;
}


void changeCaseOfChars(char A[]){
    /* in ASCII code 65 => 'A'  97 => 'a'
                     66 => 'B'  98 => 'b'
                     90 => 'Z'  122=> 'z'

    */
    for(int i = 0; A[i] != '\0'; i++){
        if(A[i] >= 65 && A[i] <= 90){  // if character A[i] is upper case letter
            A[i] = A[i] + 32;
        }
        else if(A[i] >= 97 && A[i] <= 122) // else if A[i] is lower case letter
            A[i] = A[i] -32;
        else{
            printf("You added character other than letter of english alphabet in your string. No upper case of that char\n");
        }
    }
}

// below function changes all the characters to upper case
void toUpperCase(char A[]){
    for(int i = 0; A[i] != '\0'; i++){
        if(A[i] >= 97 && A[i] <= 122) // that is lower case
            A[i] = A[i] -32;
    }
}

void toLowerCase(char A[]){
    for(int i = 0; A[i] != '\0'; i++){
        if(A[i] >= 65 && A[i] <= 90)
            A[i] += 32;
    }
}

// if char A[] = "How are you";  in this string there are 3 words. For that we just count spaces and add 1.
int countWordsInString(char A[]){
    int i = 1;
    int numOfSpaces = 0;
    while(A[i] != '\0'){
        if(A[i] == ' ' && A[i-1] != ' ')
            numOfSpaces += 1;
        i++;
    }
    if(A[i-1] == ' ')return numOfSpaces;
    return numOfSpaces+1;
}

// "how are you" => 5; vowels are 'a,e,i,o,u,A,E,I,O,U'
int countVowelsInString(char A[], int isVowel){
    int countVowel = 0, countCons = 0;
    int i = 0;
    while(A[i] != '\0'){
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
            countVowel += 1;
        else if((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z'))
            countCons += 1;
        i++;
    }
    if(isVowel == 1) return countVowel;
    else  return countCons;
}

// if the string consists of only english alphabets and nums then it is valid
bool isValidStr(char* A){
    for(int i = 0; A[i] != '\0'; i++){
        if( !(A[i] >= 'a' && A[i] <= 'z') && !(A[i] >= 'A' && A[i] <= 'Z') && !(A[i] >= 48 && A[i] <= 57) )
            return false;
    }
    return true;
}

void reverseStr(char* A){
    int length = 0;
    int i = 0;
    while(A[i++] != '\0')
        length++;



    i = 0; int j = length-1; // j is last char's index Ex: "salom"

    while(i < j){
        // swap A[i] and A[j];
        char temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++; j--;
    }
}

bool isSame(char* A1, char* A2){

    int i;
    for(i=0; A1[i] !='\0'; i++){
        if(A1[i] != A2[i]) return false;
    }
    if(A2[i] != '\0')return false;

    return true;
}

void compareArrs(char* A1, char* A2){
    int i, j;
    for(i = 0, j = 0; A1[i] != '\0' && A2[j] != '\0'; i++, j++){
        if(A1[i] != A2[j])
            break;
    }
    if(A1[i] == A2[j]) printf("Arrays are equal\n");
    else if (A1[i] < A2[j]) printf("A1 < A2\n");
    else printf("A1 > A2\n");
    return;
}


// below function finds duplicates in a string. It prints duplicates as well as occurances of it.
void printDuplicates(char* A){


    // a = 97 in ASCII
    // z = 122
    // A = 65
    // Z = 90  So we need hashArray of size 122-65+1 = 58 for storing occurances
    int HashArray[58] = {0};

    for(int i = 0; A[i] != '\0'; i++){ // this loop stores occurances of chars in hashArray at appropriate index.
        HashArray[ A[i]-65 ] += 1;    // occurances of 'a' should be stored in HashArray[0]
    }
    for(int i = 0; i<58; i++){
        if(HashArray[i] > 1){
            printf("There are %d '%c' in a string   \"%s\"\n", HashArray[i], i+65, A);
        }
    }
}


// below function checks if string is anagram or not. Anagram means 2 string uses same set of chars; Ex: "medical" and "decimal" is anagram
bool isAnagram(char* A1, char* A2){
    int len1 = 0;
    for(int i = 0; A1[i] != '\0'; i++){
        len1++;
    }

    int len2 = 0;
    for(int i = 0; A2[i] != '\0'; i++){
        len2++;
    }
    if(len1 != len2) return false;

    int hashArray[122-65+1] = {0}; // all chars from 'A'  to 'z'
    for(int i = 0; A1[i] != '\0'; i++){
        hashArray[ A1[i]-65 ] += 1;
    } //after loop: occurances of chars in A1 have been stored at hashArray at appropriate index;

    for(int i = 0; A2[i] != '\0'; i++){
        hashArray[A2[i]-65] -=1;
        if(hashArray[ A2[i] - 65 ] == -1)
            return false;
    }
    return true;
}


int main()
{
    char A1[] = "asdafghjk  lAmponbiR";
    char A2[] = "inboamphA  gjfkdlsaR";
    if(isAnagram(A1, A2))
        printf("\"%s\"  and  \"%s\"  is anagram\n", A1, A2);
    else printf("\"%s\"  and  \"%s\"  is not anagram\n", A1, A2);
    return 0;
}
