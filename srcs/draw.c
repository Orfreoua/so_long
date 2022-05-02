/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:27:59 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/26 11:54:54 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
** return the color of a point on the img
*/
int	get_pixel(t_screen *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + (x * \
						(img->bits_per_pixel / 8)))));
}

void	set_pixel(t_screen *screen, int x, int y, int color)
{
	*(unsigned int *)(screen->addr + (y * screen->line_length
				+ x * (screen->bits_per_pixel / 8))) = color;
}

/*
**  draw in the current images
*/

void	my_mlx_pixel_put(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length
			+ x * (screen->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
