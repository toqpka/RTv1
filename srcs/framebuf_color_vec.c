/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuf_color_vec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:10:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 07:22:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** sky pattern for frame_img
*/

t_ray new_ray(t_vec3 orig, t_vec3 dir)
{
  t_ray n_ray;

  n_ray.start = orig;
  n_ray.direct = dir;
  return (n_ray);
}

t_vec3 color_ray(t_ray ray)
{
  t_vec3 unit_direct = vec_norm(ray.direct);
  double t = 4.2*(unit_direct.y+1.0);
  t_vec3 add;
  t_vec3 v1;
  t_vec3 v2;
  v1 = vec_scale(vec_new(1.0, 1.0, 1.0), 1.0-t);
  v2 = vec_scale(vec_new(0.5, 0.7, 1.0), t);
  add = vec_op_add(v1,v2);
  return (add);
}

void          color_frame_vec(t_framebuff *frbuf)
{
  int   i;
  int   j;
  uint8_t   r;
  uint8_t   g;
  uint8_t   b;
  float   fr;
  float   fg;
  float   fb;
  t_vec3    lower_l = vec_new(-2.0, -1.0, -1.0);
  t_vec3    horiz = vec_new(4.0, 0.0, 0.0);
  t_vec3    vert = vec_new(0.0, 2.0, 0.0);
  t_vec3    origin = vec_new(0.0, 0.0, 0.0);

  if (frbuf->w && frbuf->h)
  {
    j = -1;
    while (++j < frbuf->h)
    {
      i = -1;
      while (++i < frbuf->w)
      {
        double u = (float)i / (float) frbuf->w;
        double v = (float)j / (float) frbuf->h;
        t_ray r_ray = new_ray(origin, vec_op_add(lower_l, vec_op_add(vec_scale(horiz, (double)u), vec_scale(vert, (double)v))));
        t_vec3 col = color_ray(r_ray);
        r = (uint8_t)(255.99*col.x);
        g = (uint8_t)(255.99*col.y);
        b = (uint8_t)(255.99*col.z);
        frbuf->img[i+j] = pack_color(r, g, b);
      }
    }
  }
  return ;
}
