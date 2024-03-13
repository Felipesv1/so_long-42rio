/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:00:16 by felperei          #+#    #+#             */
/*   Updated: 2024/03/13 09:06:52 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_Long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		gameplay(av[1], &game);
	}
	else
	{
		ft_printf("Error\nInvalid Sytax\n");
		exit(1);
	}
	return (0);
}
