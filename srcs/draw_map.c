/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:32:53 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/26 16:41:43 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	draw_next(t_data *data)
{
	draw_player(data);
	if (data->bonus.on)
		bonus_display(data);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win,
		data->mlx.img, 0, 0);
	if (data->bonus.on)
		display_nb_moves(data);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == '0')
				draw_on_img(&data->mlx, &data->floor, y * 64, x * 64);
			else if (data->map.map[x][y] == 'C')
				draw_on_img(&data->mlx, &data->collectible.screen_c,
					y * 64, x * 64);
			else if (data->map.map[x][y] == 'E')
				draw_on_img(&data->mlx, &data->exit.screen_e, y * 64, x * 64);
			else
				draw_on_img(&data->mlx, &data->wall, y * 64, x * 64);
			y++;
		}
		x++;
	}
	draw_next(data);
}

void	draw_on_img(t_screen *img, t_screen *s_img, int startX, int startY)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < 64)
	{
		draw.y = 0;
		while (draw.y < 64)
		{
			draw.r_x = (float)draw.x / (float)64;
			draw.r_y = (float)draw.y / (float)64;
			draw.pos_x = draw.r_x * s_img->width;
			draw.pos_y = draw.r_y * s_img->height;
			draw.color = get_pixel(s_img, draw.pos_x, draw.pos_y);
			draw.p_data_x = startX + draw.x;
			draw.p_data_y = startY + draw.y;
			set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

void	draw_player(t_data *data)
{
	if (data->time < 50 || data->time > 250)
		draw_on_img(&data->mlx, &(data->player.right1),
			data->player.pos.y * 64, data->player.pos.x * 64);
	else if (data->time < 100 || data->time > 200)
		draw_on_img(&data->mlx, &(data->player.right2),
			data->player.pos.y * 64, data->player.pos.x * 64);
	else
		draw_on_img(&data->mlx, &(data->player.right2),
			data->player.pos.y * 64, data->player.pos.x * 64);
}
