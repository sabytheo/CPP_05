/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:20:23 by tsaby             #+#    #+#             */
/*   Updated: 2026/06/03 12:31:22 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(time(NULL));
	try
	{
		Bureaucrat high("HighRank", 1);
		Bureaucrat low("LowRank", 150);

		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery << std::endl;

		high.executeForm(shrubbery);
		high.signForm(shrubbery);
		high.executeForm(shrubbery);
		low.executeForm(shrubbery);

		std::cout << "---" << std::endl;

		RobotomyRequestForm robotomy("Robot");
		std::cout << robotomy << std::endl;
		std::cout << "---" << std::endl;

		PresidentialPardonForm pardon("Arthur");
		std::cout << pardon << std::endl;

		high.signForm(pardon);
		high.executeForm(pardon);
		low.executeForm(pardon);

		std::cout << "---" << std::endl;

		ShrubberyCreationForm shrubbery2("garden");
		low.signForm(shrubbery2);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
