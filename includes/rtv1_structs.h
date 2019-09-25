/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/25 16:24:49 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

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
}                 t_sdl;

typedef struct		s_ltexture
{
  SDL_Texture* mTexture;

  //Image dimensions
  int mWidth;
  int mHeight;

}                 t_ltexture;

#endif
