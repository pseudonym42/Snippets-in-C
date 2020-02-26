#include <stdio.h>
#include <stdlib.h>


void append();
void traverse();

// prepend();
// add();
// deleteFirst()
// delete();
// getLength();
// reverse();
// swap();
// sort();

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


int main(void) {
    int choice;
    while (1) {
        printf("~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("1. Append item\n");
        printf("2. Display all items\n");
        printf("3. Quit\n");
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
                exit(1);
            default:
                printf("Invalid input\n");
        }
    }
}
