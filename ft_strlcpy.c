/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:51:28 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/13 12:56:50 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *destination, const char *source, size_t size)
{
	size_t	i;

	if (!destination || !source)
		return (0);
	i = 0;
	while (source[i] != '\0' && i < size - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (size > 0)
		destination[i] = '\0';
	while (source[i])
		i++;
	return (i);
}
/*
#include <stddef.h>
#include <stdio.h>
#include <stddef.h>

int main() 
{
    char source[] = "Badumts";
    char destination[50];

    size_t copied = ft_strlcpy(destination, source, sizeof(destination));

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("Number of characters copied: %zu\n", copied);

    return (0);
}
*/
