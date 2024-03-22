/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:17:46 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/13 17:13:01 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

typedef struct s_struct
{
	int				fd;
	char			*content;
	int				swich;
	int				ret;
	int				leng;
}					t_struct;

char	*get_next_line(int fd);
char	*ft_strjoin2(t_struct *file, char const *s2, ssize_t len2);
char	*ft_strdup2(const char *s1, size_t l);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *str);

#endif

/// @brief s_struct is a struct that holds the content of the file
/// and the file descriptor. The struct is used to handle multiple
/// files at the same time.
/// @param fd the file descriptor.
/// @param content the content of the file.
/// @param swich a swich to indicate if the file is empty or not.
/// @param ret the number of bytes read from the file.