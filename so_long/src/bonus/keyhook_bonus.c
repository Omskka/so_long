/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <binurtas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:39 by binurtas          #+#    #+#             */
/*   Updated: 2023/04/08 21:05:15 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_move_up(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y - 1][game->pl_x] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/up.xpm";
	ft_fill_window(game);
}

void	ft_move_down(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y + 1][game->pl_x] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/down.xpm";
	ft_fill_window(game);
}

void	ft_move_left(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x - 1] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/left.xpm";
	ft_fill_window(game);
}

void	ft_move_right(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x + 1] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/right.xpm";
	ft_fill_window(game);
}

int	ft_keyboard(int keyhook, t_game *game)
{
	if (keyhook == 53)
		ft_close_window(game);
	ft_enemy(keyhook, game);
	if (game->collect == 0 && ((keyhook == 2 && game->map[game->pl_y][game->pl_x
				+ 1] == 'E') || (keyhook == 1 && game->map[game->pl_y
				+ 1][game->pl_x] == 'E') || (keyhook == 0
				&& game->map[game->pl_y][game->pl_x - 1] == 'E')
			|| (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] == 'E')))
	{
		ft_printf("Thx you for collecting all the Pokemon!\n");
		ft_close_window(game);
	}
	if (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] != '1'
		&& game->map[game->pl_y - 1][game->pl_x] != 'E')
		ft_move_up(game);
	else if (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] != '1'
			&& game->map[game->pl_y][game->pl_x - 1] != 'E')
		ft_move_left(game);
	else if (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] != '1'
			&& game->map[game->pl_y + 1][game->pl_x] != 'E')
		ft_move_down(game);
	else if (keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] != '1'
			&& game->map[game->pl_y][game->pl_x + 1] != 'E')
		ft_move_right(game);
	return (0);
}
