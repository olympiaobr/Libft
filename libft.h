/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:16:25 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/15 13:22:50 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>

int	ft_isalpha(int c);
int	ft_isalnum(int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

size_t	ft_strlen(const char *s);
size_t	ft_bzero(void *b, size_t len);
size_t	ft_strlcpy(char *destination, const char *source, size_t size);
size_t	ft_strlcat(char *dst, char *src, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memcpy
void	*ft_memmove
	

char	*ft_substr(char const *s, unsigned int start, size_t len)
char	*ft_strjoin(char const *s1, char const *s2)
char	*ft_strtrim(char const *s1, char const *set)
char	**ft_split(char const *s1, char const *set)
char	**ft_itoa(int n)
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char ))
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
void	ft_putchar_fd(char c, int fd)
void	ft_putstr_fd(char *s, int fd)
void	ft_putendl_fd(char *s, int fd)


#endif
