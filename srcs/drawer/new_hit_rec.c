/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_hit_rec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 05:01:18 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 19:24:48 by gwaymar-         ###   ########.fr       */
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
