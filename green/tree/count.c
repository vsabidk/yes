#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

/* TOTAL NUMBER OF NODES */
int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* COUNT LEAF NODES */
int countLeafNodes(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

/* COUNT INTERNAL (NON-LEAF) NODES */
int countInternalNodes(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

/* COUNT NODES WITH DEGREE 1 */
int countDegreeOne(struct node* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL))
        count = 1;

    return count + countDegreeOne(root->left) + countDegreeOne(root->right);
}

/* COUNT NODES WITH DEGREE 2 */
int countDegreeTwo(struct node* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    if (root->left != NULL && root->right != NULL)
        count = 1;

    return count + countDegreeTwo(root->left) + countDegreeTwo(root->right);
}

int main() {
    struct node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nTotal nodes        : %d", countNodes(root));
    printf("\nLeaf nodes         : %d", countLeafNodes(root));
    printf("\nInternal nodes     : %d", countInternalNodes(root));
    printf("\nNodes with degree 1: %d", countDegreeOne(root));
    printf("\nNodes with degree 2: %d", countDegreeTwo(root));

    return 0;
}
