/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:55:13 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/10 17:29:19 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void  fill_all_obj(t_obj  *all_obj)
{
  t_sphere    new_sphere;
  char  *str="hello";
  t_mater   ivory;
  mater_fill(&ivory, MAT_IVORY);
// filling spheres
  new_sphere = sphere_new(vec_new(-3.0,  0.0, -16.0), 2, ivory);


  all_obj = (t_obj *)malloc(sizeof(t_obj));
  // all_obj->type = ft_memalloc(6);
  // ft_memcpy(all_obj->type,str,6);

  // all_obj->type = ft_memalloc(sizeof(t_sphere));
  // ft_memcpy(all_obj->type,&new_sphere,sizeof(t_sphere));
  all_obj->type = &new_sphere;
  all_obj->c_type = "sphere";
  if (!(ft_strcmp(all_obj->c_type,"sphere")))
  {
    t_sphere    custom_obj;
    ft_memcpy(&custom_obj,all_obj->type,sizeof(t_sphere));
    printf("!!=%f \n",custom_obj.radius);
  }
  return ;
}

// t_sphere    *create_null_list_spheres(int nbr)
// {
//   t_sphere    *n;
//   int   i;
//
//   n = (t_sphere*)malloc(nbr * sizeof(t_sphere));
//   if (n == NULL || nbr == 0)
//     return (NULL);
//   i = -1;
//   while(++i < nbr)
//   {
//     n[i].radius = 0.0;
//     n[i].center = vec_new(0.0,0.0,0.0);
//     n[i].mater = mater_new();
//   }
//   return (n);
// }
//
//
// t_sphere   *exec_sphers(void)
// {
//   t_sphere   *spheres;
//   int       nbrs_sph = 4;
//
//   spheres = create_null_list_spheres(nbrs_sph);
//   if (!(spheres))
//     ft_print_error_exit(&ft_putendl, "Error, no_spheres");
// // CREATING mater
//   t_mater   ivory;
//
//   mater_fill(&ivory, MAT_IVORY);
// // filling spheres
//   spheres[0] = sphere_new(vec_new(   0,     0, -1), 0.5, lambertian);
//   spheres[1] = sphere_new(vec_new(   0,-100.5, -1), 100, lambertian);
//   spheres[2] = sphere_new(vec_new( 1,    0, -1), 0.5, metal);
//   spheres[3] = sphere_new(vec_new( -1,   0, -1), 0.5, metal);
//   return (spheres);
// }
