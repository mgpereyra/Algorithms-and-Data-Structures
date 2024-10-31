#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct Employee{
    int id;
    char name[50];
}Employee;

typedef Employee Data;

typedef struct BSTNode{
    Data data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode* createNode(Data data);
BSTNode* insertNode(BSTNode * root, Data data);
BSTNode* searchNode(BSTNode * root, int id);
void printEmployee(Employee * employee);
void printInOrder(BSTNode * root);
int inputEmployee(Employee * employee);
void freeBST(BSTNode * root);

#endif // BINARYTREE_H_INCLUDED
