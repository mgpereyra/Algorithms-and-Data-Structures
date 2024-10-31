#include "BinaryTree.h"

BSTNode * createNode(Data data) {
    BSTNode * newNode = (BSTNode *)malloc(sizeof(BSTNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;  // Copy the data
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode * insertNode(BSTNode * root, Data data) {
    if (root == NULL) {
        // If the tree is empty, the new node becomes the root
        return createNode(data);
    }

    // Recursively insert in the left or right subtree based on the `id`
    if (data.id < root->data.id) {
        root->left = insertNode(root->left, data);
    } else if (data.id > root->data.id) {
        root->right = insertNode(root->right, data);
    } else {
        printf("Duplicate Employee ID is not allowed: %d\n\n", data.id);
    }

    return root;  // Return the unchanged root pointer
}

BSTNode * searchNode(BSTNode * root, int id) {
    // Base case: root is null or the id matches the root's id
    if (root == NULL || root->data.id == id) {
        return root;
    }

    // If the id is smaller than root's id, search in the left subtree
    if (id < root->data.id) {
        return searchNode(root->left, id);
    }

    // If the id is greater, search in the right subtree
    return searchNode(root->right, id);
}

void printEmployee(Employee * employee) {
    if (!employee) return;
    printf("ID: %d, Name: %s\n", employee->id, employee->name);
}

void printInOrder(BSTNode * root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    printInOrder(root->left);

    // Print the root (current node)
    printEmployee(&root->data);

    // Traverse the right subtree
    printInOrder(root->right);
}

int inputEmployee(Employee * employee) {
    if(!employee)
        return FALSE;
    printf("Enter Employee ID: ");
    scanf("%d", &employee->id);
    printf("Enter Employee Name: ");
    scanf("%s", employee->name);
    return TRUE;
}

void freeBST(BSTNode * root) {
    if (root == NULL) return;

    // Recursively free the left and right subtrees
    freeBST(root->left);
    freeBST(root->right);

    // Free the current node
    free(root);
}
