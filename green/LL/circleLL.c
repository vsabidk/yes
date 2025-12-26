#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *tail = NULL;

// Create node
struct node* create_node(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Insert at beginning
void insert_begin(int value) {
    struct node *newnode = create_node(value);

    if (tail == NULL) {            // first node
        tail = newnode;
        tail->next = tail;
        return;
    }

    newnode->next = tail->next;    // new node -> first node
    tail->next = newnode;          // tail -> new first
}

// Insert at end
void insert_end(int value) {
    struct node *newnode = create_node(value);

    if (tail == NULL) {
        tail = newnode;
        tail->next = tail;
        return;
    }

    newnode->next = tail->next;    // new -> first
    tail->next = newnode;          // old tail -> new
    tail = newnode;                // update tail
}

// Insert at position
void insert_pos(int value, int pos) {
    if (pos < 1) {
        printf("\nInvalid position.\n");
        return;
    }

    if (tail == NULL || pos == 1) {
        insert_begin(value);
        return;
    }

    struct node *newnode = create_node(value);
    struct node *temp = tail->next;  // first node
    int i = 1;

    while (i < pos - 1 && temp != tail) {
        temp = temp->next;
        i++;
    }

    if (temp == tail) {  // position greater than length → insert end
        insert_end(value);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete beginning
void delete_begin() {
    if (tail == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = tail->next;   // first node

    if (temp == tail) {               // one node
        tail = NULL;
    } else {
        tail->next = temp->next;      // skip first
    }

    free(temp);
}

// Delete end
void delete_end() {
    if (tail == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = tail->next;   // first node

    if (temp == tail) {               // one node only
        tail = NULL;
        free(temp);
        return;
    }

    // find node before tail
    while (temp->next != tail)
        temp = temp->next;

    temp->next = tail->next;          // last removed
    free(tail);
    tail = temp;                      // new tail
}

// Delete at position
void delete_pos(int pos) {
    if (tail == NULL || pos < 1) {
        printf("\nInvalid position.\n");
        return;
    }

    if (pos == 1) {
        delete_begin();
        return;
    }

    struct node *temp = tail->next;   // first node
    int i = 1;

    while (i < pos - 1 && temp->next != tail->next) {
        temp = temp->next;
        i++;
    }

    if (temp->next == tail->next) {   // out of range
        printf("\nPosition out of range.\n");
        return;
    }

    struct node *del = temp->next;

    if (del == tail)           // deleting last node
        tail = temp;

    temp->next = del->next;
    free(del);
}

// Delete by value
void delete_value(int value) {
    if (tail == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = tail->next, *prev = tail;

    do {
        if (temp->data == value) {

            if (temp == tail && temp == tail->next) {
                tail = NULL;    // one node
            } else {
                prev->next = temp->next;

                if (temp == tail)
                    tail = prev;     // deleting last node
            }

            free(temp);
            printf("\nValue deleted.\n");
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != tail->next);

    printf("\nValue not found.\n");
}

// Display list
void display() {
    if (tail == NULL) {
        printf("\nList empty.\n");
        return;
    }

    struct node *temp = tail->next;  // first node

    printf("\nCircular List: ");

    while (temp != tail) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("%d -> (back to start)\n", tail->data);
}

int main() {
    int ch, val, pos;

    while (1) {
        printf("\n---- Circular Linked List ----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Delete by Value\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
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
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 7:
                printf("Enter value: ");
                scanf("%d", &val);
                delete_value(val);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}
