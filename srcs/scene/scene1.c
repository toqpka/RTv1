/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/03 20:57:36 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    scene1(t_sdl **sdl)
{
  SDL_Surface		*frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  //backgr(frame);

  SDL_BlitSurface( frame, NULL, (*sdl)->screen, NULL );
  ft_putstr("Loading: scene1\n");
  return;
}
