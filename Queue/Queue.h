#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct student{
    int id;
    char name[30];
}t_student;

typedef t_student t_data;

typedef struct node{
    struct node * next;
    t_data data;
}t_node;

typedef struct queue{
    t_node * first;
    t_node * last;
}t_queue;

void showStudent(t_student * student);

int createQueue(t_queue * queue);
int queueIsFull(t_queue * queue);
int addToQueue(t_queue * queue, t_data * data);
int unQueue(t_queue * queue, t_data * data);
int queueIsEmpty(t_queue * queue);

#endif // QUEUE_H_INCLUDED
