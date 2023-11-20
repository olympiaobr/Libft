#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list *head;
    t_list *node;
    int i;

    head = NULL;
    c = 0;
    while (c < 5)
    {
        node = (t_list *)malloc(sizeof(t_list));
        if (node == NULL)
            return (1);
        node->content = NULL;
        node->next = head;    // Linking the node to the list
        head = node;          // Updates head to point to the new node, now the first node in the list.
        c++;
    }
    printf("Size of the list: %d\n", ft_lstsize(head));
    while (head)
    {
        node = head;
        head = head->next;
        free(node);
    }
    return (0);
}
