/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:53:17 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/03 21:11:32 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// t_vec3 ray_color(t_ray ray)
// {
//   double t = hit_sphere(vec_new(0,0,-1),0.9,ray);
//   if (t > 0.0)
//   {
//     t_vec3 point_at = vec_op_add(ray.origin,vec_scale(ray.direct,t));
//     t_vec3 nbig = unit_vector(vec_op_sub(point_at,vec_new(0,0,-1)));
//     return vec_scale(vec_op_add(nbig,vec_new(1,1,1)),0.5);
//   }
//   t_vec3 unit_direct = unit_vector(ray.direct);
//   t = 0.7*(unit_direct.y + 1.0);
//   t_vec3 a = vec_scale(vec_new(1.0, 1.0, 1.0), 1.0-t);
//   t_vec3 b = vec_scale(vec_new(0.5, 0.7, 1.0), t);
//   return (vec_op_add(a,b));
// }





////////////// GOOD   fix  cast_ray  need array spheres   *spheres
// void    backgr(SDL_Surface		*frame)
// {
//   int i,j;
//   double down = frame->h/100.0;
//   double left = frame->w/100.0;
//   //printf("down=%lf   left=%lf\n",down,left);
//   t_vec3 lower_l = vec_new(-left,-down,-1.0);
//   t_vec3 horiz = vec_new(left*2.0, 0.0, 0.0);
//   t_vec3 vert = vec_new(0.0, down*2.0, 0.0);
//   t_vec3 origin = vec_new(0.0, 0.0, 0.0);
//   //t_hitable *list[2];
//   t_mater   ivory;
//   t_mater   red_rubber;
//
//   mater_fill(&ivory, MAT_IVORY);
//   mater_fill(&red_rubber, MAT_RED_RUBBER);
//
//
//
//   t_sphere sphere = sphere_new(vec_new(0,0,-1.0), 0.1, ivory);
//   t_sphere sphere2 = sphere_new(vec_new(0,-100.5,-1.0), 100, red_rubber);
//   i = -1;
//   while (++i < frame->h)
//   {
//     j = -1;
//     while (++j < frame->w)
//     {
//       double x =  (2*(j+0.5)/(double)frame->w - 1)*tan(FOV/2.0)*frame->w/(double)frame->h;
//       double y = -(2*(i+0.5)/(double)frame->h - 1)*tan(FOV/2.0);
//       t_vec3 dir = unit_vector(vec_new(x, y, -1));
//       t_ray ray = new_ray(origin, dir);
//       t_vec3 col = cast_ray(ray, sphere);
//       int r = (int)(255.99*col.x);
//       int g = (int)(255.99*col.y);
//       int b = (int)(255.99*col.z);
//       put_pixel(frame, j, i, pack_color(r,g,b));
//     }
//   }
//   return ;
// }
