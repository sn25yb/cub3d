/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:34:09 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIB_H
# define LIB_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libgnl/get_next_line.h"

void	free_array(char **arr);
char	**arrcpy(char **arr);
char	*ft_strchrset(char *str, char *set);
int		read_next_line(const char *file, char **line, int *fd);

#endif
