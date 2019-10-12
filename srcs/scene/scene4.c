/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 06:29:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/08 08:07:33 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

Uint32 getpixel_surf(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

switch (bpp)
{
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
            break;

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
      }
}

void    scene4(t_sdl **sdl)
{
  SDL_Surface		*frame;
  SDL_Surface *env_map = IMG_Load( "textures/envmap.jpg" );
  //SDL_Surface *env_map = IMG_Load( "textures/Canada-Flag.bmp" );
  uint8_t r,g,b,a;
  uint32_t color;

  SDL_Color sdl_col;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);


  //ft_flip(frame); //  rotatte  verticaly

  int i,j;
j=-1;
while(++j < env_map->h)
{
  i=-1;
  while(++i < env_map->w)
  {
    //color = read_pixel(env_map, i, j);




    SDL_Color rgb;
    uint32_t data = getpixel_surf(env_map, i, j);    
    SDL_GetRGB(data, env_map->format, &rgb.r, &rgb.g, &rgb.b);
    //unpack_color( color, &r, &g, &b, &a);
    //sdl_col = int_to_color(color);

    put_pixel(frame, i, j, pack_color(rgb.r,rgb.g,rgb.b));
    //put_pixel(frame, i, j, pack_color(r,g,b));
  }
}
  //SDL_BlitSurface( env_map, NULL, frame, NULL );
  SDL_BlitSurface( frame, NULL, (*sdl)->screen, NULL );
  ft_putstr("Loading: scene4\n");
  return;
}
