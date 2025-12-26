#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Create a new node
struct node* create_node(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Insert at end of list
void insert_end(struct node **head, int value) {
    struct node *newnode = create_node(value);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Display the list
void display(struct node *head) {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse the linked list
void reverse(struct node **head) {
    struct node *prev = NULL, *curr = *head, *next;

    while (curr != NULL) {
        next = curr->next;     // Store next
        curr->next = prev;     // Reverse pointer
        prev = curr;           // Move prev ahead
        curr = next;           // Move curr ahead
    }

    *head = prev;
    printf("\nList reversed successfully.\n");
}

// Sort the linked list using Bubble Sort
void sort_list(struct node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("\nList too small to sort.\n");
        return;
    }

    struct node *i, *j;
    int temp;

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("\nList sorted successfully.\n");
}

// Concatenate list2 at end of list1
void concatenate(struct node **head1, struct node **head2) {
    if (*head2 == NULL) {
        printf("\nSecond list is empty, nothing to concatenate.\n");
        return;
    }

    if (*head1 == NULL) {
        *head1 = *head2;
        *head2 = NULL;
        printf("\nLists concatenated (first list was empty).\n");
        return;
    }

    struct node *temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head2;
    *head2 = NULL;

    printf("\nLists concatenated successfully.\n");
}

// Merge two sorted linked lists into a new sorted list
struct node* merge_sorted(struct node* head1, struct node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *result = NULL;

    if (head1->data < head2->data) {
        result = head1;
        result->next = merge_sorted(head1->next, head2);
    } else {
        result = head2;
        result->next = merge_sorted(head1, head2->next);
    }

    return result;
}

int main() {
    struct node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int choice, value;

    while (1) {
        printf("\n----- Singly Linked List Operations -----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 to List 1\n");
        printf("8. Merge List 1 & List 2 (sorted)\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(&list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(&list2, value);
                break;

            case 3:
                display(list1);
                break;

            case 4:
                display(list2);
                break;

            case 5:
                sort_list(&list1);
                break;

            case 6:
                reverse(&list1);
                break;

            case 7:
                concatenate(&list1, &list2);
                break;

            case 8:
                printf("\nMerging lists (ensure both are sorted)...\n");
                merged = merge_sorted(list1, list2);
                printf("\nMerged List:\n");
                display(merged);
                break;

            case 9:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}
