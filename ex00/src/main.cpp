/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:20:23 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/23 12:14:01 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a;
		Bureaucrat b("Tom",48);
		Bureaucrat c("Pouce",0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "-----------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat d("Pouce",151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "-----------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat FF("Paul",2);
		FF.incrementGrade();
		std::cout << FF << std::endl;
		FF.incrementGrade();
		std::cout << FF << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

		std::cout << "-----------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat FF("Paul",149);
		FF.decrementGrade();
		std::cout << FF << std::endl;
		FF.decrementGrade();
		std::cout << FF << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);

}
