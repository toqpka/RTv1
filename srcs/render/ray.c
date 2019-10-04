/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 03:35:42 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 03:43:58 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray     new_ray(t_vec3 orig, t_vec3 dir)
{
  t_ray n_ray;

  n_ray.origin = orig;
  n_ray.direct = dir;
  return (n_ray);
}

t_ray     get_ray(t_cam cam, double u, double v)
{
  t_ray   new_r;
  t_vec3  aa;
  t_vec3  dir;
  aa = vec_op_add(cam.lower_l,vec_scale(cam.horiz,u));
  dir = vec_op_add(aa,vec_scale(cam.vert,v));
  new_r = new_ray(cam.origin, dir);
  return (new_r);
}
