/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:57:50 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/16 17:23:58 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**split_words(const char *s, char c, char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && ft_is_delim(s[i], c))
		i++;
	if (!s[i])
	{
		arr[j] = NULL;
		return (arr);
	}
	arr[j] = ft_word_dup(s + i, c);
	if (!arr[j])
		return (NULL);
	return (split_words(s + i, c, arr + 1));
}

static char	**ft_split_into_words(const char *s, char c, char **arr)
{
	while (*s && ft_is_delim(*s, c))
		s++;
	if (!*s)
	{
		arr[0] = NULL;
		return (arr);
	}
	return (split_words(s, c, arr));
}

char	**ft_split(const char *s, char c)
{
	char **arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(*arr) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	return (ft_split_into_words(s, c, arr));
}
/*
#include <stdio.h>

int main(void)
{
    char **result;
    int i;

    printf("Test with empty string:\n");
    result = ft_split("", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with delimiters at the beginning and end:\n");
    result = ft_split(",alpha,beta,", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with consecutive delimiters:\n");
    result = ft_split("apple,,orange", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with no delimiters:\n");
    result = ft_split("fruitbasket", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with NULL string:\n");
    result = ft_split(NULL, ',');
    if (result)
    {
        i = 0;
        while (result[i])
        {
            printf("'%s'\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
    {
        printf("NULL\n");
    }

    return (0);
}
*/
