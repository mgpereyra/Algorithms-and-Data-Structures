#include "LinkedList.h"

int main()
{
    List list;
    Student student;

    createList(&list);

    while(createStudent(&student)){
        insertInOrderNoDuplicates(&list,&student);
    }

    showAndEmptyList(&list);

    return 0;
}
