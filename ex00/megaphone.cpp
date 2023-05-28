/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:43:48 by ymehlil           #+#    #+#             */
/*   Updated: 2023/05/26 01:00:10 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i = 1;
	int j = 0;
	
	if (ac != 1)
	{
		while (av[i])
		{
			j = 0;
			while(av[i][j])
			{
				av[i][j] = std::toupper(av[i][j]);
				j++;
			}
			std::cout << av[i];
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
