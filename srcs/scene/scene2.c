/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:06:25 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/03 18:46:49 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    scene2(t_sdl **sdl)
{
  SDL_Surface		*frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  back_scene2(frame);

  SDL_BlitSurface( frame, NULL, (*sdl)->screen, NULL );
  ft_putstr("Loading: scene2\n");
  return;
}
