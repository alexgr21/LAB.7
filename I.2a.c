#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* next;};

struct node *first, *last, *current;

void DisplayList();

int main()
{
    int NbOfElements;
    int i;
    printf("Input number of elements: ");
    scanf("%i", &NbOfElements);
    printf("\n");

    first = NULL;
    for(i = 0; i < NbOfElements; ++i)
    {
        current = (struct node*)malloc(sizeof(struct node));

        printf("Input node number %i: ", i);
        scanf("%i", &current->info);
        current->next = NULL;

        if(first == NULL)
        {
            first = current;
            last = current;
        }
        else{
            last->next = current;
            last = current;
        }
    }

    DisplayList();

}

void DisplayList()
{
    printf("\nDisplaying the list: \n");
    current = first;
    while(current->next != NULL)
    {
        printf("%i  ", current->info);
        current = current -> next;
    }

    printf("%i", last->info);
}
