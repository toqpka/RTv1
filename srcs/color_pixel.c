/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 01:33:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 04:07:51 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void          set_pixel(SDL_Surface *surface, int x, int y, uint32_t *pixel)
{
  unsigned int    *ptr;
  int             lineoffset;

  ptr = (unsigned int*)surface->pixels;
  lineoffset =  y * (surface->pitch / sizeof( unsigned int ) );
  ptr[lineoffset + x ] = pixel[y + x];
  return ;
}

uint32_t    pack_color(const uint8_t r, const uint8_t g, const uint8_t b)
{
  uint8_t a;
  a = 255;
  //return (r | g << 8 | b << 16 | a << 24);
  //return ((a<<24) + (b<<16) + (g<<8) + r);
  return ((a<<24) + (r<<16) + (g<<8) + b);
}

void        unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
{
  *r = (color >>  0) & 255;
  *g = (color >>  8) & 255;
  *b = (color >> 16) & 255;
  *a = (color >> 24) & 255;
//   return ;
}
