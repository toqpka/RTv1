/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/30 04:02:11 by gwaymar-         ###   ########.fr       */
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
** SDL functions
*/
SDL_Color     int_to_color(int color);
int           color_to_int(SDL_Color color);
void          clear_surface(SDL_Surface *surf, const SDL_Rect *rect, const int color, void *param);
void			clear_surface(SDL_Surface *surf, const SDL_Rect *rect, const int color, void *param);
void			draw_filled_square(SDL_Surface *surf, const SDL_Rect *rect, const int color, void *param);
SDL_Surface		*create_surface(int width, int height);

/*
** DRAWER few colors
*/
void      backgr(SDL_Surface		*frame);
t_vec3    ray_color(t_ray ray);
t_ray     new_ray(t_vec3 orig, t_vec3 dir);
double    hit_sphere(t_vec3 center, double radius, t_ray ray);
uint8_t   hitable(t_ray ray, double t_min, double t_max, t_hit_rec rec);

/*
** Color pack functions
*/
uint32_t    pack_color(const uint8_t r, const uint8_t g, const uint8_t b);
void        unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a);
/*
** Set_pixel on surface SDL
*/
//void          set_pixel(SDL_Surface *surface, int x, int y, uint32_t *pixel);
//void          set_pixel(SDL_Surface *surface, int x, int y, int color);
void          put_pixel(SDL_Surface *surf, const int x, const int y, const int color);

/*
** Some scene function
*/
void        scene1(t_sdl **sdl);
void        scene2(t_sdl **sdl);
void        scene3(t_sdl **sdl);
void        scene4(t_sdl **sdl);
void        scene5(t_sdl **sdl);

#endif
