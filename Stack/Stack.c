#include "Stack.h"

void createStack(Stack * myStack){
    myStack->last = NULL;
}

void push(Stack * myStack, Student * myStudent){
    Node * newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Not enough memory...");
        return;
    }
    newNode->next=myStack->last;
    newNode->data=myStudent;
    myStack->last=newNode;
}

int pop(Stack * myStack, Student * myStudent){
    if(myStack->last == NULL){
        myStudent = NULL;
        return FALSE;
    }
    Node * temp = myStack->last;

    myStudent->id = temp->data->id;
    strcpy(myStudent->name,temp->data->name);

    myStack->last=myStack->last->next;
    free(temp);
    return TRUE;
};

int peek (Stack * myStack, Student * myStudent){
    if(myStack->last == NULL){
        myStudent = NULL;
        return FALSE;
    }

    myStudent->id = myStack->last->data->id;
    strcpy(myStudent->name,myStack->last->data->name);

    return TRUE;
}

int stackIsEmpty(Stack * myStack){
    if(myStack->last){
        return FALSE;
    }
    return TRUE;
}

int stackIsFull(Stack * myStack){
    Node * newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return TRUE;
    }
    return FALSE;
}

void emptyStack(Stack * myStack){
    Node * temp;
    while(myStack->last!=NULL){
        temp=myStack->last;
        myStack->last=myStack->last->next;
        free(temp);
    }
}



void showAndPopStack(Stack * myStack){
    Student * student = malloc(sizeof(Student));
    while(pop(myStack,student)==TRUE){
        printf("Student: %s, ID: %d has been popped from the stack...\n",student->name,student->id);
    }
    free(student);
}
