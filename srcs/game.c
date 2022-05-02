/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:40:31 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/24 15:19:33 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	is_collectible(t_data *data, int x, int y)
{
	if (data->map.map[x][y] == 'C')
	{
		data->map.map[x][y] = '0';
		data->collectible.nb_c--;
		return (1);
	}
	if (data->map.map[x][y] == 'E' && data->collectible.nb_c == 0)
	{
		printf(BLUE"____ ____ ____ ___  ____ ____ _  _ ____ \n");
		printf(BLUE"| __ |  | |  | |  \\ | __ |__| |\\/| |___\n");
		printf(BLUE"|__] |__| |__| |__/ |__] |  | |  | |___\n");
		printf("\n"NORMAL);
		free_all(data);
	}
	return (0);
}

int	update(t_data *data)
{
	data->time++;
	if (data->time >= 300)
		data->time = 0;
	draw_map(data);
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == W && data->map.map
		[data->player.pos.x - 1][data->player.pos.y] != '1')
		data->player.pos.x -= 1;
	else if (key == A && data->map.map
		[data->player.pos.x][data->player.pos.y - 1] != '1')
		data->player.pos.y -= 1;
	else if (key == S && data->map.map
		[data->player.pos.x + 1][data->player.pos.y] != '1')
		data->player.pos.x += 1;
	else if (key == D && data->map.map
		[data->player.pos.x][data->player.pos.y + 1] != '1')
		data->player.pos.y += 1;
	else if (key == ESC)
		free_all(data);
	else
		return (SUCCESS);
	data->shiffting++;
	is_collectible(data, data->player.pos.x, data->player.pos.y);
	printf("%d\n", data->shiffting);
	return (SUCCESS);
}
