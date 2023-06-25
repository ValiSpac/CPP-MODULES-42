/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:59:40 by vpac              #+#    #+#             */
/*   Updated: 2023/06/07 17:42:41 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "phonebook.hpp"

contact::contact(){}

contact::~contact(){}

phonebook::phonebook()
{
	index = 0;
}

phonebook::~phonebook(){}

std::string	shorten(std::string str)
{
	std::string	temp;

	if (str.length() >= 10)
	{
		temp = str.substr(0, 9);
		temp += ".";
	}
	else
		temp = str;
	return (temp);
}
