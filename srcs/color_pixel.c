/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 01:33:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 02:57:48 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// void          set_pixel(SDL_Surface *surface, int x, int y, uint32_t *pixel)
// {
//   unsigned int    *ptr;
//   int             lineoffset;
//
//   // ptr = (unsigned int*)surface->pixels;
//   // lineoffset =  y * (surface->pitch / sizeof( unsigned int ) );
//   // printf("line=%d \n",lineoffset);
//
//   Uint8* pi = (Uint8*)surface->pixels;
//   pi += (y * surface->pitch) + (x * sizeof(Uint32));
//   *((Uint32*)pi) = *pixel;
//
//   //ptr[lineoffset + x ] = pixel[x + y];
//   return ;
// }


// void			set_pixel(SDL_Surface *surface, int x, const int y, int color)
// {
// 	Uint32		*pixels;
//
// 	pixels = (Uint32 *)surface->pixels;
// 	if (x >= 0 && y >= 0 && x < surface->w && y < surface->h)
// 		pixels[y * surface->w + x] = color;
// }
//
uint32_t    pack_color(const uint8_t r, const uint8_t g, const uint8_t b)
{
  uint8_t a;
  a = 255;
  return (r | g << 8 | b << 16 | a << 24);
}
//
// void        unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
// {
//   *b = (color >>  0) & 255;
//   *g = (color >>  8) & 255;
//   *r = (color >> 16) & 255;
//   *a = (color >> 24) & 255;
// //   return ;
// }

void			put_pixel(SDL_Surface *surf, const int x, const int y, const int color)
{
	Uint32		*pixels;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
	{
		pixels = (Uint32 *)surf->pixels;
		pixels[y * surf->w + x] = color;
	}
}

Uint32		read_pixel(SDL_Surface *surf, const int x, const int y)
{
	Uint32		pixel;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
		pixel = (Uint32)(surf->pixels + y * surf->w + x);
	else
		pixel = 0;
	return (pixel);
}
