/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 01:59:47 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/30 02:12:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

SDL_Color     int_to_color(int color)
{
	SDL_Color	ret_color;

	ret_color.r = (color >> 24) & 0xFF;
	ret_color.g = (color >> 16) & 0xFF;
	ret_color.b = (color >> 8) & 0xFF;
	ret_color.a = (color) & 0xFF;
	return (ret_color);
}

int           color_to_int(SDL_Color color)
{
	int			ret_color;

	ret_color = 0;
	ret_color = (ret_color << 8) + color.a;
	ret_color = (ret_color << 8) + color.b;
	ret_color = (ret_color << 8) + color.g;
	ret_color = (ret_color << 8) + color.r;
	return (ret_color);
}
