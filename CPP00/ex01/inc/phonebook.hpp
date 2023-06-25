/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:39:25 by vpac              #+#    #+#             */
/*   Updated: 2023/06/07 17:31:32 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class contact
{
	public:
		std::string	f_name;
		std::string	l_name;
		std::string	nick;
		std::string	phone_nb;
		std::string	secret;
		contact();
		~contact();
};

class phonebook
{
	private:
		contact	contacts[8];
		int		index;
		void	add_contact(int index);
		void	search_contact(int index);
		void	list_contact(int index);
		void	set_empty(int index);
	public:
		phonebook();
		~phonebook();

		void	add();
		void	search();
};

std::string	shorten(std::string str);

#endif
