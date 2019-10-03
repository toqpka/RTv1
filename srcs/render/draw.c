/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:38:13 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/03 23:44:05 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	cast_ray(t_ray ray, t_sphere *sphers, t_light *light , size_t	depth)
{
	t_vec3		nbig,point;
	t_mater		mater;
	double		diff_light_intens = 0;
	double		spec_light_intens = 0;
	t_vec3		light_dir;

	t_vec3		left_return;
	t_vec3		right_return;

	double left_part_powf;

	if (depth > 1 || !scene_intersect(sphers,ray,&point,&nbig,&mater))
	{
		return (vec_new(0.2,0.7,0.8)); //backgroung color
	}
	t_vec3	reflect_dir = unit_vector(reflect(ray.direct, nbig));
	t_vec3	reflect_orig = (vec_dot(reflect_dir,nbig)) ? vec_op_sub(point,vec_scale(nbig,1e-3)) : vec_op_add(point,vec_scale(nbig,1e-3));
	t_ray		reflect_ray = new_ray(reflect_orig, reflect_dir);
	t_vec3	reflect_color = cast_ray(reflect_ray, sphers, light, depth + 1);

	int		i = -1;
	while (++i < LIGHT_NMB)
	{
		light_dir = unit_vector(vec_op_sub(light[i].pos, point));
		//add shadows
		double light_distance = vec_length(vec_op_sub(light[i].pos, point));
		t_vec3 shadow_orig = (vec_dot(light_dir,nbig) < 0) ? vec_op_sub(point,vec_scale(nbig,1e-3)) : vec_op_add(point,vec_scale(nbig,1e-3));
		t_vec3 shadow_pt,shadow_n;
		t_mater	tmpmater;
		t_ray shadow_ray = new_ray(shadow_orig, light_dir);
		if (scene_intersect(sphers,shadow_ray,&shadow_pt,&shadow_n,&tmpmater) && (vec_length(vec_op_sub(shadow_pt,shadow_orig)) < light_distance))
			continue;
		diff_light_intens += light[i].intens * fmax(0.0f, vec_dot(light_dir, nbig));
		left_part_powf = (double)fmax(0.0f, vec_dot(vec_scale(reflect(vec_scale(light_dir,-1), nbig),-1),ray.direct));
		spec_light_intens += (double)powf(left_part_powf, mater.spec_exp)*light[i].intens;
	}
	left_return = vec_scale(vec_scale(mater.diff_col,diff_light_intens),mater.albedo.x);
	right_return = vec_scale(vec_scale(vec_new(1.0, 1.0, 1.0),spec_light_intens),mater.albedo.y);
	return (vec_op_add(vec_op_add(left_return,right_return),vec_scale(reflect_color,mater.albedo.z)));
}

void		choose_scene(t_sdl **sdl)
{
	if ((*sdl)->scene_num == SCENE1_IMG)
		scene1(sdl);
	else if ((*sdl)->scene_num == SCENE2_IMG)
		scene2(sdl);
	else if ((*sdl)->scene_num == SCENE3_IMG)
		scene3(sdl);
	else if ((*sdl)->scene_num == SCENE4_IMG)
		scene4(sdl);
	else if ((*sdl)->scene_num == SCENE5_IMG)
		scene5(sdl);
	else
		ft_print_error_exit(&ft_putendl, "Error not_scene");
	return ;
}

void		sdl_render(t_sdl *sdl)
{
	choose_scene(&sdl);
	//SDL_BlitSurface( sdl->image, NULL, sdl->screen, NULL );
	SDL_UpdateWindowSurface(sdl->win);
	return ;
}
