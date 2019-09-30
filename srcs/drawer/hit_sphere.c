/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:28:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/30 04:43:49 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double    hit_sphere(t_vec3 center, double radius, t_ray ray)
{
  t_vec3 oc = vec_op_sub(ray.origin,center);
  double a = vec_dot(ray.direct, ray.direct);
  double b = 2.0 * vec_dot(oc, ray.direct);
  double c = vec_dot(oc, oc) - radius*radius;
  double discrim = b*b - 4*a*c;

  return ((discrim < 0) ? -1.0 : (-b - sqrt(discrim)) / (2.0*a));
}

// uint8_t   hitable(t_sphere sphere, t_ray ray, double t_min, double t_max, t_hit_rec rec)
// {
//   t_vec3 oc = vec_op_sub(ray.origin,sphere.center);
//   double a = vec_dot(ray.direct, ray.direct);
//   double b = vec_dot(oc, ray.direct);
//   double c = vec_dot(oc, oc) - radius*radius;
//   double discrim = b*b - a*c;
//   if (discrim > 0)
//   {
//     double temp = (-b - sqrt(b*b-a*c))/a;
//     if (temp < t_max && temp > t_min)
//     {
//       rec.t = temp;
//       rec.p = vec_op_add(ray.origin,vec_scale(ray.direct,rec.t));
//       rec.normal = vec_scale(vec_op_sub(rec.p,sphere.center),1.0/radius);
//       return (1);
//     }
//     temp = (-b + sqrt(b*b-a*c))/a;
//     if (temp < t_max && temp > t_min)
//     {
//       rec.t = temp;
//       rec.p = vec_op_add(ray.origin,vec_scale(ray.direct,rec.t));
//       rec.normal = vec_scale(vec_op_sub(rec.p,sphere.center),1.0/radius);
//       return (1);
//     }
//   }
//   return (0);
// }
