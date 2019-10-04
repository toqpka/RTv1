/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 04:31:37 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 02:24:02 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint8_t   hitable_list(t_ray ray, double t_min, double t_max, t_hit_rec *rec, t_sphere *world)
{
  t_hit_rec   temp_rec = new_hit_rec(0.0, vec_new(0.0, 0.0, 0.0),vec_new(0.0, 0.0, 0.0));
  uint8_t     hit_anything = FALSE;
  double      closest_so_far = t_max;
  int         i;

  i = -1;
  while (++i < SPHERE_NMB)
  {
    if (hitable(world[i],ray,t_min,closest_so_far,&temp_rec))    
    {
      hit_anything = TRUE;
      closest_so_far = temp_rec.t;
      *rec = temp_rec;
    }
  }
  return (hit_anything);
}
