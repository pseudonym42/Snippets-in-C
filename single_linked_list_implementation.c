#include <stdio.h>
#include <stdlib.h>


void append();
void traverse();
int getLength();
void deleteItemByIndex();

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

void deleteItemByIndex() {
    printf("\n");
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    unsigned int itemIndex;
    unsigned int len = (unsigned int) getLength();
    printf("Type index number of the item that needs to be deleted\n");
    scanf("%d", &itemIndex);
    printf("\n");

    if ((len - 1) < itemIndex || itemIndex < 0) {
        printf("The index of the item you'd like to remove should be a positive number more than zero and less than %u\n", len);
        return;
    }

    struct Item* temp = root;
    if (itemIndex == 0) {
        root = temp->link;
        temp->link = NULL;
        free(temp);
        return;
    }

    unsigned int i = 1;
    struct Item* itemToDelete;

    while (i < itemIndex) {
        temp = temp->link;
        i++;
    }
    itemToDelete = temp->link;

    temp->link = itemToDelete->link;
    itemToDelete->link = NULL;
    free(itemToDelete);
    printf("Deletion is successfull\n");
    return;
}

int getLength() {
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
    return length;
}


int main(void) {
    int choice;
    while (1) {
        printf("~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("1. Append item\n");
        printf("2. Display all items\n");
        printf("3. Display length\n");
        printf("4. Delete item by index\n");
        printf("5. Quit\n");
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
                getLength();
                break;
            case 4:
                deleteItemByIndex();
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid input\n");
        }
    }
}
