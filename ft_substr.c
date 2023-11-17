/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:21:15 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/15 12:28:50 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
// #include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int	start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len; //length of input string

	if (!s)
		return (NULL);
	s_len = ft_strlen(s); //calculates length of the input string s
	if (start >= s_len)
		return (ft_strdup("")); //if yes,s tarting index beyond bounds of the input string s, so empty string
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL); //check if mem alloc success
	i = 0;
	while (i < len)  //copy substring from (s) to the newly allocated memory (substr).
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>
int main() {
    char *result;
    char test_str[] = "Example string for testing";

    result = ft_substr(test_str, 8, 6);
    printf("Test 1 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(test_str, 30, 5);
    printf("Test 2 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(test_str, 10, 0);
    printf("Test 3 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(test_str, 15, 50);
    printf("Test 4 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(NULL, 5, 5);
    printf("Test 5 - Substring: '%s'\n", result);

    return (0);
}
*/
