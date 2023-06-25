/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:39:21 by vpac              #+#    #+#             */
/*   Updated: 2023/06/07 17:35:31 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

int	main(void)
{
	std::string	input;
	phonebook	book;

	while (1)
	{
		std::cout << "Valid command: ADD / SEARCH / EXIT\n";
		std::cin >> input;
		if (input == "ADD")
		{
			book.add();
		}
		else if (input == "SEARCH")
		{
			book.search();
		}
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "invalid input\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		if (std::cin.eof())
			return (0);
	}
}
