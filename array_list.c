#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node{
int data;
int last;
}node;
const lenth = sizeof(node);

node* init()
{
    node* start = malloc(sizeof(node)*MAX);
    start->data=0;
    start->last=-1;

    return start;
}
int insert(node* start, int n, int data)
{
    if (n >= MAX)
    {
        printf("overflow\n");
        return -1;
    }
    if (n < 0 || n > start->last+1)
    {
        printf("wrong position\n");
        return -2;
    }
    if (start->last+1 == n)
    {
        (start+lenth*n)->data=data;
        start->last++;
    }
    else 
    {
        int i;
        for (i=start->last; i>=n; i--)
        {
            (start+lenth*(i+1))->data = (start+lenth*i)->data;
        }
        (start+lenth*n)->data = data;
        start->last++;
    }
    return 0;
}

int add(node* start, int data)
{
   insert(start, start->last+1, data); 
   return 0;
}
int delete(node* start, int n)
{
    int i;
    if (n > start->last)
    {
        printf("no such node\n");
        return -1;
    }    
    if (n == start->last)
    {
        (start+lenth*n)->data = 0;
        start->last--;
        return 0;
    }
    for (i=n; i<start->last; i++)
    {
        (start+lenth*i)->data = (start+lenth*(i+1))->data;
    }
    start->last--;
    return 0;
}
int search(node* start, int n)
{
    if (n > start->last+1)
    {
        printf("no such node\n");
        return -1;
    }    
    printf("%d\n",(start+lenth*n)->data);
    return 0; 
}
void traversal(node* start)
{
    int i;
    for (i=0; i<=start->last; i++)
    {
        printf("%d\n", (start+(lenth*i))->data);
    }
}
void menu(node* start)
{
    int choice;
    int n;
    int data;
    printf("last: %d\n", start->last);
    printf("choose:=\n");
    printf("1.insert\n");
    printf("2.search\n");
    printf("3.delete\n");
    printf("4.traversal\n");
    printf("5.add\n");
    printf("\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            scanf("%d",&n);
            scanf("%d",&data);
            printf("\n");
            insert(start, n, data);
            break;
        case 2:
            scanf("%d",&n);
            search(start, n);
            printf("\n");
            break;
        case 3:
            scanf("%d",&n);
            printf("\n");
            delete(start, n);
            break;
        case 4:
            traversal(start);
            break;
        case 5:
            scanf("%d",&n);
            printf("\n");
            add(start, n);
            break;
        default:
            break;
    }
}
int main(void)
{
    node* start = init();
    int i;
    add(start, 0);
    add(start, 1);
    add(start, 2);
    add(start, 3);
    add(start, 4);
    while(1)
    {
        menu(start);
    }

    for (i=0; i<41; i++)
    {
        printf("%d\n",(start+i*lenth)->data);
        printf("%d\n",start->last);
    }

    return 0;
}
