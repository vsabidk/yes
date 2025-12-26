#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int pow;
    struct node *next;
};

// Create node
struct node* create_node(int c, int p) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("\nMemory Allocation Failed\n");
        exit(1);
    }
    newnode->coeff = c;
    newnode->pow = p;
    newnode->next = NULL;
    return newnode;
}

// Insert a term in descending power order
struct node* insert_term(struct node *head, int c, int p) {
    struct node *newnode = create_node(c, p);

    if (head == NULL || p > head->pow) {
        newnode->next = head;
        return newnode;
    }

    struct node *temp = head;
    while (temp->next != NULL && temp->next->pow >= p)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

// Display polynomial neatly
void display(struct node *head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        if (temp != head && temp->coeff >= 0)
            printf(" + ");

        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
    }
}

// Add P1 + P2
struct node* add_poly(struct node *p1, struct node *p2) {
    struct node *res = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            res = insert_term(res, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p2->pow > p1->pow) {
            res = insert_term(res, p2->coeff, p2->pow);
            p2 = p2->next;
        }
        else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                res = insert_term(res, sum, p1->pow);

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        res = insert_term(res, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        res = insert_term(res, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return res;
}

int main() {
    struct node *P1 = NULL, *P2 = NULL, *SUM = NULL;
    int n, c, p;

    printf("\nEnter number of terms in Polynomial P1: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter term %d (coeff power): ", i);
        scanf("%d %d", &c, &p);
        P1 = insert_term(P1, c, p);
    }

    printf("\nEnter number of terms in Polynomial P2: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter term %d (coeff power): ", i);
        scanf("%d %d", &c, &p);
        P2 = insert_term(P2, c, p);
    }

    printf("\nP1 = ");
    display(P1);

    printf("\nP2 = ");
    display(P2);

    SUM = add_poly(P1, P2);

    printf("\n\nSUM = ");
    display(SUM);

    printf("\n");
    return 0;
}
