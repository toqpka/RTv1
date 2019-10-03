/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/03 23:13:53 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# include <math.h>
# include "libft.h"
# include "rtv1_structs.h"
# include "rtv1_prototypes.h"
# include "rtv1_vec3.h"

# define WIN_TITLE "RTv1 - SDL"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 800


# define SCENE1 "scene1"
# define SCENE2 "scene2"
# define SCENE3 "scene3"
# define SCENE4 "scene4"
# define SCENE5 "scene5"

# define SCENE1_IMG 1
# define SCENE2_IMG 2
# define SCENE3_IMG 3
# define SCENE4_IMG 4
# define SCENE5_IMG 5

/*
**	Spheres options and maters
*/
# define SPHERE_NMB 4
# define MAT_IVORY "ivory"
# define MAT_RED_RUBBER "red_rubber"
# define MAT_MIRROR "mirror"


# define LIGHT_NMB 3

# define MAX_DIST 20000
# define FALSE 0
# define TRUE 1
# define PI 3.14159265359
# define FOV PI/2.0
#endif
