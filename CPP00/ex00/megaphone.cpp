/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:39:17 by vpac              #+#    #+#             */
/*   Updated: 2023/06/02 13:39:18 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc && ++j < argc)
	{
		i = -1;
		while (argc > 1 && argv[j][++i] && argv)
		{
			std::cout << (char)std::toupper(argv[j][i]) ;
		}
	}
	std::cout << std::endl;
	return (0);
}
