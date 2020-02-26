#include <stdio.h>
#include <stdlib.h>


void append();
void traverse();
void printLength();

// addBefore();
// addAfter();
// delete();


struct Item {
    int value;
    struct Item* link;
};
struct Item* root = NULL;


void append () {
    printf("\n");
    printf("Enter new item: ");
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item*));
    scanf("%d", &newItem->value);
    newItem->link = NULL;

    if (root == NULL) {
        root = newItem;
    } else {
        struct Item* temp = root;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newItem;
    }
    printf("Added item %d successfully\n", newItem->value);
    printf("\n");
    return;
}

void traverse() {
    printf("\n");
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Item* temp = root;
    do {
        printf("%d ---> ", temp->value);
        temp = temp->link;
    } while (temp != NULL);
    printf("NULL \n");
    return;
}

void printLength() {
    printf("\n");
    unsigned int length = 0;

    if (root != NULL) {
        struct Item* temp = root;
        do {
            length += 1;
            temp = temp->link;
        } while (temp != NULL);
    }

    printf("Number of items in the list: %i\n", length);
    return;
}


int main(void) {
    int choice;
    while (1) {
        printf("~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("1. Append item\n");
        printf("2. Display all items\n");
        printf("3. Display length\n");
        printf("4. Quit\n");
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~\n");

        printf("Select from the menu:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                append();
                break;
            case 2:
                traverse();
                break;
            case 3:
                printLength();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid input\n");
        }
    }
}
