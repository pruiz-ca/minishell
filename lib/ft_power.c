/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqs <raqs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 02:12:22 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/05/12 21:00:28 by raqs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double num, double pow)
{
	double		result;

	result = 1;
	while (pow-- > 0)
		result *= num;
	return (result);
}
