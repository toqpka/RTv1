/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 03:19:39 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/04 03:30:29 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam   cam_init(t_vec3 lower_l, t_vec3 horiz, t_vec3 vert, t_vec3 origin)
{
  t_cam    new_cam;

  new_cam.lower_l = lower_l;
  new_cam.horiz = horiz;
  new_cam.vert = vert;
  new_cam.origin = origin;
  return (new_cam);
}

t_cam   exec_cam(int wid, int height)
{
  t_cam cam;

  double down = height/100.0;
  double left = wid/100.0;

  cam.lower_l = vec_new(-left,-down, -1.0);
  cam.horiz = vec_new(left*2.0, 0.0, 0.0);
  cam.vert = vec_new(0.0, down*2.0, 0.0);
  cam.origin = vec_new(0.0, 0.0, 0.0);
  return (cam);
}
