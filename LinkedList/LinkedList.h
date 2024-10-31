#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct Student{
    char name[50];
    int id;
}Student;

int createStudent(Student * student);

typedef struct Node{
    Student data;
    struct Node * next;
}Node;

typedef struct List{
    struct Node * head;
}List;

void createList(List * list);
int insertInOrderNoDuplicates(List * list, Student * student);
int isEmpty(List * list);
int isFull(List * list);
void showAndEmptyList(List * list);

#endif // LINKEDLIST_H_INCLUDED
