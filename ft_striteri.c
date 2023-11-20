/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:33:10 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/17 12:36:36 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

void my_uppercase(unsigned int i, char *c)
{
    if (*c >= 'a' && *c <= 'z')
    {
        *c -= 32; // Convert to uppercase
    }
}

#include <stdio.h>

int main(void)
{
    char str[] = "hello world";

    printf("Before: %s\n", str);

    // Applying ft_striteri
    ft_striteri(str, my_uppercase);

    printf("After: %s\n", str);

    return (0);
}

