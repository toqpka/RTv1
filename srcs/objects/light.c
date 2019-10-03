/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:58:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/03 23:36:11 by gwaymar-         ###   ########.fr       */
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

t_light    light_new(t_vec3 pos, double intens)
{
  t_light    new_light;

  new_light.intens = intens;
  new_light.pos = pos;
  return (new_light);
}

t_vec3    reflect(t_vec3 a, t_vec3 b)
{
  return (vec_op_sub(a,vec_scale(vec_scale(b,2.0f),vec_dot(a,b))));
}
