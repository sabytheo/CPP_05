/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:26 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/29 10:53:53 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
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

void Bureaucrat::signForm(AForm &other)
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

void Bureaucrat::executeForm(AForm const &other) const
{
	if (other.execute(*this) == true)
		std::cout << this->_name << " executed " << other.getName() << std::endl;
	// else if (other.getStatus() == true)
	// 	std::cout << this->_name << " cannot executed" << other.getName() << \
	// 	" because the grade required to exec the form is " << other.getRankToExec() \
	// 	<< "and " << this->_name << "is only rank " << this->_rank << std::endl;
	// else
	// 	std::cout << other.getName() << " need to be signed for being executed" << std::endl;
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
