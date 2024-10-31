#include "DoubleLinkedList.h"

int main()
{
    DoubleLinkedList list;
    DoubleLinkedList sortedList;

    createDoubleLinkedList(&list);
    createDoubleLinkedList(&sortedList);

    Data employee;

    while(createEmployee(&employee)){
        insertAtTheBeginning(&list,&employee); // This will work like a stack
        insertInOrderAsc(&sortedList,&employee);
    }

    printf("\nList:\n");
    printDoubleLinkedListEmployee(&list);

    printf("\nSorted list (using insertion function):\n");
    printDoubleLinkedListEmployee(&sortedList);

    sortDoubleLinkedList(&list);
    printf("Sorted list:\n");
    printDoubleLinkedListEmployee(&list);

    printf("Sorted list with no duplicates:\n");
    deleteDuplicatesFromDoubleLinkedList(&list);
    printDoubleLinkedListEmployee(&list);
    return 0;
}
