/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:26 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/29 10:53:53 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{

	}
	return *this;
}

static AForm *makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string existingForm[] = {"presidential pardon", "shrubbery creation", "robotomy request"};
	AForm*(*func[])(std::string)= {&makePresidential,&makeShrubbery,&makeRobotomy};

	for(int i = 0; i < 3; i++)
	{
		if(existingForm[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return func[i](target);
		}
	}

	std::cout << name << " doesn't match any existing form" << std::endl;
	return NULL;
}
Intern::~Intern(void)
{
	std::cout << "Destructor Intern called" << std::endl;
}
