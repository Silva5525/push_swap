/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:02:53 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/22 14:20:44 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int			ft_printf(const char *format, ...);
int			v_di(va_list *args);
int			v_x(va_list *args, const char *base_char, ssize_t *wr_i);
int			v_x(va_list *args, const char *base_char, ssize_t *wr_i);
int			v_p(va_list *args, const char *base_char, ssize_t *wr_i);
int			v_u(va_list *args, ssize_t *wr_i);
int			v_remix(char format, va_list *args, ssize_t *wr_i);

#endif
