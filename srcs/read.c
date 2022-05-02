/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:15:44 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/24 14:21:10 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	fill_map(t_data *data, void *file, int ret, int i)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (FAIL);
	while (ret > 0)
	{
		ret = get_next_line(fd, &data->map.map[i], 1);
		if (!data->map.map[i]
			|| ft_strlen(data->map.map[i]) == 0)
		{
			free_map_two_d_with_limit(data->map.map, i + 1);
			return (error(FAIL, "error with loading map"));
		}
		i++;
	}
	if (ret == -1)
	{
		free_map_two_d_with_limit(data->map.map, i);
		return (error(FAIL, "error with get_next_line"));
	}
	data->map.map[i] = 0;
	close(fd);
	return (SUCCESS);
}

char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	get_next_line(int fd, char **line, int reader)
{
	char			*buff;
	static char		*save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!has_return(save) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
