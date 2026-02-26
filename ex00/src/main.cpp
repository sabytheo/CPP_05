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
	Bureaucrat alice("Alice", 75);
	std::cout << alice << std::endl;

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat dave("Dave", 2);
		dave.incrementGrade();
		std::cout << dave << std::endl;
		dave.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat eve("Eve", 149);
		eve.decrementGrade();
		std::cout << eve << std::endl;
		eve.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
