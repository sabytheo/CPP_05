/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:20:23 by tsaby             #+#    #+#             */
/*   Updated: 2026/06/02 17:52:22 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::srand(time(NULL));

	Intern intern;
	try
	{
		Bureaucrat boss("Boss", 1);
		AForm *rrf = intern.makeForm("robotomy request", "Bender");
		AForm *scf = intern.makeForm("shrubbery creation", "home");
		AForm *ppf = intern.makeForm("presidential pardon", "Arthur");
		AForm *bad = intern.makeForm("coffee request", "me");

		std::cout << "---" << std::endl;

		boss.signForm(*rrf);
		boss.executeForm(*rrf);

		std::cout << "---" << std::endl;

		boss.signForm(*scf);
		boss.executeForm(*scf);

		std::cout << "---" << std::endl;

		boss.signForm(*ppf);
		boss.executeForm(*ppf);

		delete rrf;
		delete scf;
		delete ppf;
		delete bad;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
