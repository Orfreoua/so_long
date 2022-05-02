/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:47:28 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/26 16:38:04 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_data(t_data *data)
{
	data->player.nb_p = 0;
	data->collectible.nb_c = 0;
	data->exit.nb_e = 0;
	data->map.grid_width = 0;
	data->map.grid_height = 0;
	data->time = 0;
	data->shiffting = 0;
}

void	so_long_loop(t_data *data)
{	
	draw_map(data);
	mlx_loop_hook(data->mlx.init, update, data);
	mlx_hook(data->mlx.win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx.win, 33, 1L << 5, free_all, data);
	mlx_loop(data->mlx.init);
}

void	load_game(t_data *data)
{
	data->mlx.init = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.init, data->map.grid_width * 64,
			data->map.grid_height * 64, "game");
	data->mlx.img = mlx_new_image(data->mlx.init,
			data->map.grid_width * 64, data->map.grid_height * 64);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
	init_textures(data);
	if (data->bonus.on)
		bonus(data);
	so_long_loop(data);
	mlx_loop(data->mlx.init);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (error(FAIL, "Need map!"));
	data.bonus.on = 0;
	init_data(&data);
	if (!load_map(&data, argv[1]))
		return (FAIL);
	load_game(&data);
	return (0);
}
