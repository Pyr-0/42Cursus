/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:13:22 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/03 14:53:40 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void * dst, const void * src, size_t n);
/*void	ft_memccpy
void	ft_memmove
void	ft_memchr
void	ft_memcmp*/

size_t	ft_strlen (const char *str);
/*char	ft_strlcpy
char	ft_strlcat
char	ft_strchr
char	ft_strrchr
char	ft_strnstr
char	ft_strncmp*/

int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
