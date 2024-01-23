#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    // Handle deletion at the beginning (index 0)
    if (index == 0)
    {
        *head = (*head)->next;
        if (*head)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    // Traverse to the node before the one at the specified index
    for (i = 0; i < index - 1 && current != NULL; i++)
        current = current->next;

    // Check if index is out of bounds
    if (current == NULL || current->next == NULL)
        return (-1);

    // Update pointers to skip the current node
    current->next = current->next->next;
    if (current->next)
        current->next->prev = current;

    return (1);
}
