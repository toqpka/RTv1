/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:05:23 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 04:06:52 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void          img_to_screen(SDL_Surface *scr, t_framebuff *frbuf)
{
  int i;
  int j;

  i = -1;
  while (++i < (int)frbuf->h)
  {
    j = -1;
    while (++j < (int)frbuf->w)
      set_pixel(scr, j, i, frbuf->img);
  }
  return ;
}

t_framebuff   *ft_framebuff_init(size_t w, size_t h, uint32_t color)
{
  t_framebuff   *fr;
  int           i;
  int           size_img;

  if (!(fr = (t_framebuff*)ft_memalloc(sizeof(t_framebuff))))
    ft_print_error_exit(&ft_putendl, "Error t_framebuf");
  if (!(fr->img = (uint32_t*)malloc(w * h * sizeof(uint32_t))))
    ft_print_error_exit(&ft_putendl, "Error t_framebuf->img");
  i = -1;
  size_img = w*h;
  while (++i < size_img)
    fr->img[i] = color;
  fr->w = w;
  fr->h = h;
  return (fr);
}
