/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 05:28:28 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 07:20:00 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double    vec_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double    vec_squared_len(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3    vec_norm(t_vec3 v)
{
	return (vec_scale(v, 1.0f/vec_length(v)));
}
