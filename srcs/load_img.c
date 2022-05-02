/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:44:23 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/24 14:46:51 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_screen	load_image(void *mlx, char *path, t_data *data)
{
	t_screen	screen;

	screen.img = mlx_xpm_file_to_image(mlx, path,
			&(screen.width), &(screen.height));
	if (!screen.img)
	{
		error(FAIL, "Error during image loading.");
		free_all(data);
	}
	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel,
			&screen.line_length, &screen.endian);
	return (screen);
}

void	init_textures(t_data *data)
{
	data->player.right1 = load_image(data->mlx.init,
			"assets/textures/mario1.xpm", data);
	data->player.right2 = load_image(data->mlx.init,
			"assets/textures/mario2.xpm", data);
	data->player.right3 = load_image(data->mlx.init,
			"assets/textures/mario3.xpm", data);
	data->collectible.screen_c = load_image(data->mlx.init,
			"assets/textures/piece.xpm", data);
	data->exit.screen_e = load_image(data->mlx.init,
			"assets/textures/flag.xpm", data);
	data->wall = load_image(data->mlx.init,
			"assets/textures/block.xpm", data);
	data->floor = load_image(data->mlx.init,
			"assets/textures/blue.xpm", data);
}
