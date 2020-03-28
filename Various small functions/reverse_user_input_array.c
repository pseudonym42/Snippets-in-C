/*
    Program to reverse in place an array of fixed sizeof

    Array elements are to be submitted by a user

    For example: If the user enters 1, 2, 3, the output of the program
    will print to the standard output: 3, 2, 1
*/

#include <stdio.h>

void reverseArray(int* arr, int len) {
    int tmp;
    for(int i = 0; i < len/2; i++) {
        tmp = *(arr + i);
        *(arr + i) = *(arr + len - 1 - i);
        *(arr + len - 1 - i) = tmp;
    }
}


int main(void) {
    int array[6] = {0};
    int arrayLength = (int)(sizeof(array)/sizeof(int));

    printf("Please insert 6 elements below: \n\n");
    for(int i = 0; i < arrayLength; i++) {
        scanf("%d", &array[i]);
    }

    reverseArray(array, arrayLength);

    for(int i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
