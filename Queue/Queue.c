#include "Queue.h"

void showStudent(t_student * student){
    if(student)
        printf("Student id: %d\nStudent name: %s\n\n",student->id, student->name);
};

int createQueue(t_queue * queue){
    queue->first = queue->last = NULL;
    return TRUE;
};

int queueIsFull(t_queue * queue){
    t_node * newNode = malloc(sizeof(t_node));
    if(!newNode){
        return TRUE;
    }else{
        free(newNode);
        return FALSE;
    }
};

int addToQueue(t_queue * queue, t_data * data){
    t_node * newNode = malloc(sizeof(t_node));
    if(newNode==NULL){
        return FALSE;
    }
    if(queue->first==NULL && queue->last==NULL){
        queue->first = queue->last = newNode;
    }else{
        queue->last->next = newNode;
        queue->last=newNode;
    }
    newNode->data=*data;
    newNode->next=NULL;
    return TRUE;
};

int unQueue(t_queue * queue, t_data * data){
    if(queue->first==NULL || queue->last==NULL){
        return FALSE;
    }
    *data=queue->first->data;
    t_node * aux = queue->first;
    if(queue->first == queue->last){
        queue->first = queue->last = NULL;
    }else{
        queue->first = queue->first->next;
    }
    free(aux);
    return TRUE;
};

int queueIsEmpty(t_queue * queue){
    if(queue->first==NULL || queue->last==NULL){
        return TRUE;
    }
    return FALSE;
};
