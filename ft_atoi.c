/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:02:03 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/14 16:12:35 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long	r;
	long	prev_r;

	i = 0;
	sign = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		prev_r = r;
		r = r * 10 + (str[i] - '0');
		if (sign == 1 && prev_r > r)
			return (0);
		if (sign == -1 && - prev_r < -r)
			return (-1);
		i++;
	}
	return ((int)(r * sign));
}
/*
#include <stdio.h>
int main()
{
    char *str1 = "  ---+--+1234ab567";
    char *str2 = "456";
    char *str3 = "   +789";
    char *str4 = "   -0";
    char *str5 = "   00123";

    printf("String: %s, Integer: %d\n", str1, ft_atoi(str1));
    printf("String: %s, Integer: %d\n", str2, ft_atoi(str2));
    printf("String: %s, Integer: %d\n", str3, ft_atoi(str3));
    printf("String: %s, Integer: %d\n", str4, ft_atoi(str4));
    printf("String: %s, Integer: %d\n", str5, ft_atoi(str5));

    return (0);
}
*/
