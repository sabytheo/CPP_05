/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:20:23 by tsaby             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/02 15:46:44 by tsaby            ###   ########.fr       */
=======
/*   Updated: 2026/06/02 18:26:32 by tsaby            ###   ########.fr       */
>>>>>>> 6740ea314ac4d3c760c6f7d239d0446d14e8513b
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
