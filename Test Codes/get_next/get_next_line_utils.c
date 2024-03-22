/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:03:09 by wdegraf           #+#    #+#             */
/*   Updated: 2023/12/19 14:14:28 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Allocates (with malloc(3)) and returns a new
/// string, which is the result of the concatenation
/// of ’s1’ and ’s2’
/// @param s1 The prefix (anfangs) string
/// @param s2 The suffix (end) string
/// @return The new allocated str or Null if fails
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	ssize_t	len1;
	ssize_t	len2;
	ssize_t	j;
	ssize_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
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

/// @brief The  strdup() function returns a pointer to a new string which is a 
/// du plicate of the string s.  Memory for the new string  is  obtained  with
/// malloc(3), and can be freed with free(3).
/// @param s1 string to duplicate
/// @return a pointer to duplicated string. Null if memory was insufficient. 
char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(s1);
	a = (char *)malloc(l + 1);
	if (a == NULL)
		return (NULL);
	while (l != 0)
	{
		a[i] = s1[i];
		i++;
		l--;
	}
	a[i] = '\0';
	return (a);
}

/// @brief The  strchr() function returns a pointer to the first occurrence of 
/// the character c in the string s.
/// @param s Through searched string
/// @param c char which is searched
/// @return pointer to the first occurrence of c 
char	*ft_strchr(const char *s, int c)
{
	while (s != NULL && *s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
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
