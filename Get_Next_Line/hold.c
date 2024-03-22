// #include "get_next_line.h"

// char	*save_rest(char *buffer, int i)
// {
// 	int		j;
// 	char	*rest;

// 	rest = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (rest == NULL)
// 		return (NULL);
// 	j = 0;
// 	while (buffer[i] != '\0')
// 	{
// 		rest[j] = buffer[i];
// 		i++;
// 		j++;
// 	}
// 	rest[j] = '\0';
// 	return (rest);
// }

// char	*ft_read(int fd, char *out, char *rest)
// {
// 	char		buffer[BUFFER_SIZE + 1];
// 	int			count;
// 	int			i;
// 	int			j;

// 	j = 0;
// 	if (rest)
// 	{
// 		while (rest[j] != '\0')
// 		{
// 			if (rest[j] == '\n')
// 			{
// 				out = ft_strjoin(out, rest, j);
// 				rest = save_rest(rest, j);
// 				return (out);
// 			}
// 			j++;
// 		}
// 		out = ft_strjoin(out, rest, j);
// 	}
// 	count = read(fd, 0, 0);
// 	while (count >= 0)
// 	{
// 		i = 0;
// 		j = read(fd, buffer, BUFFER_SIZE);
// 		if (j <= 0)
// 			return (NULL);
// 		count = j;
// 		buffer[j] = '\0';
// 		while (j > i && buffer[i] != '\n' && buffer[i] != '\0')
// 			i++;
// 		i++;
// 		out = ft_strjoin (out, buffer, i);
// 		if (buffer[i - 1] == '\n')
// 		{
// 			rest = save_rest(buffer, i);
// 			break ;
// 		}
// 		if (buffer[j] == '\0')
// 			break ;
// 	}
// 	return (out);
// }

// char	*get_next_line(int fd)
// {
// 	char			*out;
// 	static char		*rest;

// 	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	out = ft_read(fd, NULL, rest);
// 	if (!out || out[0] == '\0')
// 	{
// 		free(out);
// 		free(rest);
// 		return (NULL);
// 	}
// 	return (out);
// }

