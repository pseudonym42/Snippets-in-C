#include <stdio.h>
#include <stdlib.h>
#define STACKMAXSIZE 5 // pre-processor macro


int stack[STACKMAXSIZE],
    top = -1;

void push(int);
int pop();
int isFull();
int isEmpty();
void traverse();


int main(void) {

    int choice, item;

    while (1) {

        printf("~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Traverse element\n");
        printf("4. Quit\n");
        printf("\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Element:");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item == 0) {
                    printf("Stack is in underflow\n");
                } else {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid input\n");
        }
    }
}

void push(int item) {
    if (isFull()) {
        printf("Stack is overflow\n");
    } else {
        top++;
        stack[top] = item;
        printf("%d is added to the stack\n\n", item);
    }
}

int isFull() {
    if (top == STACKMAXSIZE - 1) {
        return 1;
    }
    return 0;
}

int pop() {
    if (isEmpty()) {
        return 0;
    }
    return stack[top--];
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

void traverse() {
    if (isEmpty()) {
        printf("The stack is empty\n");
    } else {
        printf("See the stack below: \n");
        printf("|| Start ");
        for (int i=0; i<=top; i++) {
            printf("| %d ", stack[i]);
        }
        printf(" | End ||\n");
    }
}
