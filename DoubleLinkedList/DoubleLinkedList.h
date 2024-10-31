#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct Employee{
    int id;
    char name[50];
}Employee;

typedef Employee Data;

int createEmployee(Employee * employee);
void printEmployee(Employee * employee);

typedef struct Node{
    struct Node * previous;
    struct Node * next;
    Data data;
}Node;

typedef struct DoubleLinkedList{
    Node * head;
	Node * tail;
}DoubleLinkedList;

void createDoubleLinkedList(DoubleLinkedList * list);
int insertAtTheBeginning(DoubleLinkedList * list, Data * data);
int insertInOrderAsc(DoubleLinkedList * list, Data * data);
void printDoubleLinkedListEmployee(DoubleLinkedList * list);
int getLenghtOfDoubleLinkedList(DoubleLinkedList * list);
void swapNodePointersOfDoubleLinkedList(Node * nodeA, Node * nodeB);

void deleteDuplicatesFromDoubleLinkedList(DoubleLinkedList * list);
void deleteNodeFromDoubleLinkedList(DoubleLinkedList * list, Node * node);
int dataIsEqual(Data * dataA, Data * dataB);
void sortDoubleLinkedList(DoubleLinkedList * list);
int isDataAIsLessThanB(Data * dataA, Data * dataB);

#endif // DOUBLELINKEDLIST_H_INCLUDED
