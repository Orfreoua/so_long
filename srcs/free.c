/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:09:53 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/26 11:51:08 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_map_two_d_with_limit(char **map, int limit)
{
	int	i;

	i = 0;
	while (map[i] && i < limit - 1)
	{
		ft_free(map[i]);
		i++;
	}
	ft_free(map[i]);
	free(map);
}

void	free_tab_two_d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab[i]);
	free(tab);
	tab = NULL;
}

void	destroy_textures(t_data *data)
{
	if (data->player.right1.img)
		mlx_destroy_image(data->mlx.init, data->player.right1.img);
	if (data->player.right2.img)
		mlx_destroy_image(data->mlx.init, data->player.right2.img);
	if (data->player.right3.img)
		mlx_destroy_image(data->mlx.init, data->player.right3.img);
	if (data->floor.img)
		mlx_destroy_image(data->mlx.init, data->floor.img);
	if (data->wall.img)
		mlx_destroy_image(data->mlx.init, data->wall.img);
	if (data->exit.screen_e.img)
		mlx_destroy_image(data->mlx.init, data->exit.screen_e.img);
	if (data->collectible.screen_c.img)
		mlx_destroy_image(data->mlx.init, data->collectible.screen_c.img);
	if (data->bonus.on && data->bonus.oursin.img)
		mlx_destroy_image(data->mlx.init, data->bonus.oursin.img);
}

void	close_windows(t_data *data)
{
	destroy_textures(data);
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.init, data->mlx.img);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.init, data->mlx.win);
	if (data->mlx.init)
		mlx_destroy_display(data->mlx.init);
	if (data->mlx.init)
		free(data->mlx.init);
	exit (0);
}

int	free_all(t_data *data)
{
	free_tab_two_d(data->map.map);
	close_windows(data);
	return (0);
}
