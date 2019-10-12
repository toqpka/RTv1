/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 00:11:02 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/10 20:41:08 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
// for plane
int ray_intersect_plane(t_plane plane, t_ray ray, float *t0)
{
  double  c = vec_dot(ray.direct,plane.norm);
  if (c == 0) return FALSE;
  double alp = (vec_dot(plane.line,plane.norm) - vec_dot(ray.origin,plane.norm))/c;
  //double alp = (vec_dot(ray.origin,plane.norm))/c;
  if (alp < 0) return FALSE;
  *t0 = alp;
  return TRUE;
}

t_plane   plane_new(t_vec3 n,t_vec3 line,t_mater  mat)
{
  t_plane new_p;

  new_p.norm = n;
  new_p.line = line;
  new_p.mater = mat;
  return (new_p);
}
