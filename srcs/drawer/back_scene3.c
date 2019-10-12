/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_scene3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 01:24:59 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/05 02:46:13 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vec3 color_scene3(t_ray r, t_sphere *world ,int depth)
{
  double t;
   //t= hit_sphere(vec_new(0,0,-1),0.9,ray);
  t_hit_rec   rec;
  if (hitable_list(r, 0.0000001, MAXFLOAT, &rec, world))
  {
    t_vec3 target = vec_op_add(vec_op_add(rec.p,rec.normal),random_in_unit_sphere());
    t_vec3  atten;
    t_ray   scatter;
    //return (vec_scale(ray_color(new_ray(rec.p,vec_op_sub(target,rec.p)),world,1),0.5));
    int check_scatt = ft_scatter(rec.mat_ptr,r,&rec,&atten,&scatter);
    if (check_scatt || depth < 50)
    {
      return (vec_op_mult(atten, ray_color(scatter, world, depth+1)));
    }
    else
      return (vec_new(0,0,0));
  }
  else
  {
    t_vec3 unit_direct = unit_vector(r.direct);
    t = 0.5*(unit_direct.y + 1.0);
    t_vec3 a = vec_scale(vec_new(1.0, 1.0, 1.0), 1.0-t);
    t_vec3 b = vec_scale(vec_new(0.5, 0.7, 1.0), t);
    return (vec_op_add(a,b));
  }
}

void    back_scene3(SDL_Surface		*frame)
{
  t_cam cam = exec_cam(frame->w, frame->h);

  // CREATING Spheres
    t_sphere  *spher;
    int       nbrs_sph = 4;

    spher = create_null_list_spheres(nbrs_sph);
    if (!(spher))
      ft_print_error_exit(&ft_putendl, "Error, no_spheres");
  // CREATING mater
    t_mater   ivory;
    t_mater   red_rubber;
    t_mater   mirror;
    t_mater   metal;
    t_mater   lamber;

    mater_fill(&ivory, MAT_IVORY);
    mater_fill(&red_rubber, MAT_RED_RUBBER);
    mater_fill(&mirror, MAT_MIRROR);
    mater_fill(&metal, MAT_METAL);
    mater_fill(&lamber, MAT_LAMBERT);
  // filling spheres
    spher[0] = sphere_new(vec_new(0.0,  0.0, -1.0), 0.5, lamber);
    spher[1] = sphere_new(vec_new(0.0, -100.5, -1.0), 100, lamber);
    spher[2] = sphere_new(vec_new( 1, 0, -1), 0.5, metal);
    spher[3] = sphere_new(vec_new( -1,  0, -1), 0.5, metal);

  int i,j;
  int   ns = 40;
  j = -1;
  while (++j < frame->h)
  {
    i = -1;
    while (++i < frame->w)
    {
      t_vec3 col = vec_new(0,0,0);
      int s = -1;
      while (++s < ns)
      {
        double u = (float)(i + drand48()) / (float)frame->w;
        double v = (float)(j + drand48()) / (float)frame->h;
        t_ray ray = cam_get_ray(cam, u , v);
        col = vec_op_add(col,color_scene3(ray,spher,0));
      }
      col = vec_scale(col,1.0/ns);
      col = vec_new(sqrt(col.x),sqrt(col.y),sqrt(col.z));
      int r = (int)(255.99*col.x);
      int g = (int)(255.99*col.y);
      int b = (int)(255.99*col.z);
      put_pixel(frame, i, j, pack_color(r,g,b));
    }
  }
  return ;
}
