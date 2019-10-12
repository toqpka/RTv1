/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 04:53:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/10 20:46:03 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
// for sphere
int ray_intersect(t_sphere sphere, t_ray ray, float *t0)
{
  t_vec3 lbig = vec_op_sub(sphere.center, ray.origin);
  float tca = (float)vec_dot(lbig, ray.direct);
  float d2 = (float)vec_dot(lbig, lbig) - tca*tca;
  if (d2 > sphere.radius*sphere.radius) return FALSE;
  float thc = sqrtf(sphere.radius*sphere.radius - d2);
  float t2 = tca - thc;
  float t1 = tca + thc;
  if (t2 < 0) t2 = t1;
  if (t2 < 0) return FALSE;
  *t0 = t2;
  return TRUE;
}

t_sphere    *create_null_list_spheres(int nbr)
{
  t_sphere    *n;
  int   i;

  n = (t_sphere*)malloc(nbr * sizeof(t_sphere));
  if (n == NULL || nbr == 0)
    return (NULL);
  i = -1;
  while(++i < nbr)
  {
    n[i].radius = 0.0;
    n[i].center = vec_new(0.0,0.0,0.0);
    n[i].mater = mater_new();
  }
  return (n);
}

t_sphere    sphere_new(t_vec3 center, double radius, t_mater mater)
{
  t_sphere    new_sphere;

  new_sphere.center = center;
  new_sphere.radius = radius;
  new_sphere.mater = mater;
  return (new_sphere);
}

t_sphere   *exec_sphers(void)
{
  t_sphere   *spheres;
  int       nbrs_sph = 4;

  spheres = create_null_list_spheres(nbrs_sph);
  if (!(spheres))
    ft_print_error_exit(&ft_putendl, "Error, no_spheres");
// CREATING mater
  t_mater   ivory;
  t_mater   red_rubber;
  t_mater   mirror;
  t_mater   metal;
  t_mater   lambertian;

  mater_fill(&ivory, MAT_IVORY);
  mater_fill(&red_rubber, MAT_RED_RUBBER);
  mater_fill(&mirror, MAT_MIRROR);
  mater_fill(&metal, MAT_METAL);
  mater_fill(&lambertian, MAT_LAMBERT);
// filling spheres
  spheres[0] = sphere_new(vec_new(   0,     0, -1), 0.5, lambertian);
  spheres[1] = sphere_new(vec_new(   0,-100.5, -1), 100, lambertian);
  spheres[2] = sphere_new(vec_new( 1,    0, -1), 0.5, metal);
  spheres[3] = sphere_new(vec_new( -1,   0, -1), 0.5, metal);
  return (spheres);
}
