/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 06:30:56 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_PROTOTYPES_H
# define RTV1_PROTOTYPES_H

/*
** Main functions
*/
void        ft_close(t_sdl **sdl);
void        ft_init(t_sdl **sdl, uint8_t sc);
void		    sdl_loop(t_sdl *sdl);
void        how_to_use(void);

/*
** Read functions
*/
void        read_init(t_sdl **sdl, char *argv);

/*
** Draw functions
*/
void		    sdl_render(t_sdl *sdl);

/*
** Color pack functions
*/
uint32_t    pack_color(const uint8_t r, const uint8_t g, const uint8_t b);
void        unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a);
/*
** Set_pixel on surface SDL
*/
void          set_pixel(SDL_Surface *surface, int x, int y, uint32_t *pixel);

/*
** Some scene function
*/
void        scene1(t_sdl **sdl);
void        scene2(t_sdl **sdl);
void        scene3(t_sdl **sdl);

/*
** Useless can be change
*/
t_framebuff   *ft_framebuff_init(size_t w, size_t h, uint32_t color);
void          img_to_screen(SDL_Surface *scr, t_framebuff *frbuf);
void          color_frame_flame(t_framebuff *frbuf);
void          color_frame_vec(t_framebuff *frbuf);
#endif
