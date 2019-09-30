/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/30 04:36:43 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_vec3.h"

typedef struct		s_ray
{
  t_vec3      origin;
  t_vec3      direct;
}                 t_ray;

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

typedef struct		s_hit_rec
{
  double    t;
  t_vec3    p;
  t_vec3    normal;
}                 t_hit_rec;

typedef struct		s_sphere
{
  double    radius;
  t_vec3    center;
}                 t_sphere;


typedef struct		s_hitable
{
  void                *content;
  size_t              content_size;
  struct s_hitable    *next;
  int                 list_size;
}                 t_hitable;
#endif
