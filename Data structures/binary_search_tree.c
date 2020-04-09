#include <stdio.h>
#include <stdlib.h>


void insert();


struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;


void insert () {
    printf("\n");
    printf("Enter new item: \n");
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    scanf("%d", &newNode->value);
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        struct Node *parentNode, *currentNode;
        currentNode = root;
        while (currentNode) {
            parentNode = currentNode;

            if (newNode->value > currentNode->value) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }

        if (newNode->value > parentNode->value) {
            parentNode->right = newNode;
        } else {
            parentNode->left = newNode;
        }

    }
    printf("Added node %d successfully\n", newNode->value);
    printf("\n");
    return;
}


int main(void) {
    int choice;
    while (1) {
        printf("~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("1. Insert item\n");
        printf("2. Quit\n");
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~\n");

        printf("Select from the menu:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                exit(1);
            default:
                printf("Invalid input\n");
        }
    }
}
