/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:01:06 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/19 14:53:20 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_vec	v_diffd(t_vec v1, double n)
{
	t_vec	res;

	res.x = v1.x - n;
	res.y = v1.y - n;
	res.z = v1.z - n;
	return (res);
}

t_vec	v_sumd(t_vec v1, double n)
{
	t_vec	res;

	res.x = v1.x + n;
	res.y = v1.y + n;
	res.z = v1.z + n;
	return (res);
}

t_vec	v_divd(t_vec v1, double n)
{
	t_vec	res;

	res.x = v1.x / n;
	res.y = v1.y / n;
	res.z = v1.z / n;
	return (res);
}

t_vec	v_muld(t_vec v1, double n)
{
	t_vec	res;

	res.x = v1.x * n;
	res.y = v1.y * n;
	res.z = v1.z * n;
	return (res);
}
