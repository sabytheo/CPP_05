/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:20:23 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/26 16:39:48 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form badHigh("BadHigh", 0, 10);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form badLow("BadLow", 151, 10);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Form taxForm("TaxForm", 50, 25);
	std::cout << taxForm << std::endl;

	Bureaucrat highRank("HighRank", 1);
	Bureaucrat lowRank("LowRank", 150);

	highRank.signForm(taxForm);
	std::cout << taxForm << std::endl;

	lowRank.signForm(taxForm);

	Form permitForm("PermitForm", 10, 5);
	lowRank.signForm(permitForm);

	return (0);
}
