#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new n;

	new_n = (t_list *)malloc(sizeof(t_list));
	if (!new_n)
		return (NULL);

	new_n->content = content;
	new_n->next = NULL;
	return (new_n);
}

#include <stdio.h>

int main(void)
{
    t_list *node;

    // Test with a sample content value
    int sample_content = 123;
    node = ft_lstnew((void *)&sample_content);

    // Check if the node was created successfully
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print the content of the node
    printf("Node content: %d\n", *(int *)node->content);

    // Free the allocated memory for the node
    free(node);

    return 0;
}
