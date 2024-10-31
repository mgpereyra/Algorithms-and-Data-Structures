#include "Queue.h"

int main()
{
    t_student student1;
    student1.id = 1;
    strcpy(student1.name, "Maximiliano");

    t_student student2;
    student2.id = 2;
    strcpy(student2.name, "Gaston");

    t_student student3;
    student3.id = 3;
    strcpy(student3.name, "Tomas");

    t_queue queue;
    createQueue(&queue);

    addToQueue(&queue, &student1);
    addToQueue(&queue, &student2);
    addToQueue(&queue, &student3);

    t_student student;

    while(!queueIsEmpty(&queue)){
        if(unQueue(&queue,&student))
            showStudent(&student);
    }

    printf("Queue is %s", queueIsEmpty(&queue)?"empty...":"not empty!");

    return 0;
}
