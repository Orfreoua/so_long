/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 06:55:57 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/26 17:31:25 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	moves_ia2(t_data *data)
{
	if (data->collectible.nb_c % 2 == 0)
	{
		if (data->time > 150)
			data->bonus.dir2 *= -1;
		if (data->map.map[data->bonus.pos2.x]
			[data->bonus.pos2.y + data->bonus.dir2]
			!= '1')
			data->bonus.pos2.y += data->bonus.dir2;
		else
			data->bonus.dir2 *= -1;
	}
	else
	{
		if (data->time > 150)
			data->bonus.dir2 *= -1;
		if (data->map.map[data->bonus.pos2.x
				+ data->bonus.dir2][data->bonus.pos2.y]
				!= '1')
			data->bonus.pos2.x += data->bonus.dir2;
		else
			data->bonus.dir2 *= -1;
	}
}

void	moves_ia(t_data *data)
{
	if (data->collectible.nb_c % 2 == 0)
	{
		if (data->time > 150)
			data->bonus.dir *= -1;
		if (data->map.map[data->bonus.pos.x]
			[data->bonus.pos.y + data->bonus.dir]
			!= '1')
			data->bonus.pos.y += data->bonus.dir;
		else
			data->bonus.dir *= -1;
	}
	else
	{
		if (data->time > 150)
			data->bonus.dir *= -1;
		if (data->map.map[data->bonus.pos.x
				+ data->bonus.dir][data->bonus.pos.y]
				!= '1')
			data->bonus.pos.x += data->bonus.dir;
		else
			data->bonus.dir *= -1;
	}
}

void	bonus_display(t_data *data)
{
	if (((data->player.pos.x == data->bonus.pos.x)
			&& (data->player.pos.y == data->bonus.pos.y))
		|| ((data->player.pos.x == data->bonus.pos2.x)
			&& (data->player.pos.y == data->bonus.pos2.y)))
	{
		printf(RED"____ ____ _  _ ____ ____ _  _ ____ ____ \n");
		printf(RED"____ ____ _  _ ____ ____ _  _ ____ ____ \n");
		printf(RED"| __ |__| |\\/| |___ |  | |  | |___ |__/ \n");
		printf(RED"|__] |  | |  | |___ |__|  \\/  |___ |  \\  \n"NORMAL);
		printf(NORMAL);
		free_all(data);
	}
	draw_on_img(&data->mlx, &data->bonus.oursin,
		data->bonus.pos.y * 64, data->bonus.pos.x * 64);
	draw_on_img(&data->mlx, &data->bonus.oursin,
		data->bonus.pos2.y * 64, data->bonus.pos2.x * 64);
	moves_ia(data);
	moves_ia2(data);
}

void	display_nb_moves(t_data *data)
{
	(void)data;
	data->moves_ascii = ft_itoa(data->shiffting);
	if (!data->moves_ascii)
		free_all(data);
	mlx_string_put(data->mlx.init, data->mlx.win, 20, 20, 4040404,
		data->moves_ascii);
	ft_free(data->moves_ascii);
}

void	bonus(t_data *data)
{
	if (data->bonus.on)
		data->bonus.oursin = load_image(data->mlx.init,
				"assets/textures/Oursin.xpm", data);
	data->bonus.pos.y = data->map.grid_width / 2;
	data->bonus.pos.x = data->map.grid_height / 2;
	data->bonus.pos2.x = data->bonus.pos.x / 2;
	data->bonus.pos2.y = data->bonus.pos.y / 2;
	data->bonus.dir = 1;
	data->bonus.dir2 = -1;
}
