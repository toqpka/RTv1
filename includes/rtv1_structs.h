/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 06:47:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_vec3.h"

typedef struct		s_ray
{
  t_vec3      start;
  t_vec3      direct;
}                 t_ray;

typedef struct		s_framebuff
{
  size_t      w; // image dimensions
  size_t      h;
  uint32_t    *img; // storage container
}                 t_framebuff;

typedef struct		s_image
{
  uint32_t      width;
  uint32_t      height;
  uint32_t      lenght;
  uint32_t      *pixels;
}                 t_image;

typedef struct		s_sdl
{
  SDL_Window      *win;
  SDL_Surface     *screen;
  t_image         *screen_img;
  SDL_Surface     *image;
  SDL_Event       event;
  uint8_t         run_main;
  uint8_t         scene_num;
}                 t_sdl;

typedef struct		s_ltexture
{
  SDL_Texture* mTexture;

  //Image dimensions
  int mWidth;
  int mHeight;

}                 t_ltexture;

#endif
