#include "libft.h"

void	ft_lsadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;

	new->next = *lst;
	*lst = new;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list *head;
    t_list *node;
    int i;

    head = NULL; // Initialize the head of the list to NULL
    i = 0;
    while (i < 3) // Adding 3 nodes to the list
    {
        node = (t_list *)malloc(sizeof(t_list)); // Dynamically allocate a new node
        if (node == NULL) // Check for successful allocation
        {
            // Handle allocation failure if needed
            return (1); // Return an error code
        }
        node->content = (void *)(size_t)i; // Assign content to the node
        ft_lsadd_front(&head, node); // Add the node to the front of the list
        i++;
    }

    // Printing the list to check if nodes are added correctly
    node = head; // Start from the head of the list
    while (node != NULL)
    {
        printf("Node content: %zu\n", (size_t)node->content);
        node = node->next; // Move to the next node
    }

    // Code to free the list might go here

    return (0);
}
