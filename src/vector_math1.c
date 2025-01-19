/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:01:01 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/19 14:53:20 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_vec	v_diff(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vec	v_sum(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec	v_div(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x / v2.x;
	res.y = v1.y / v2.y;
	res.z = v1.z / v2.z;
	return (res);
}

t_vec	v_mul(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x * v2.x;
	res.y = v1.y * v2.y;
	res.z = v1.z * v2.z;
	return (res);
}
