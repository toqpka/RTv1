/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:41:16 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 06:42:46 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    back_scene2(SDL_Surface		*frame)
{
  int i,j;
  double down = frame->h/100.0;
  double left = frame->w/100.0;
  //printf("down=%lf   left=%lf\n",down,left);
  t_vec3 lower_l = vec_new(-left,-down,-1.0);
  t_vec3 horiz = vec_new(left*2.0, 0.0, 0.0);
  t_vec3 vert = vec_new(0.0, down*2.0, 0.0);
  t_vec3 origin = vec_new(0.0, 0.0, 0.0);
// CREATING lights
  t_light   *lights;
  int       nbrs_lghts = LIGHT_NMB;
  lights = create_null_list_lights(nbrs_lghts);
  if (!(lights))
    ft_print_error_exit(&ft_putendl, "Error, no_lights");

  lights[0] = light_new(vec_new(-20.0,  20.0,  20.0), 1.5);
  lights[1] = light_new(vec_new( 30.0,  50.0, -25.0), 1.4);
  lights[2] = light_new(vec_new( 30.0,  20.0,  30.0), 0.4);
// CREATING Spheres
  t_sphere  *spher;
  int       nbrs_sph = SPHERE_NMB;

  spher = create_null_list_spheres(nbrs_sph);
  if (!(spher))
    ft_print_error_exit(&ft_putendl, "Error, no_spheres");
// CREATING mater
  t_mater   ivory;
  t_mater   red_rubber;
  t_mater   mirror;

  mater_fill(&ivory, MAT_IVORY);
  mater_fill(&red_rubber, MAT_RED_RUBBER);
  mater_fill(&mirror, MAT_MIRROR);
// filling spheres
  spher[0] = sphere_new(vec_new(-3.0,  0.0, -16.0), 2, ivory);
  spher[1] = sphere_new(vec_new(-1.0, -1.5, -12.0), 2, red_rubber);
  spher[2] = sphere_new(vec_new( 1.5, -0.5, -18.0), 3, red_rubber);
  spher[3] = sphere_new(vec_new( 7.0,  5.0, -18.0), 4, ivory);

  size_t	depth = 0;

  i = -1;
  while (++i < frame->h)
  {
    j = -1;
    while (++j < frame->w)
    {
      double x =  (2*(j+0.5)/(double)frame->w - 1)*tan(FOV/2.)*frame->w/(double)frame->h;
      double y = -(2*(i+0.5)/(double)frame->h - 1)*tan(FOV/2.);
      t_vec3 dir = unit_vector(vec_new(x, y, -1));
      t_ray ray = new_ray(origin, dir);
      depth = 0;
      t_vec3 col = cast_ray(ray, spher, lights, depth);
      int r = (int)(255.99*col.x);
      int g = (int)(255.99*col.y);
      int b = (int)(255.99*col.z);
      put_pixel(frame, j, i, pack_color(r,g,b));
    }
  }
  return ;
}
