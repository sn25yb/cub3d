/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:23:02 by sohykim           #+#    #+#             */
/*   Updated: 2023/11/21 18:21:36 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	make_lines(t_file *file, int fd)
{
	ssize_t	byte_to_read;

	byte_to_read = read(fd, file->buffer, BUFFER_SIZE);
	if (byte_to_read >= 0)
	{
		while (byte_to_read > 0)
		{
			file->buffer[byte_to_read] = 0;
			if (file->strs == NULL)
				file->strs = ft_substr(file->buffer, 0, byte_to_read);
			else
			{
				file->temp = ft_strjoin(file->strs, file->buffer);
				free(file->strs);
				file->strs = file->temp;
			}
			if (file->strs == NULL)
				return (0);
			if (ft_strchr(file->buffer, 10))
				return (1);
			byte_to_read = read(fd, file->buffer, BUFFER_SIZE);
		}
		return (1);
	}
	return (0);
}

static t_file	*find_file(struct s_head *h, int fd)
{
	t_file	*node;
	t_file	*prev;

	node = h->head;
	prev = NULL;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		prev = node;
		node = node->next;
	}
	node = malloc(sizeof(t_file));
	if (node == NULL)
		return (0);
	node->temp = 0;
	node->strs = 0;
	node->next = 0;
	node->fd = fd;
	if (prev)
		prev->next = node;
	else
		h->head = node;
	return (node);
}

static void	delete_all(struct s_head *file, int fd)
{
	t_file	*node;
	t_file	*prev;

	node = file->head;
	prev = NULL;
	while (node)
	{
		if (node->fd == fd)
		{
			free(node->strs);
			node->strs = NULL;
			node->temp = NULL;
			if (prev)
				prev->next = node->next;
			else
				file->head = node->next;
			free(node);
			break ;
		}
		prev = node;
		node = node->next;
	}
}

static int	make_result(struct s_head *file, t_file	*now, char	**res)
{
	char	*result;
	char	*temp;
	size_t	len;

	if (now->strs == NULL || now->strs[0] == 0)
		return (0);
	temp = ft_strchr(now->strs, 10);
	if (temp == NULL)
	{
		result = ft_substr(now->strs, 0, ft_strlen(now->strs) + 1);
		delete_all(file, now->fd);
	}
	else
	{
		len = temp - now->strs + 1;
		result = ft_substr(now->strs, 0, len);
		ft_strlcpy(now->strs, temp + 1, ft_strlen(now->strs) + 1);
		now->temp = now->strs;
	}
	if (result)
	{
		*res = result;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static struct s_head	*file;
	t_file					*new;
	char					*result;

	if (file == NULL)
	{
		file = malloc(sizeof(struct s_head));
		if (file == NULL)
			return (0);
		file->head = NULL;
	}
	new = find_file(file, fd);
	result = NULL;
	if (new == NULL || !make_lines(new, fd) || !make_result(file, new, &result))
	{
		delete_all(file, fd);
		if (file->head == NULL)
		{
			free(file);
			file = NULL;
		}
	}
	return (result);
}
