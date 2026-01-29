/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:26 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/26 15:52:04 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _rank(150)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, size_t rank) : _name(name)
{
	if (rank < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (rank > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_rank = rank;
	std::cout << "Bureaucrat " << name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rank = copy._rank;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_rank = other._rank;
	}
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Rank's windows is [1,150]";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Rank's windows is [1,150]";
}

void Bureaucrat::incrementGrade()
{
	if (this->_rank == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_rank -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->_rank == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_rank += 1;
}

void Bureaucrat::signForm(Form &other)
{
	try
	{
		other.beSigned(*this);
		std::cout << this->getName() << " signs " << other.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " cannot sign " << other.getName()
				  << " because " << e.what() << '\n';
	}
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

size_t Bureaucrat::getGrade() const
{
	return (_rank);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor Bureaucrat " << this->_name << " called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrate grade " << other.getGrade() << ".";
	return os;
}
