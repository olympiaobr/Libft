/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:39 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/16 16:40:02 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_i;
	size_t	e_i;
	size_t	tr_len;

	if (!s1 || !set)
		return (NULL);
	s_i = 0;
	while (s1[s_i] && ft_strchr(set, s1[s_i]))
		s_i++;
	e_i = ft_strlen(s1);
	while (e_i > s_i && ft_strchr(set, s1[e_i -1]))
		e_i--;
	tr_len = e_i - s_i;
	return (ft_substr(s1, s_i, tr_len));
}

#include <stdio.h>

int main() 
{
    char *result;

    // Test Case 1
    result = ft_strtrim("  Lorem ipsum dolor sit amet  ", " ");
    printf("Test 1: \"%s\"\n", result);
    free(result);

    // Test Case 2
    result = ft_strtrim("!!!---example---!!!", "!-");
    printf("Test 2: \"%s\"\n", result);
    free(result);

    // Test Case 3
    result = ft_strtrim("foobarbaz", "fz");
    printf("Test 3: \"%s\"\n", result);
    free(result);

    // Test Case 4
    result = ft_strtrim("2023-11-15", "1234567890-");
    printf("Test 4: \"%s\"\n", result);
    free(result);

    // Test Case 5
    result = ft_strtrim("ft_strtrim_test", "ft_");
    printf("Test 5: \"%s\"\n", result);
    free(result);

    return 0;
}
