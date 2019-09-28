/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 06:29:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 07:22:11 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void  check(t_framebuff		*frbuf)
{
  for (size_t j = 0; j<frbuf->h; j++) {
        for (size_t i = 0; i<frbuf->w; i++)
        {
            frbuf->img[i+j*frbuf->w] = pack_color(i/(double)(frbuf->h)*1.0f,j/(double)(frbuf->w)*1.0f, 255);
            //frbuf->img[i+j*frbuf->w] = pack_color(255,255, 0);
        }
    }
}

void    scene3(t_sdl **sdl)
{
  t_framebuff		*frbuf;

  frbuf = ft_framebuff_init(800, 512, pack_color(255, 255, 255));
  check(frbuf);
  img_to_screen((*sdl)->screen , frbuf);
  ft_putstr("Loading: scene3\n");
  return;
}
