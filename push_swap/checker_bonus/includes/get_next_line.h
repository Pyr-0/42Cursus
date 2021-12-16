/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:07:26 by eozben            #+#    #+#             */
/*   Updated: 2021/10/05 20:12:34 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define BUFFER_SIZE 15

char	*get_next_line(int fd);
char	*get_last_line(char **save, char *buf);

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);

char	*ft_keepreading(int *var, char *buf, char **save);
char	*ft_puttogether(int *var, char *buf, char **save);
char	*ft_storeandcut(char **buf, char **save);

char	*ft_exit(char **save, char *buf, char *tmp);

#endif