/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:32:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/25 17:23:03 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int main( int argc, char* args[] )
{
	t_sdl		*sdl;

	ft_init(&sdl);
	while (sdl->run_main)
	{
		while ( SDL_PollEvent( &(sdl->event) ) != 0 )
		{
			if((SDL_QUIT == sdl->event.type) || (SDL_KEYDOWN == sdl->event.type && SDL_SCANCODE_ESCAPE == sdl->event.key.keysym.scancode))
				sdl->run_main = 0;
		}
	}
	ft_close(&sdl);
	return (0);
}
