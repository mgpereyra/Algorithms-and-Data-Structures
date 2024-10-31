#include "BinaryTree.h"

int main() {
    BSTNode * bst = NULL;

    Employee e1 = {101, "Alice"};
    Employee e2 = {203, "Bob"};
    Employee e3 = {145, "Charlie"};
    Employee e4 = {101, "Alice's clone"};

    // Insert employees into the BST
    bst = insertNode(bst, e1);
    bst = insertNode(bst, e2);
    bst = insertNode(bst, e3);
    bst = insertNode(bst, e4);

    printf("In-order traversal of the BST:\n");
    printInOrder(bst);
    printf("\n");

    Employee e;
    inputEmployee(&e);
    insertNode(bst,e);

    printf("In-order traversal of the BST:\n");
    printInOrder(bst);
    printf("\n");

    // Search for an employee
    int searchId = 145;
    printf("Searching for employee id: %d\n\n",searchId);
    BSTNode * foundNode = searchNode(bst, searchId);
    if (foundNode) {
        printf("Employee found:\n");
        printEmployee(&foundNode->data);
    } else {
        printf("Employee with ID %d not found\n", searchId);
    }

    // Free the memory allocated for the BST
    freeBST(bst);

    return 0;
}
