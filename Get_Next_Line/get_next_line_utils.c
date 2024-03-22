/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:05 by wdegraf           #+#    #+#             */
/*   Updated: 2023/12/19 16:03:19 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2, ssize_t len2)
{
	char	*s3;
	ssize_t	len1;
	ssize_t	j;
	ssize_t	i;

	s3 = NULL;
	len1 = ft_strlen(s1);
	s3 = (char *)malloc(len1 + len2 + 1);
	if (s3 == NULL)
		return (NULL);
	i = -1;
	while (len1 > ++i)
		s3[i] = s1[i];
	j = -1;
	while (len2 > ++j)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

/// @brief counts the leng of s
/// @param s str to count
/// @return leng of count
size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s && s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strdup(const char *s1, int i, int l)
{
	char	*a;
	size_t	j;

	j = 0;
	if (l == 0)
		l = ft_strlen(s1);
	a = (char *)malloc(l + 1);
	if (a == NULL)
		return (NULL);
	while (l != 0)
	{
		a[j] = s1[i];
		i++;
		j++;
		l--;
	}
	a[j] = '\0';
	return (a);
}

/// @brief The  memcpy()  function  copies  n bytes from memory area src to
/// memory area dest.  The memory areas must not overlap.  Use memmove(3)  
/// if  the memory areas do overlap.
/// @param dst destination for new string
/// @param src string which to copy
/// @param len how long to copy
/// @return a pointer to dest
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;

	if (dst == 0 && src == 0)
		return (NULL);
	dst2 = (unsigned char *) dst;
	src2 = (const unsigned char *) src;
	while (len > 0)
	{
		*dst2 = *src2;
		src2++;
		dst2++;
		len--;
	}
	return (dst);
}
