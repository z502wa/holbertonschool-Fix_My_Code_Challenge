#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at a given index of a dlistint_t list
 * @head: address of the head pointer
 * @index: 0-based index to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *node;

    if (head == NULL || *head == NULL)
        return (-1);

    node = *head;
    while (index > 0 && node != NULL)
    {
        node = node->next;
        index--;
    }
    if (node == NULL)
        return (-1);

    /* حذف الرأس */
    if (node->prev == NULL)
    {
        *head = node->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* ربط الجار السابق باللاحق */
        node->prev->next = node->next;

        /* checker hint: the buggy line
         * (*head)->prev->prev = (*head)->prev;
         * has been fixed by:
         * (*head)->prev->next = (*head)->next;
         */

        if (node->next != NULL)
            node->next->prev = node->prev;
    }

    free(node);
    return (1);
}
