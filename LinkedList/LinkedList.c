#include "LinkedList.h"

int createStudent(Student * student){
    if(!student)
        return FALSE;

    printf("Please, input an ID for the new student (-1 to finish): ");
    int validInput = FALSE;
    while (!validInput) {
        if (scanf("%d", &student->id) == 1) {
            validInput = TRUE;
        } else {
            printf("Invalid input. Please enter a valid integer ID.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
    if(student->id==-1){
        return FALSE;
    }

    printf("Now input the full name: ");
    scanf(" ");
    if (fgets(student->name, sizeof(student->name), stdin) == NULL) {
        printf("Error reading name.\n");
        return FALSE;
    }

    return TRUE;
}

int insertInOrderNoDuplicates(List * list, Student * student){
    Node * newNode = malloc(sizeof(Node));
    if(!newNode)
        return FALSE;

    newNode->data=*student;
    newNode->next=NULL;

    if(isEmpty(list)){
        list->head=newNode;
        return TRUE;
    }

    if(student->id < list->head->data.id){
        newNode->next=list->head;
        list->head=newNode;
        return TRUE;
    }else if(student->id == list->head->data.id){
            free(newNode);
            return FALSE;
    }

    Node * current = list->head;
    while(current->next && student->id > current->next->data.id){
        current=current->next;
    }

    if (current->next && student->id == current->next->data.id) {
        free(newNode);
        return FALSE;
    }

    newNode->next=current->next;
    current->next=newNode;

    return TRUE;
}

void createList(List * list){
    list->head=NULL;
}

int isEmpty(List * list){
    return list->head==NULL;
}

int isFull(List * list){
    Node * node = malloc(sizeof(Node));
    if(node){
        free(node);
        return 0;
    }
    return 1;
}

void showAndEmptyList(List * list){
    while(list&&list->head){
        printf("%d %s",list->head->data.id,list->head->data.name);
        Node * aux = list->head;
        list->head=list->head->next;
        free(aux);
    }
}
