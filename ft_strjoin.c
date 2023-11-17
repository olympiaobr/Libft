/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:43:11 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/15 13:04:18 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);

	r = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, l1 + 1);
	ft_strlcpy(r + l1, s2, l2 + 1);
	return (r);
}

#include <stdio.h>
int main() {
    char const *s1 = "Hello, ";
    char const *s2 = "world!";
    char *result;

    result = ft_strjoin(s1, s2);
    if (result != NULL) 
    {
        printf("Test 1: %s\n", result);
        free(result); 
    } else 
    {
        printf("Test 1: Memory allocation failed\n");
    }

    s1 = "";
    result = ft_strjoin(s1, s2);
    if (result != NULL) 
    {
        printf("Test 2: %s\n", result);
        free(result);
    } else 
    {
        printf("Test 2: Memory allocation failed\n");
    }

    result = ft_strjoin(NULL, s2);
    if (result == NULL) 
    {
        printf("Test 3: Passed (NULL input)\n");
    } else 
    {
        printf("Test 3: Failed (should not concatenate NULL)\n");
        free(result);
    }

    return (0);
}
