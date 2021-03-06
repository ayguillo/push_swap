/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:05:08 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 13:29:45 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int n, int pow)
{
	int res;

	res = n;
	if (pow < 0 || n == 0)
		return (0);
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (n);
	while (pow > 1)
	{
		res = res * n;
		pow--;
	}
	return (res);
}
