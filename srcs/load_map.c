/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:07:35 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/24 15:08:56 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	valid_char(t_data *data, char c, int x, int y)
{
	int	index;
	int	len;

	len = ft_strlen(data->map.map[x]);
	index = find_index(c, "10PCE");
	if (index == 0)
		return (SUCCESS);
	if (index == -1)
		return (FAIL);
	if (c == 'P')
	{
		data->map.map[x][y] = '0';
		data->player.pos.x = x;
		data->player.pos.y = y;
		data->player.nb_p++;
	}
	else if (c == 'C')
		data->collectible.nb_c++;
	else if (c == 'E')
		data->exit.nb_e++;
	if ((x == 0 || y == 0) || (y == len))
		return (FAIL);
	return (SUCCESS);
}

int	check_map(t_data *data, int x, int y)
{
	while (data->map.map[x - 1][++y])
	{
		if (data->map.map[x - 1][y] != '1')
			return (error(FAIL, "bad map"));
	}
	if (data->player.nb_p != 1 || data->exit.nb_e < 1
		|| data->collectible.nb_c < 1 || y != data->map.grid_width)
		return (error(FAIL, "bad map"));
	return (SUCCESS);
}

int	good_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->map.grid_width = ft_strlen(data->map.map[x]);
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (!valid_char(data, data->map.map[x][y], x, y))
				return (FAIL);
			y++;
		}
		if (data->map.map[x][y - 1] != '1')
			return (FAIL);
		if (y != data->map.grid_width)
			return (error(FAIL, "map are not rectangle"));
		x++;
	}
	data->map.grid_height = x;
	y = 0;
	return (check_map(data, x, y));
}

int	check_name(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (n[i] == '.')
		{
			if ((n[i + 1] && n[i + 1] == 'b')
				&& (n[i + 2] && n[i + 2] == 'e')
				&& (n[i + 3] && n[i + 3] == 'r')
				&& (!n[i + 4]))
				return (SUCCESS);
		}
		i++;
	}
	return (error(FAIL, "bad name file"));
}

int	load_map(t_data *data, void *file)
{
	int	size;

	if (!check_name(file))
		return (FAIL);
	size = size_of_map(file);
	data->map.map = malloc(sizeof(char *) * size);
	if (!data->map.map)
		return (error(FAIL, "error malloc the map 2d"));
	if (fill_map(data, file, 1, 0) == 0)
		return (FAIL);
	if (!good_map(data))
	{
		free_tab_two_d(data->map.map);
		return (error(FAIL, "Not a good map"));
	}
	return (SUCCESS);
}
