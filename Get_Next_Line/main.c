/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:51:06 by wdegraf           #+#    #+#             */
/*   Updated: 2023/12/19 14:52:29 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		file;
	char	*line;

	file = open("test.txt", O_RDONLY);
	if (file == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(file);
	while (line)
	{
		printf("$$ %s\n", line);
		line = get_next_line(file);
	}
	close(file);
	return (0);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include "get_next_line.h"

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	// Open a file descriptor for standard input
// 	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
// 	write(fd, "0123456789012345678901234567890123456789x2\n", 42);
// 	close(fd);

// 	// Redirect standard input to the file descriptor
// 	fd = open("test.txt", O_RDONLY);
// 	close(0); // Close standard input
// 	dup(fd);   // Duplicate the file descriptor to standard input
// 	close(fd); // Close the duplicated file descriptor

// 	// Call get_next_line to read from standard input
// 	line = get_next_line(0);

// 	// Print the result
// 	if (line)
// 	{
// 		printf("Result: %s\n", line);
// 		free(line);
// 	}
// 	else
// 	{
// 		printf("Error reading from standard input\n");
// 	}

// 	// Close standard input
// 	close(0);

// 	return 0;
// }