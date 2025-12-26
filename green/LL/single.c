#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* ------------------ CREATE NEW NODE ------------------ */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* ------------------ INSERTION OPERATIONS ------------------ */

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {       // If list empty
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at given position (1-based)
void insertAtPosition(int value, int pos) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

/* ------------------ DELETION OPERATIONS ------------------ */

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) { // Only one element
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}



// Delete node by value (first occurrence)
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If value is at head
    if (head->data == value) {
        deleteFirst();
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value not found!\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

/* ------------------ SEARCH OPERATION ------------------ */

void search(int value) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value not found in list!\n");
}

/* ------------------ DISPLAY ------------------ */

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ------------------ MENU-DRIVEN MAIN ------------------ */

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete at Position\n");
        printf("7. Delete by Value\n");
        printf("8. Search\n");
        printf("9. Display\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 9:
                display();
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
