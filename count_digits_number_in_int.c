/*
    Program to Count Number of Digits in an Integer

    This program takes an integer from the user and calculates the number of digits.

    For example: If the user enters 2319, the output of the program will be 4.
*/

#include <stdio.h>

int main(void) {

    int userInt, n = 1;
    scanf("%d", &userInt);

    while (userInt >= 10) {
        userInt /= 10;
        n += 1;
    }

    printf("\nNumber of digits = %d\n", n);
    return 0;
}
