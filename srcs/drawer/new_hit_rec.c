/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_hit_rec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 05:01:18 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 01:25:28 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_hit_rec   new_hit_rec(double t, t_vec3 p, t_vec3 normal)
{
  t_hit_rec new;

  new.t = t;
  new.p = p;
  new.normal = normal;
  return (new);
}

int ray_intersect(t_sphere sphere, t_ray ray, float *t0)
{
        t_vec3 lbig = vec_op_sub(sphere.center,ray.origin);
        float tca = (float)vec_dot(lbig, ray.direct);
        float d2 = (float)vec_dot(lbig, lbig) - tca*tca;
        if (d2 > sphere.radius*sphere.radius) return FALSE;
        float thc = sqrtf(sphere.radius*sphere.radius - d2);
        *t0 = tca - thc;
        float t1 = tca + thc;
        if (*t0 < 0) *t0 = t1;
        if (*t0 < 0) return FALSE;
        return TRUE;
}

int   scene_intersect(t_sphere *sphere, t_ray ray, t_vec3 *hit, t_vec3 *nbig, t_mater *material)
{
    double spheres_dist = MAX_DIST;
    int   i;
    float dist_i;

    i = -1;
    while (++i < SPHERE_NMB)
    {
        dist_i = 0;
        if (ray_intersect(sphere[i] ,ray, &dist_i) && dist_i < spheres_dist)
        {
            spheres_dist = dist_i;
            *hit = vec_op_add(ray.origin,vec_scale(ray.direct,dist_i));
            *nbig = unit_vector((vec_op_sub(*hit,sphere[i].center)));
            *material = sphere[i].mater;
        }
    }
    return (spheres_dist < 1000);
}
