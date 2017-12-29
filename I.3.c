#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* next;};

struct node *first_l1, *first_l2, *last, *current;

void DisplayList();
void concatenate(struct node* a, struct node* b);


int main()
{
    int NbOfElements;
    int i;
    printf("Number of elements in the first list: ");
    scanf("%d", &NbOfElements);
    printf("\n");

    first_l1 = NULL;
    for(i = 0; i < NbOfElements; ++i)
    {
        current = (struct node*)malloc(sizeof(struct node));

        printf("Input node number %i: ", i);
        scanf("%i", &current->info);
        current->next = NULL;

        if(first_l1 == NULL)
        {
            first_l1 = current;
            last = current;
        }
        else{
            last->next = current;
            last = current;
        }
    }

    printf("\n\nNumber of elements in the second list: ");
    scanf("%d", &NbOfElements);
    printf("\n");

    first_l2 = NULL;
    for(i = 0; i < NbOfElements; ++i)
    {
        current = (struct node*)malloc(sizeof(struct node));

        printf("Input node number %i: ", i);
        scanf("%i", &current->info);
        current->next = NULL;

        if(first_l2 == NULL)
        {
            first_l2 = current;
            last = current;
        }
        else{
            last->next = current;
            last = current;
        }
    }

    concatenate(first_l1, first_l2);
    DisplayList();

    return 0;
}

void DisplayList()
{
    printf("\nDisplaying the list: \n");
    current = first_l1;
    while(current->next != NULL)
    {
        printf("%i  ", current->info);
        current = current -> next;
    }

    printf("%i", last->info);
}

void concatenate(struct node* first1, struct node* first2)
{
    if(first1 != NULL && first2!= NULL)
    {
        if(first1->next == NULL)
            first1->next = first2;
        else
            concatenate(first1->next, first2);
    }
    else
    {
        printf("One of the lists is NULL!\n");
    }
}
