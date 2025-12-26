#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Create new node */
struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* Insert node in BST */
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

/* HEIGHT of Tree */
int height(struct node* root) {
    if (root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

/* DEPTH of a given node */
int depth(struct node* root, int key, int level) {
    if (root == NULL)
        return -1;

    if (root->data == key)
        return level;

    int left = depth(root->left, key, level + 1);
    if (left != -1)
        return left;

    return depth(root->right, key, level + 1);
}

int main() {
    struct node* root = NULL;
    int n, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Height of tree: %d\n", height(root));

    printf("Enter node to find depth: ");
    scanf("%d", &key);

    int d = depth(root, key, 0);
    if (d != -1)
        printf("Depth of node %d is: %d\n", key, d);
    else
        printf("Node not found\n");

    return 0;
}
