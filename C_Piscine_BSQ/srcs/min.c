/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:58:51 by naqua             #+#    #+#             */
/*   Updated: 2021/09/07 21:56:49 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int	dia, int left, int right)
{
	int	res;

	if (dia < left)
		res = dia;
	else
		res = left;
	if (right < res)
		res = right;
	return (res + 1);
}
