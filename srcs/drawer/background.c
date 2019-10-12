/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:53:17 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/08 00:53:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3  random_in_unit_sphere(void)
{
  t_vec3  p = vec_new(1,1,1);
  while (vec_squared_len(p) >= 1.0)
  {
    p = vec_op_sub(vec_scale(vec_new(drand48(),drand48(),drand48()),2.0), vec_new(1,1,1));
  }
  return (p);
}

int ft_scatter(t_mater *mater,t_ray ray, t_hit_rec *rec, t_vec3 *atten, t_ray *scatter)
{
  if (mater->type_mat == MAT_LAMBERT)
  {
    t_vec3 target = vec_op_add(vec_op_add((*rec).p, (*rec).normal),random_in_unit_sphere());
    *scatter = new_ray((*rec).p, vec_op_sub(target,(*rec).p));
    *atten = mater->albedo;
    return (TRUE);
  }
  if (mater->type_mat == MAT_METAL)
  {
    t_vec3 reflected = reflect(unit_vector(ray.direct),(*rec).normal);
    *scatter = new_ray((*rec).p, reflected);
    *atten = mater->albedo;
    return (vec_dot((*scatter).direct,(*rec).normal) > 0);
  }
  return (0);
}

t_vec3 ray_color(t_ray ray, t_sphere *world, int depth)
{
  double t;
   //t= hit_sphere(vec_new(0,0,-1),0.9,ray);
  t_hit_rec   rec;
  if (hitable_list(ray, 0.001, MAXFLOAT, &rec, world))
  {
    t_vec3 target = vec_op_add(vec_op_add(rec.p,rec.normal),random_in_unit_sphere());
    t_vec3  atten;
    t_ray   scatter;
    return (vec_scale(ray_color(new_ray(rec.p,vec_op_sub(target,rec.p)),world,1),0.5));

    // if (depth < 50 || ft_scatter(rec.mat_ptr,ray,&rec,&atten,&scatter))
    // {
    //   return (vec_op_mult(atten, ray_color(scatter, world, depth+1)));
    // }
    // else
    //   return (vec_new(0,0,0));
  }
  else
  {
    t_vec3 unit_direct = unit_vector(ray.direct);
    t = 0.5*(unit_direct.y + 1.0);
    t_vec3 a = vec_scale(vec_new(1.0, 1.0, 1.0), 1.0-t);
    t_vec3 b = vec_scale(vec_new(0.5, 0.7, 1.0), t);
    return (vec_op_add(a,b));
  }
}





void    backgr(SDL_Surface		*frame)
{
  int i,j;

  t_cam cam;
  cam = exec_cam(frame->w,frame->h);

  // CREATING lights
  t_light   *lights;
  lights = exec_lights();
  // CREATING Spheres
  t_sphere  *spher;
  spher = exec_sphers();

  t_sphere *world;
  world = spher;

//smoothing  ok if 100  (slow load 30 sec)
int   ns = 40;
int   s;
  i = -1;
  while (++i < frame->h)
  {
    j = -1;
    while (++j < frame->w)
    {
      t_vec3  col = vec_new(0,0,0);
      s = -1;
      while (++s < ns)
      {
        double hor = (double)(j + drand48())/(double)(frame->w); //u
        double ver = (double)(i + drand48())/(double)(frame->h); //v
        t_ray ray = get_ray(cam, hor, ver);
        t_vec3  p = vec_op_add(ray.origin,vec_scale(ray.direct,2.0f));
        col = vec_op_add(col,ray_color(ray, world, 0));
      }

      col = vec_scale(col,1.0/ns);
      col = vec_new(sqrt(col.x),sqrt(col.y),sqrt(col.z));
      int r = (int)(255.99*col.x);
      int g = (int)(255.99*col.y);
      int b = (int)(255.99*col.z);
      put_pixel(frame, j, i, pack_color(r,g,b));
    }
  }
  return ;
}
