/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/25 17:28:08 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static uint8_t init_sdl(t_sdl *sdl)
{
  	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
  	{
  		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
  		return (0);
  	}
  	else
  	{
  		if ( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
  			printf( "Warning: Linear texture filtering not enabled!" );
  		sdl->win = SDL_CreateWindow( WIN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN );
  		if ( sdl->win == NULL )
  		{
  			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
  			return (0);
  		}
  		else
  		{
  			//DRaw image
  		}
  	}
  	return (1);
}

void ft_init(t_sdl **sdl)
{
  if (!((*sdl) = ft_memalloc(sizeof(t_sdl))))
		ft_print_error_exit(&ft_putendl, "Error");
  (*sdl)->win = NULL;
  (*sdl)->screen = NULL;
  (*sdl)->image = NULL;
  (*sdl)->run_main = 1;
  if (!((*sdl)->screen_img = ft_memalloc(sizeof(t_image))))
		ft_print_error_exit(&ft_putendl, "Error_sc_img");
  (*sdl)->screen_img->width = 0;
  (*sdl)->screen_img->height = 0;
  (*sdl)->screen_img->lenght = 0;
  (*sdl)->screen_img->pixels = NULL;
  if (!(init_sdl((*sdl))))
    ft_print_error_exit(&ft_putendl, "Error_sdl");
  return ;
}

void ft_close(t_sdl **sdl)
{
  SDL_DestroyWindow( (*sdl)->win );
	(*sdl)->win = NULL;
	IMG_Quit();
	SDL_Quit();
  return ;
}
