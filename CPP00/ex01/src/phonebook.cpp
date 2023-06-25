/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:10:01 by vpac              #+#    #+#             */
/*   Updated: 2023/06/07 17:44:08 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"
# include <string>
# include <iomanip>

void	phonebook::add_contact(int index)
{
	contact &person = contacts[index];

	std::cout << "Input first name:\n";
	std::cin >> person.f_name;
	std::cout << "Input last name:\n";
	std::cin >> person.l_name;
	std::cout << "Input nickname:\n";
	std::cin >> person.nick;
	std::cout << "Input phone number:\n";
	std::cin >> person.phone_nb;
	std::cout << "Input darkest secret:\n";
	std::cin >> person.secret;
}

void	phonebook::list_contact(int index)
{
	contact &person = contacts[index];

	std::cout << std::setw(10) << index + 1 << '|';
	std::cout << std::setw(10) << shorten(person.f_name) << '|';
	std::cout << std::setw(10) << shorten(person.l_name) << '|';
	std::cout << std::setw(10) << shorten(person.nick) << "|\n";
}

void	phonebook::search_contact(int index)
{
	contact &person = contacts[index];

	if (person.f_name.empty())
	{
		std::cout << "Contact index empty\n";
		return ;
	}
	std::cout << "first name: " << person.f_name << std::endl;
	std::cout << "last name: " << person.l_name << std::endl;
	std::cout << "nickname: " << person.nick << std::endl;
	std::cout << "number: " << person.phone_nb << std::endl;
	std::cout << "secret: " << person.secret << std::endl;
}

void	phonebook::add(void)
{
	if (index == 8)
	{
		for (int i = 1; i < 8; i++)
			contacts[i - 1] = contacts[i];
		index--;
	}
	add_contact(index++);
}

void	phonebook::search(void)
{
	int	index_t;

	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << "|\n";
	for (int i = 0; i < 8; i++)
		list_contact(i);
	std::cout << "Input the index of the person you are searching:\n";
	std::cin >> index_t;
	if (index_t > 8 || index_t < 1)
	{
		std::cout << "Out of range\n";
		return ;
	}
	index_t--;
	if (index == 0)
		std::cout << "phonebook empty\n";
	else if (index_t <= index && index_t >= 0)
		search_contact(index_t);
}
