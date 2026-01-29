/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:20:23 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/29 11:02:13 by tsaby            ###   ########.fr       */
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

	Bureaucrat Paul("Paul",150);
	Bureaucrat Pierre("Pierre",1);
	ShrubberyCreationForm Tree("Tree");
	RobotomyRequestForm Robot("Robot");
	PresidentialPardonForm Pardon("Pardon");

	std::cout << "---------------------------------" << std::endl;

	try
	{

		Pierre.signForm(Tree);
		Pierre.signForm(Robot);
		std::cout << "---------------------------------" << std::endl;

		// Tree.execute(Paul);
		// Tree.execute(Pierre);
		// Robot.execute(Pierre);
		// Pierre.executeForm(Tree);
		Pierre.executeForm(Tree);
		Pierre.executeForm(Robot);
		Pierre.executeForm(Pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "---------------------------------" << std::endl;

	return (0);

}
