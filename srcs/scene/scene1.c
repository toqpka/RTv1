/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 04:13:58 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    scene1(t_sdl **sdl)
{
  t_framebuff		*frbuf;

  frbuf = ft_framebuff_init(800, 512, pack_color(255, 255, 255));
  color_frame_flame(frbuf);
  img_to_screen((*sdl)->screen , frbuf);
  ft_putstr("Loading: scene1\n");
  return;
}
