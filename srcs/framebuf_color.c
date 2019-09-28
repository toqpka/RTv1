/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuf_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:10:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 04:13:54 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Flame pattern for frame_img
*/

void          color_frame_flame(t_framebuff *frbuf)
{
  int   i;
  int   j;
  uint8_t   r;
  uint8_t   g;
  uint8_t   b;
  float   fr;
  float   fg;
  float   fb;


  i = -1;
  if (frbuf->w && frbuf->h)
  {
    while (++i < frbuf->w)
    {
      j = -1;
      while (++j < frbuf->h)
      {
        fr = (float)i / (float)((int)frbuf->w);
        fg = (float)j / (float)((int)frbuf->h);
        fb = 0.2;
        r = (uint8_t)(255.99*fr);
        g = (uint8_t)(255.99*fg);
        b = (uint8_t)(255.99*fb);
        frbuf->img[i+j] = pack_color(r, g, b);
      }
    }
  }
  return ;
}
