#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct Student{
    char name[32];
    int id;
}Student;

typedef struct Node{
    Student * data;
    struct Node * next;
}Node;

typedef struct Stack{
    struct Node * last;
}Stack;

void createStack(Stack * myStack);
void push(Stack * myStack, Student * myStudent);
int pop(Stack * myStack, Student * myStudent);
int peek(Stack * myStack, Student * myStudent);
int stackIsEmpty(Stack * myStack);
int stackIsFull(Stack * myStack);
void emptyStack(Stack * myStack);

void showAndPopStack(Stack * myStack);

#endif // STACK_H_INCLUDED
