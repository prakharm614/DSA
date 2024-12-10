#include <stdio.h>
#include <stdlib.h>
typedef struct list {
    int info;
    struct list *next;
} node;
void insertfirst(node **start, int x)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = x;
    ptr->next = *start;
    *start = ptr;
}
void traverse(node *start)
{
    node *temp;
    temp = start;
    if (start == NULL) {
        printf("List is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

int main()
{
    node *start = NULL;
    int x;
printf("Enter the element: ");
    scanf("%d", &x);
insertfirst(&start, x);
traverse(start);

    return 0;
}