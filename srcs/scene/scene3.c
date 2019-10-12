/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 06:29:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/05 01:47:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    scene3(t_sdl **sdl)
{
  SDL_Surface		*frame;
  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  back_scene3(frame);

  ft_flip(frame); //  rotatte  verticaly
  SDL_BlitSurface( frame, NULL, (*sdl)->screen, NULL );
  ft_putstr("Loading: scene3\n");
  return;
}
