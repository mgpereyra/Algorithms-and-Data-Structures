#include "DoubleLinkedList.h"

void createDoubleLinkedList(DoubleLinkedList * list){
    list->head=list->tail=NULL;
}

int createEmployee(Employee * employee){
    if(!employee)
        return FALSE;

    printf("Please, input an ID for the new employee (-1 to finish): ");
    int validInput = FALSE;
    while (!validInput) {
        if (scanf("%d", &employee->id) == 1) {
            validInput = TRUE;
        } else {
            printf("Invalid input. Please enter a valid integer ID.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
    if(employee->id==-1){
        return FALSE;
    }

    printf("Now input the full name: ");
    scanf(" ");
    if (fgets(employee->name, sizeof(employee->name), stdin) == NULL) {
        printf("Error reading name.\n");
        return FALSE;
    }

    return TRUE;
}

int insertAtTheBeginning(DoubleLinkedList * list, Data * data){ // Will behave like a stack
    if(!list||!data)
        return FALSE;

    Node * newNode = malloc(sizeof(Node));
    if(!newNode)
        return FALSE;

    newNode->next=newNode->previous=NULL;
    newNode->data=*data;

    // List is empty
    if(!list->head||!list->tail){
        list->head=list->tail=newNode;
        // newNode->next=newNode->previous=newNode; // If I wanted to make it circular, uncomment line
    }else{
        newNode->next=list->head;
        // newNode->previous=list->tail; // If I wanted to make it circular I should put this in the next line
        list->head->previous=newNode;
        list->head=newNode;
    }
    return TRUE;
}

int insertInOrderAsc(DoubleLinkedList * list, Data * data){
    if(!list || !data){
        return FALSE;
    }
    Node * newNode = malloc(sizeof(Node));
    if(!newNode){
        return FALSE;
    }
    newNode->data=*data;
    newNode->next=newNode->previous=NULL;

    if(!list->head||!list->tail){ // Empty list
        list->head=list->tail=newNode;
        return TRUE;
    }

    if(isDataAIsLessThanB(data,&list->head->data)){ // Insert at the head
        newNode->next=list->head;
        list->head->previous=newNode;
        list->head=newNode;
        return TRUE;
    }

    Node * current = list->head; // Traverse the list to find insertion point
    while(current->next&&isDataAIsLessThanB(&current->next->data,data)){
        current=current->next;
    }

    if(!current->next){ // Insert at the tail
        current->next=newNode;
        newNode->previous=current;
        list->tail=newNode;
    }else{
        newNode->next = current->next; // Insert between nodes
        newNode->previous=current;
        current->next->previous=newNode;
        current->next=newNode;
    }

    return TRUE;
}

void printEmployee(Employee * employee){
    if(!employee)
        return;
    printf("%d %s",employee->id,employee->name);
}

void printDoubleLinkedListEmployee(DoubleLinkedList * list){
    if(!list)
        return;
    Node * current = list->head;
    while(current){
        printEmployee(&current->data);
        current=current->next;
    }
    printf("-- The size of the list is %d employee(s) --\n\n",getLenghtOfDoubleLinkedList(list));
}

void deleteDuplicatesFromDoubleLinkedList(DoubleLinkedList * list){
    if(!list||!list->head||!list->tail){
        return;
    }

    Node * current = list->head;
    while(current){
        Node * aux = current->next;
        while(aux){
            if(dataIsEqual(&current->data,&aux->data)){
                Node * nextAux = aux->next;
                deleteNodeFromDoubleLinkedList(list,aux);
                aux=nextAux;
            }else{
                aux=aux->next;
            }
        }
        current=current->next;
    }
}

int dataIsEqual(Data * dataA, Data * dataB){
    return dataA->id==dataB->id;
}

void deleteNodeFromDoubleLinkedList(DoubleLinkedList * list, Node * node){
    if(!list||!node)
        return;
    if(node==list->head&&node==list->tail){
        list->head=list->tail=NULL;
    }else if(node==list->head){
        list->head=list->head->next;
        if(list->head)
            list->head->previous=NULL;
    }else if (node==list->tail){
        list->tail=list->tail->previous;
        if(list->tail)
            list->tail->next=NULL;
    }else{
        if(node->previous){
            node->previous->next=node->next;
        }
        if(node->next){
            node->next->previous=node->previous;
        }
    }

    free(node);
}

void sortDoubleLinkedList(DoubleLinkedList * list){
    if(!list||!list->head||!list->tail||list->head==list->tail) // If no list or less than two elements
        return;
    Node *newHead = list->head;
    while(newHead){
        Node *min = newHead;
        Node *current = newHead->next;
        while(current){ // Search for the minimum id in the list
            if(isDataAIsLessThanB(&current->data,&min->data)){
                    min=current;
            }
            current=current->next;
        }

        if(min!=newHead){
            Data temp = newHead->data;
            newHead->data = min->data;
            min->data = temp;
        }

        newHead = newHead->next;
    }
}

int isDataAIsLessThanB(Data * dataA, Data * dataB){
    return dataA->id < dataB->id;
}

int getLenghtOfDoubleLinkedList(DoubleLinkedList * list){
    int size = 0;
    if(list){
        Node * ptr = list->head;
        while(ptr){
            size++;
            ptr=ptr->next;
        }
    }
    return size;
}
