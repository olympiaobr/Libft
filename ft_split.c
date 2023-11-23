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

static int  ft_is_delim(char c, char delim)
{
    return (c == delim);
}

static int  ft_word_count(const char *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (ft_is_delim(s[i], c) && s[i])
            i++;
        if (!ft_is_delim(s[i], c) && s[i])
            count++;
        while (!ft_is_delim(s[i], c) && s[i])
            i++;
    }
    return (count);
}

static char *ft_word_dup(const char *s, int start, int end)
{
    char    *word;
    int     i;

    word = (char *)malloc(sizeof(*word) * (end - start + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

static char	**fill_split_array(const char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_is_delim(s[i], c))
		{
			start = i;
			while (s[i] && !ft_is_delim(s[i], c))
				i++;
			arr[j] = ft_word_dup(s, start, i);
			if (!arr[j])
				return (NULL);
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char **ft_split(const char *s, char c)
{
	char **arr;

	arr = (char **)malloc(sizeof(*arr) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!fill_split_array(s, c, arr))
	{
		while (*arr)
			free(*arr++);
		free(arr);
		return (NULL);
	}
	return (arr);
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
