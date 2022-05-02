/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:15:18 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/25 00:15:21 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	error(int return_vallue, char *msg)
{
	printf(RED "%s\n", msg);
	printf(NORMAL);
	return (return_vallue);
}

int	find_index(char c, char *index_tab)
{
	int	index;

	index = 0;
	while (index_tab[index])
	{
		if (index_tab[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	size_of_map(void *file)
{
	int		size;
	char	*line;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (FAIL);
	size = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line, 1);
		ft_free(line);
		size++;
	}
	close(fd);
	if (ret == -1)
		return (FAIL);
	return (size + 1);
}
