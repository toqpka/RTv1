/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:41:16 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 13:01:46 by gwaymar-         ###   ########.fr       */
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

  //SDL_Surface *env_map = IMG_Load( "textures/envmap.jpg" );
  SDL_Surface *env_map = IMG_Load( "textures/london_cityscape_515132.jpg" );
  //SDL_Surface *env_map = IMG_Load( "textures/pont_de_bir_hakeim_565362.jpg" );

  t_light   *lights;
  int       nbrs_lghts = LIGHT_NMB;
  lights = create_null_list_lights(nbrs_lghts);
  if (!(lights))
    ft_print_error_exit(&ft_putendl, "Error, no_lights");

  lights[0] = light_new(vec_new(-200.0,  200.0,  200.0), 2.5);
  //lights[0] = light_new(vec_new( 0.0,  -140.0,  0.0), 1.5);
  lights[1] = light_new(vec_new( 300.0,  500.0, -250.0), 2);
  lights[2] = light_new(vec_new( 300.0,  200.0,  300.0), 2);
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
  spher[0] = sphere_new(vec_new( 0.0,  0.0, -10.0), 3, mirror);
  spher[1] = sphere_new(vec_new(-7.0, 0.0, -10.0), 3, ivory);
  spher[2] = sphere_new(vec_new( 7.0, 0.0, -10.0), 3, red_rubber);
  spher[3] = sphere_new(vec_new( 7.0,  5.0, -18.0), 4, mirror);

  size_t	depth = 0;

  t_obj   all_obj;

  fill_all_obj(&all_obj);

  i = -1;
  while (++i < frame->h)
  {
    j = -1;
    while (++j < frame->w)
    {
      //double x =  (2*(j+0.5)/(double)frame->w - 1)*tan(FOV/2.)*frame->w/(double)frame->h;
      //double y = -(2*(i+0.5)/(double)frame->h - 1)*tan(FOV/2.);
      //t_vec3 dir = unit_vector(vec_new(x, y, -1));
      t_vec3 dir = vec_new(0, 0, 0);
      dir.x =  (j + 0.5) - frame->w/2.0;
      dir.y = -(i + 0.5) + frame->h/2.0;
      dir.z = -(frame->h)/(2.f*tan(FOV/2.f));

      t_ray ray = new_ray(origin, unit_vector(dir));
      depth = 0;
      t_vec3 col = cast_ray(ray, spher, lights, depth, env_map);

      float max_f = fmax(col.x,(fmax(col.y,col.z)));
      if (max_f > 1) col = vec_scale(col,1.f/max_f);
      int r = (int)(255.99*fmax(0.f, fmin(1.f, col.x)));
      int g = (int)(255.99*fmax(0.f, fmin(1.f, col.y)));
      int b = (int)(255.99*fmax(0.f, fmin(1.f, col.z)));
      put_pixel(frame, j, i, pack_color(r,g,b));
    }
  }
  return ;
}
