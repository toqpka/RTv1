/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:58:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/08 03:38:23 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light    *create_null_list_lights(int nbr)
{
  t_light    *n;
  int   i;

  n = (t_light*)malloc(nbr * sizeof(t_light));
  if (n == NULL || nbr == 0)
    return (NULL);
  i = -1;
  while(++i < nbr)
  {
    n[i].intens = 0.0;
    n[i].pos = vec_new(0.0,0.0,0.0);
  }
  return (n);
}

t_light     light_new(t_vec3 pos, double intens)
{
  t_light    new_light;

  new_light.intens = intens;
  new_light.pos = pos;
  return (new_light);
}

// t_vec3      reflect(t_vec3 v, t_vec3 n)
// {
//   return (vec_op_sub(v,vec_scale(n,2.0*vec_dot(v,n))));
// }


t_vec3      reflect(t_vec3 i, t_vec3 n)
{
  t_vec3 righ = vec_scale(vec_scale(n,2.f),vec_dot(i,n));
  return (vec_op_sub(i,righ));
}

// t_vec3 reflect(const t_vec3 i, const t_vec3 n)
// {
//     t_vec3  ref = vec_scale(n,2.f);
//     return (vec_op_sub(i,vec_scale(ref,vec_dot(i,n))));
// }


//  strange  but  work (reverse)
// t_vec3      reflect(t_vec3 r, t_vec3 n)
// {
//  return (vec_op_sub(vec_scale(n,2.0*vec_dot(n,r)),r));
// }

t_light   *exec_lights(void)
{
  t_light   *lights;
  int       nbrs_lghts = LIGHT_NMB;
  lights = create_null_list_lights(nbrs_lghts);
  if (!(lights))
    ft_print_error_exit(&ft_putendl, "Error, no_lights");

  lights[0] = light_new(vec_new(-20.0,  20.0,  20.0), 1.5);
  lights[1] = light_new(vec_new( 30.0,  50.0, -25.0), 1.7);
  lights[2] = light_new(vec_new( 30.0,  20.0,  30.0), 1.8);
  return (lights);
}
