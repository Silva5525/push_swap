/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:13:01 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/20 19:20:37 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief counts the leng of s
/// @param s str to count
/// @return leng of count
size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s && s[c] != 0)
		c++;
	return (c);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "abcdefergg";
// 	int	out = ft_strlen(str);
// 	printf("%i", out);
// 	return (0);
// }
