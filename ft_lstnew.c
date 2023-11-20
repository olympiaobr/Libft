/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:25:36 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/20 17:28:40 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_n;

	new_n = (t_list *)malloc(sizeof(t_list));
	if (!new_n)
		return (NULL);
	new_n->content = content;
	new_n-> NULL;
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
