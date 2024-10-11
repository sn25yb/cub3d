/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:07:13 by sohykim           #+#    #+#             */
/*   Updated: 2023/11/21 18:21:47 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_file
{
	int				fd;
	char			*strs;
	char			*temp;
	char			buffer[BUFFER_SIZE + 1];
	struct s_file	*next;
}	t_file;

struct	s_head
{
	t_file	*head;
};

char	*get_next_line(int fd);
#endif
