/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/05 01:41:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int ft_flip(SDL_Surface *surface)
{
    Uint8 *t;
    register Uint8 *a, *b;
    Uint8 *last;
    register Uint16 pitch;
    // if( SDL_LOCKIFMUST(surface) < 0 )
    //     return -2;

    /* do nothing unless at least two lines */
    if(surface->h < 2) {
        //SDL_UNLOCKIFMUST(surface);
        return 0;
    }
    /* get a place to store a line */
    pitch = surface->pitch;
    t = (Uint8*)malloc(pitch);
    if(t == NULL) {
      //  SDL_UNLOCKIFMUST(surface);
        return -2;
    }
    /* get first line; it's about to be trampled */
    memcpy(t,surface->pixels,pitch);
    /* now, shuffle the rest so it's almost correct */
    a = (Uint8*)surface->pixels;
    last = a + pitch * (surface->h - 1);
    b = last;

    while(a < b) {
        memcpy(a,b,pitch);
        a += pitch;
        memcpy(b,a,pitch);
        b -= pitch;
    }
    /* in this shuffled state, the bottom slice is too far down */
    memmove( b, b+pitch, last-b );
    /* now we can put back that first row--in the last place */
    memcpy(last,t,pitch);
    /* everything is in the right place; close up. */
    free(t);
    //SDL_UNLOCKIFMUST(surface);
    return 0;
}

void    scene1(t_sdl **sdl)
{
  SDL_Surface		*frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  backgr(frame);

  ft_flip(frame); //  rotatte  verticaly
  SDL_BlitSurface( frame, NULL, (*sdl)->screen, NULL );
  ft_putstr("Loading: scene1\n");
  return;
}
