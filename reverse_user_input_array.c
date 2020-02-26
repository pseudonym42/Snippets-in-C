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
    size_t arrayLength = sizeof(array)/sizeof(int);

    for(int i = 0; i < arrayLength; i++) {
        scanf("%d", &array[i]);
    }

    reverseArray(array, arrayLength);

    for(int i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
