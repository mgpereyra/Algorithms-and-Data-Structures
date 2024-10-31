#include "Stack.h"
int main()
{
    Stack myStack;
    createStack(&myStack);

    Student student1 = {"Mark",3344};
    Student student2 = {"Rick",321};
    Student student3 = {"Walter",123456};
    push(&myStack,&student1);
    push(&myStack,&student2);
    push(&myStack,&student3);

    // emptyStack(&myStack);

    /* Student student;
    if(peek(&myStack,&student)){
        printf("Name: %s, ID: %d\n",student.name,student.id);
    }if(peek(&myStack,&student)){
        printf("Name: %s, ID: %d\n",student.name,student.id);
    } */

    // printf("Stack is %s\n",stackIsEmpty(&myStack)?"empty":"not empty");

    showAndPopStack(&myStack);

    return 0;
}
