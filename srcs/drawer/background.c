/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:53:17 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/30 04:43:17 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3 ray_color(t_ray ray)
{
  double t = hit_sphere(vec_new(0,0,-1),0.9,ray);
  if (t > 0.0)
  {
    t_vec3 point_at = vec_op_add(ray.origin,vec_scale(ray.direct,t));
    t_vec3 nbig = unit_vector(vec_op_sub(point_at,vec_new(0,0,-1)));
    return vec_scale(vec_op_add(nbig,vec_new(1,1,1)),0.5);
  }
  t_vec3 unit_direct = unit_vector(ray.direct);
  t = 0.7*(unit_direct.y + 1.0);
  t_vec3 a = vec_scale(vec_new(1.0, 1.0, 1.0), 1.0-t);
  t_vec3 b = vec_scale(vec_new(0.5, 0.7, 1.0), t);
  return (vec_op_add(a,b));
}

void    backgr(SDL_Surface		*frame)
{
  int i,j;
  double down = frame->h/100.0;
  double left = frame->w/100.0;
  //printf("down=%lf   left=%lf\n",down,left);
  t_vec3 lower_l = vec_new(-left,-down,-1.0);
  t_vec3 horiz = vec_new(left*2.0, 0.0, 0.0);
  t_vec3 vert = vec_new(0.0, down*2.0, 0.0);
  t_vec3 origin = vec_new(0.0, 0.0, 0.0);
  //hitable *list[2];
  i = -1;
  while (++i < frame->h)
  {
    j = -1;
    while (++j < frame->w)
    {
      double hor = (double)j / (double)frame->w;
      double ver = (double)i / (double)frame->h;
      t_vec3 xx = vec_scale(horiz, hor);
      t_vec3 yy = vec_scale(vert, ver);
      t_vec3 cc = vec_op_add(lower_l,xx);
      t_vec3 dir = vec_op_add(cc,yy);
      t_ray ray = new_ray(origin, dir);
      t_vec3 col = ray_color(ray);
      int r = (int)(255.99*col.x);
      int g = (int)(255.99*col.y);
      int b = (int)(255.99*col.z);
      put_pixel(frame, j, i, pack_color(r,g,b));
    }
  }
  return ;
}
