/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:54:51 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 13:07:22 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int   scene_intersect(t_plane plane, t_sphere *sphere, t_ray ray, t_vec3 *hit, t_vec3 *nbig, t_mater *material)
{
    double spheres_dist = MAX_DIST;
    int   i;
    float dist_i;

    i = -1;
    // while (++i < PLANE_NMB)
    double plane_dist = MAX_DIST;
    while (++i < 1)
    {
      dist_i = 0;
      //if (dist_i>0 && fabs(pt.x)<10 && pt.z<-10 && pt.z>-30 && d<spheres_dist)
      if (ray_intersect_plane(plane ,ray, &dist_i) && dist_i < plane_dist)
      {
        plane_dist = dist_i;
        *nbig = plane.norm;
        *hit = vec_op_add(ray.origin,vec_scale(ray.direct,dist_i));
        //*material = plane.mater;
        //(*material).albedo = ((int)(.5*(*hit).x+10000) + (int)(.5*(*hit).z)) & 1 ? vec_new(.3, .3, .3) : vec_new(.3, .2, .1);
        (*material).spec_exp = 5.;
        //(*material).diff_col = vec_new(1,1,1);

        // mat->albedo = vec_new(0.9, 0.1, 0.0);
        // mat->diff_col = vec_new(0.3, 0.1, 0.1);
        // mat->spec_exp = 10.0;

        (*material).albedo = vec_new(0.1,0.1,0.4);
        (*material).diff_col = ((int)(.5*(*hit).x+1000) + (int)(.5*(*hit).z)) & 1 ? vec_new(.3, .3, .3) : vec_new(.0, .0, .0);
      }
    }

    i = -1;
    while (++i < SPHERE_NMB)  // max items (figue)
    //while (++i < 1)  // max items (figue)
    {
        dist_i = 0;
        if (ray_intersect(sphere[i] ,ray, &dist_i) && dist_i < spheres_dist)
        {
            spheres_dist = dist_i;
            *hit = vec_op_add(ray.origin, vec_scale(ray.direct,dist_i));
            *nbig = unit_vector((vec_op_sub(*hit, sphere[i].center)));
            *material = sphere[i].mater;
        }
    }

    return (fmin(spheres_dist,plane_dist) < MAX_DIST);
    //return (fmin(spheres_dist,plane_dist) < MAX_DIST);
}
