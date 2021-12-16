/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:07:19 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 00:01:01 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_last_line(char **save, char *buf)
{
	char	*tmp;

	free(buf);
	buf = ft_strdup(*save);
	if (!buf)
		return (ft_exit(save, NULL, NULL));
	if (ft_strchr(buf, '\n'))
	{
		free(*save);
		tmp = ft_strchr(buf, '\n') + 1;
		if (tmp != (char *) 2)
			*save = ft_strdup(tmp);
		else
			*save = ft_strdup("");
		if (!*save)
			return (ft_exit(NULL, buf, NULL));
		if (tmp != (char *) 2)
			*(ft_strchr(buf, '\n') + 1) = '\0';
	}
	else
	{
		free(*save);
		*save = NULL;
	}
	return (buf);
}

char	*ft_storeandcut(char **buf, char **save)
{
	char	*tmp;

	free(*buf);
	*buf = ft_strdup(*save);
	if (!*buf)
		return (ft_exit(save, NULL, NULL));
	tmp = ft_strchr(*buf, '\n') + 1;
	free(*save);
	if (tmp != (char *) 2)
		*save = ft_strdup(tmp);
	else
		*save = ft_strdup("");
	if (!*save)
		return (ft_exit(NULL, *buf, NULL));
	if (tmp != (char *) 2)
		*(ft_strchr(*buf, '\n') + 1) = '\0';
	return ((char *) 1);
}

char	*ft_puttogether(int *var, char *buf, char **save)
{
	char	*tmp;

	buf[var[1]] = '\0';
	if (!*save)
		*save = ft_strdup("");
	if (!*save)
		return (ft_exit(NULL, buf, NULL));
	tmp = ft_strjoin(*save, buf);
	if (!tmp)
		return (ft_exit(save, buf, NULL));
	free(*save);
	*save = ft_strdup(tmp);
	if (!*save)
		return (ft_exit(NULL, buf, tmp));
	free (tmp);
	return ((char *) 1);
}

char	*ft_keepreading(int *var, char *buf, char **save)
{
	char	*err;

	while (var[1] > 0)
	{
		err = ft_puttogether(var, buf, save);
		if (!err)
			return (ft_exit(save, buf, NULL));
		if (ft_strchr(*save, '\n'))
		{
			err = ft_storeandcut(&buf, save);
			if (!err)
				return (ft_exit(save, buf, NULL));
			break ;
		}
		var[1] = read(var[0], buf, BUFFER_SIZE);
	}
	if (var[1] == 0 && *save && ft_strlen(*save) > 0)
		return (get_last_line(save, buf));
	else if (var[1] == 0 || var[1] == -1)
		return (ft_exit(save, buf, NULL));
	else
		return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			var[2];
	static char	*save;

	var[0] = fd;
	if (var[0] < 0 || var[0] > OPEN_MAX)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	var[1] = read(var[0], buf, BUFFER_SIZE);
	if (var[1] == -1)
		return (ft_exit(NULL, buf, NULL));
	return (ft_keepreading(var, buf, &save));
}
