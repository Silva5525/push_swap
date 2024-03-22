/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:05 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/12 17:20:11 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/// @brief Allocates (with malloc(3)) and returns a new
/// string, which is the result of the concatenation
/// of ’s1’ and ’s2’.
/// @param s1 The prefix (anfangs) string.
/// @param s2 The suffix (end) string.
/// @param len2 The leng of s2.
/// @return The new allocated str or Null if fails.
char	*ft_strjoin2(t_struct *file, char const *s2, ssize_t len2)
{
	char		*s3;
	ssize_t		len1;
	ssize_t		j;
	ssize_t		i;
	char		*hold;

	hold = file->content;
	len1 = file->ret - len2;
	s3 = (char *)malloc(len1 + len2 + 1);
	if (s3 == NULL)
		return (NULL);
	i = -1;
	while (len1 > ++i)
		s3[i] = hold[i];
	j = -1;
	while (len2 > ++j)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

/// @brief The  strdup() function returns a pointer to a new string which is a 
/// du plicate of the string s.  Memory for the new string  is  obtained  with
/// malloc(3), and can be freed with free(3).
/// @param s1 string to duplicate.
/// @param l leng of s1.
/// @return a pointer to duplicated string. Null if memory was insufficient. 
char	*ft_strdup2(const char *s1, size_t l)
{
	char	*a;
	size_t	i;

	i = 0;
	l = ft_strlen(s1);
	if (!s1)
		return (NULL);
	a = (char *)malloc(l + 1);
	if (!a)
		return (NULL);
	while (l > i)
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
