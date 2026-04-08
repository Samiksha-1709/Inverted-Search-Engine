#include "main.h"
#include <string.h>

//function to print linked list of files
status print_list(List *head)
{
    if(head == NULL)
        return Empty;

    List *temp = head;
    while(temp)
    {
        printf("%s ", temp->FILE_NAME);
        temp = temp->next;
    }
    printf("\n"); // Formatting improvement

    return SUCCESS;
}

/* Insert files at last */
status Add_to_list(List **head, char *filename, FILE *ptr)
{
    List *node = malloc(sizeof(List));
    if(node == NULL)
        return FAILURE;

    strcpy(node->FILE_NAME, filename);
    node->ptr = ptr;
    node->next = NULL;

    if(*head == NULL)
    {
        *head = node;
        return SUCCESS;
    }

    List *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    return SUCCESS;
}
