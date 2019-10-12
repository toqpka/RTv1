/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:42:37 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/10 21:54:11 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
// for cone
int ray_intersect_cone(t_cone cone, t_ray ray, float *t0)
{
  float a = ray.origin.x - cone.center.x;
  float b = ray.origin.z - cone.center.z;
  float d = cone.height - ray.origin.y + cone.center.y;
  float tan = (cone)
  *t0 = 0;
  return FALSE;
}

t_plane   plane_new(t_vec3 n,t_vec3 line,t_mater  mat)
{
  t_plane new_p;

  new_p.norm = n;
  new_p.line = line;
  new_p.mater = mat;
  return (new_p);
}
