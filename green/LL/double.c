#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

// Create a new node
struct node* create_node(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at beginning
void insert_begin(int value) {
    struct node *newnode = create_node(value);

    if (head == NULL) { // first node
        head = tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

// Insert at end
void insert_end(int value) {
    struct node *newnode = create_node(value);

    if (tail == NULL) { // empty list
        head = tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

// Insert at position
void insert_pos(int value, int pos) {
    if (pos < 1) {
        printf("\nInvalid position.\n");
        return;
    }

    if (pos == 1 || head == NULL) {
        insert_begin(value);
        return;
    }

    struct node *temp = head;
    int i = 1;

    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) { // insert at end
        insert_end(value);
        return;
    }

    struct node *newnode = create_node(value);
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

// Insert to the left of a given node (by value)
void insert_left_of(int value, int target) {
    if (head == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nTarget value %d not found.\n", target);
        return;
    }

    struct node *newnode = create_node(value);

    if (temp == head) { // insert before head
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    } else {
        newnode->next = temp;
        newnode->prev = temp->prev;
        temp->prev->next = newnode;
        temp->prev = newnode;
    }

    printf("\nInserted %d to the left of %d\n", value, target);
}

// Delete beginning
void delete_begin() {
    if (head == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = head;

    if (head == tail) { // one node only
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

// Delete end
void delete_end() {
    if (tail == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = tail;

    if (head == tail) { // only one node
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

// Delete at position
void delete_pos(int pos) {
    if (head == NULL || pos < 1) {
        printf("\nInvalid position.\n");
        return;
    }

    if (pos == 1) {
        delete_begin();
        return;
    }

    struct node *temp = head;
    int i = 1;

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range.\n");
        return;
    }

    if (temp == tail) {
        delete_end();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

// Delete by value
void delete_value(int value) {
    if (head == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == value)
            break;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nValue not found.\n");
        return;
    }

    if (temp == head)
        delete_begin();
    else if (temp == tail)
        delete_end();
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

// Search value
void search(int value) {
    struct node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("\nValue found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("\nValue not found.\n");
}

// Display forward
void display_forward() {
    if (head == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = head;
    printf("\nForward: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Display backward
void display_backward() {
    if (tail == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = tail;
    printf("\nBackward: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    int ch, val, pos, target;

    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Insert Left of Node\n");  // New option
        printf("5. Delete Beginning\n");
        printf("6. Delete End\n");
        printf("7. Delete Position\n");
        printf("8. Delete by Value\n");
        printf("9. Search\n");
        printf("10. Display Forward\n");
        printf("11. Display Backward\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_begin(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insert_pos(val, pos);
                break;

            case 4:
                printf("Enter value to insert and target node value: ");
                scanf("%d %d", &val, &target);
                insert_left_of(val, target);
                break;

            case 5:
                delete_begin();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 8:
                printf("Enter value: ");
                scanf("%d", &val);
                delete_value(val);
                break;

            case 9:
                printf("Enter value: ");
                scanf("%d", &val);
                search(val);
                break;

            case 10:
                display_forward();
                break;

            case 11:
                display_backward();
                break;

            case 12:
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}
