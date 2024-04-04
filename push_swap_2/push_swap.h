/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:06:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/04 11:56:15 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_link
{
	int				num;
	struct s_link	*next;
	struct s_link	*actual;
	struct s_link	*prev;
}					t_link;

void error1(char **argv, int err_num);

#endif