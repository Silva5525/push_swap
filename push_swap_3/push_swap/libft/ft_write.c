/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:59:10 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/10 11:49:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Safe version of the write function with error if write fails
/// @param fd File Descriptor
/// @param buf Buffer for the String to write
/// @param count how many bytes to write
/// @return the number of bytes written
ssize_t	ft_write(int fd, const void *buf, size_t count)
{
	ssize_t	bytes_written;

	bytes_written = write(fd, buf, count);
	if (bytes_written == -1)
	{
		perror("write failed");
		exit(EXIT_FAILURE);
	}
	return (bytes_written);
}