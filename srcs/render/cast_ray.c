/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:47:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 13:17:56 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	get_sphere_back(t_ray ray,SDL_Surface *map, t_mater mater)
{
	uint32_t color;
	uint8_t r,g,b,a;

	 t_mater   ivory;

	mater_fill(&ivory, MAT_IVORY);

	t_sphere spher = sphere_new(vec_new(0,0,0), 100, ivory);


float dist = 0;
ray_intersect(spher,ray, &dist);
//scene_intersect()
t_vec3 p = vec_op_add(ray.origin,vec_scale(ray.direct,dist));
int x = (atan2(p.z, p.x)/(2*PI) + (-0.4))*map->w;
int y = acos(p.y/100)/PI*map->h;


//color = read_pixel(map, x, y);
//unpack_color( color, &r, &g, &b, &a);

SDL_Color rgb;
uint32_t data = getpixel_surf(map, x, y);
SDL_GetRGB(data, map->format, &rgb.r, &rgb.g, &rgb.b);


return (vec_new(rgb.r/255.00,rgb.g/255.00,rgb.b/255.00));
}

t_vec3	cast_ray(t_ray ray, t_sphere *sphers, t_light *light , size_t	depth ,SDL_Surface *env_map)
{
	t_vec3		nbig,point;
	t_mater		mater;
	float			diff_light_intens = 0;
	float			spec_light_intens = 0;
	t_vec3		light_dir;

	t_vec3		left_return;
	t_vec3		right_return;

	double left_part_powf;
	int  check_intersect;


	    t_mater mat;
	    //mater_fill(&mat, MAT_RED_RUBBER);
			mater_fill(&mat, MAT_MIRROR);
			//mater_fill(&mat, MAT_RED_RUBBER);
	    t_vec3  n = vec_new(0,1,0);
	    t_vec3  line = vec_new(0,-7,0);
	    t_plane plane = plane_new(n, line,  mat);


	check_intersect = scene_intersect(plane, sphers,ray,&point,&nbig,&mater);

	if (depth > 4 || !check_intersect)
	{
		//return (vec_new(0.1,0.4,0.8)); // default  back
		return (get_sphere_back(ray,env_map,mater)); // default  back
	}
	t_vec3	reflect_dir = unit_vector(reflect(ray.direct, nbig));
	t_vec3	reflect_orig = ((vec_dot(reflect_dir,nbig)) < 0) ? vec_op_sub(point,vec_scale(nbig,(0.001))) : vec_op_add(point,vec_scale(nbig,(0.001)));
	t_ray		reflect_ray = new_ray(reflect_orig, reflect_dir);
	t_vec3	reflect_color = cast_ray(reflect_ray, sphers, light, depth + 1, env_map);

	int		i = -1;
	while (++i < LIGHT_NMB)
	//while (++i < 1)
	{
		light_dir = unit_vector(vec_op_sub(light[i].pos, point));
		//add shadows
		double light_distance = vec_length(vec_op_sub(light[i].pos, point));
		t_vec3 shadow_orig = ((vec_dot(light_dir,nbig) < 0) ? vec_op_sub(point,vec_scale(nbig,0.001)) : vec_op_add(point,vec_scale(nbig,0.001)));
		t_vec3 shadow_pt,shadow_n;
		t_mater	tmpmater;
		t_ray shadow_ray = new_ray(shadow_orig, light_dir);
		if (scene_intersect(plane, sphers,shadow_ray,&shadow_pt,&shadow_n,&tmpmater) && (vec_length(vec_op_sub(shadow_pt,shadow_orig)) < 1000))
			continue;
		diff_light_intens += light[i].intens * fmax(0.f, vec_dot(light_dir, nbig));
		left_part_powf = fmax(0.f, vec_dot(vec_scale(reflect(vec_scale(light_dir,-1.0), nbig),-1.f),ray.direct));
		spec_light_intens += powf(left_part_powf, mater.spec_exp)*light[i].intens;
	}
	left_return = vec_scale(vec_scale(mater.diff_col,diff_light_intens),mater.albedo.x);
	right_return = vec_scale(vec_scale(vec_new(1.0, 1.0, 1.0),spec_light_intens),mater.albedo.y);
	t_vec3 col = vec_op_add(vec_op_add(left_return,right_return),vec_scale(reflect_color,mater.albedo.z));

	//printf("col.x=%f   ",col.x);
	// while (col.x > 255 || col.y > 255 || col.z > 255)
	// {
	// 	vec_scale(col,1/255.);
	// }
	return (col);
	//return ((vec_op_add(left_return,right_return)));
}
