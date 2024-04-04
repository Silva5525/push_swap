/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:31:19 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/03 17:04:50 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief the error function that exits the program and puts
/// out the error message when free is not needet.
/// @param error_code the error number 
void	error(int error_code)
{
	if (error_code == 1)
		write(1, "Usage: ./so_long map/a_6.ber\n", 30);
	if (error_code == 2)
		write(1, "Error\nMap is not correct\n", 26);
	if (error_code == 3)
		write(1, "Error\nmlx_init failed\n", 23);
	if (error_code == 5)
		write(1, "Error\nread_map failed\n", 23);
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/// @brief puts the steps and the gold on the window
/// @param sl struct that holds the data
void	counter_img(t_so_long *sl)
{
	char	*str1;
	char	*str2;

	ft_printf("Steps: %d\n", sl->hero->instances[0].z);
	str1 = ft_itoa(sl->hero->instances[0].z);
	str1 = ft_strjoin("Steps: ", str1);
	str2 = ft_itoa(sl->gold->instances[0].z);
	str2 = ft_strjoin(" / Gold: ", str2);
	str1 = ft_strjoin(str1, str2);
	mlx_put_string(sl->mlx, str1, 0, 0);
	free(str1);
	free(str2);
}

/// @brief ends the program and puts out the error message 
/// when free is needet.
/// @param sl the struct that holds the data for freeing
/// @param error_code the error number for the message
void	end_cite2(t_so_long *sl, int error_code)
{
	if (error_code == 9)
		write(1, "Error Rendering\n", 17);
	mlx_terminate(sl->mlx);
	exit(EXIT_FAILURE);
}

/// @brief ends the program if no error message is needed
/// @param sl struct that holds the data
void	end_cite(t_so_long *sl)
{
	mlx_terminate(sl->mlx);
	exit(EXIT_SUCCESS);
}

void	map_ok(t_so_long *sl)
{
	if (sl->hero2->instances[0].z == 0
		|| sl->exit1->instances[0].z == 0
		|| sl->gold->instances[0].z == 0)
	{
		write(1, "Error\nMap is not correct\n", 26);
		end_cite(sl);
	}
}
