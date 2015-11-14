#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int datatype;
typedef struct Queue
{
    datatype data;
    int front;
    int rear;
}queue;

const int length = sizeof(queue);

queue* create(void)
{
    queue* queue = malloc(sizeof(queue)*MAX);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}
int isEmpty(queue* queue)
{
    if (queue->front == queue->rear)
        return 1;
    return 0;
}
int isFull(queue* queue)
{
    if (queue->front == (queue->rear+1)%MAX)
        return 1;
    return 0;
}
int in(queue* queue, datatype data)
{
    if(isFull(queue))
    {
        printf("full\n");
        return -1;
    }
    (queue+length*(queue->rear))->data = data;
    queue->rear = (queue->rear+1)%MAX;
}
int out(queue* queue) 
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return -1;
    }
    printf("%d\n", (queue+length*(queue->front))->data);
    queue->front = (queue->front+1)%MAX;
}
int traversal(queue* queue)
{
    int i;
    if(isEmpty(queue))
    {
        printf("empty\n");
        return -1;
    }
    for(i = queue->front; i != queue->rear; i = (i+1)%MAX)
    {
        printf("%d\n", (queue+(length*i))->data);
    }
    return 0;
}
int menu(queue* queue)
{
    printf("choose:\n");
    printf("1.in\n");
    printf("2.out\n");
    printf("3.traversal\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        int data;
        
        case 1:
            scanf("%d", &data);
            in(queue, data);
            break;
        case 2:
            out(queue);
            break;
        case 3:
            traversal(queue);
            char a = getchar();
            printf("%x got", a);
            fflush(stdin);
            while(getchar() != '\n');
            break;
    }

}
int main(int argc, char* argv[])
{
    queue* queue = create();

    while(1)
    {
        menu(queue);
    }

    return 0;
}
