/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:07 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/20 18:22:12 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

int main()
{
    // Creating a test node
    t_list *node = malloc(sizeof(t_list));
    if (!node) {
        perror("Allocation failure");
        return 1;
    }

    // Assigning content to the node
    node->content = strdup("Hello, World!");
    node->next = NULL;

    // Use ft_lstdelone to delete the node, passing 'free' as the function pointer
    ft_lstdelone(node, free);

    return (0);
}
