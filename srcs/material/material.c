/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:16:37 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 04:43:51 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mater   mater_new(void)
{
  t_mater  new_mater;

  new_mater.type_mat = ft_strdup("");
  new_mater.albedo = vec_new(0.0, 0.0, 0.0);
  new_mater.diff_col = vec_new(0.0, 0.0, 0.0);
  new_mater.spec_exp = 0.0;
  return (new_mater);
}

void      mater_fill(t_mater *mat, char *mat_type)
{
  if (!(ft_strcmp(mat_type, MAT_IVORY)))
  {
    mat->type_mat = ft_strdup(MAT_IVORY);
    mat->albedo = vec_new(0.6, 0.3, 0.1);
    mat->diff_col = vec_new(0.4, 0.4, 0.3);
    mat->spec_exp = 50.0;
  }
  if (!(ft_strcmp(mat_type, MAT_RED_RUBBER)))
  {
    mat->type_mat = ft_strdup(MAT_RED_RUBBER);
    mat->albedo = vec_new(0.9, 0.1, 0.0);
    mat->diff_col = vec_new(0.3, 0.1, 0.1);
    mat->spec_exp = 10.0;
  }
  if (!(ft_strcmp(mat_type, MAT_MIRROR)))
  {
    mat->type_mat = ft_strdup(MAT_MIRROR);
    mat->albedo = vec_new(0.0, 10.0, 0.8);
    mat->diff_col = vec_new(1.0, 1.0, 1.0);
    mat->spec_exp = 1425.0;
  }
  if (!(ft_strcmp(mat_type, MAT_METAL)))
  {
    mat->type_mat = ft_strdup(MAT_METAL);
    mat->albedo = vec_new(0.8, 0.6, 0.2);
    mat->diff_col = vec_new(1.0, 1.0, 1.0);
    mat->spec_exp = 20.0;
  }
  if (!(ft_strcmp(mat_type, MAT_LAMBERT)))
  {
    mat->type_mat = ft_strdup(MAT_LAMBERT);
    mat->albedo = vec_new(0.8, 0.3, 0.0);
    mat->diff_col = vec_new(1.0, 1.0, 1.0);
    mat->spec_exp = 100.0;
  }
  return ;
}
