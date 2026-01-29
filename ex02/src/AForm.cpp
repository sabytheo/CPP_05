/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:26 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/23 12:14:31 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default") , _isSigned(false), _rankNeededToSign(150) , _rankNeededToExec(150)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const size_t rankNeededToSign , const size_t rankNeededToExec): \
_name(name) , _isSigned(false) ,  _rankNeededToSign(rankNeededToSign), _rankNeededToExec(rankNeededToExec)
{
	if (rankNeededToSign < 1 || rankNeededToExec < 1 )
		throw AForm::GradeTooHighException() ;
	else if (rankNeededToSign > 150 || rankNeededToExec > 150)
		throw AForm::GradeTooLowException() ;
	std::cout << "AForm " << name << " constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name) , _rankNeededToSign(copy._rankNeededToSign) , _rankNeededToExec(copy._rankNeededToExec)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_isSigned = copy._isSigned;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}


const char* AForm::isAlreadySign::what() const throw()
{
	return "The Aform is already Sign by someone";
}

std::string AForm::getName() const
{
	return(_name);
}

size_t AForm::getRankToExec() const
{
	return (_rankNeededToExec);
}

size_t AForm::getRankToSign() const
{
	return (_rankNeededToSign);
}

bool AForm::getStatus() const
{
	return(_isSigned);
}

bool AForm::beSigned(Bureaucrat& other)
{
	std::cout << "Grade of Signer " << other.getGrade() << std::endl;
	std::cout << "Rank for Signing " << this->_name << " is " << this->_rankNeededToSign << std::endl;
	if (this->_isSigned == true)
		throw AForm::isAlreadySign();
	else if (this->_rankNeededToSign < other.getGrade())
		throw AForm::GradeTooLowException();
	else
	{
		this->_isSigned = true;
		return (true);
	}
}

AForm::~AForm(void)
{
	std::cout << "Destructor AForm " << this->_name << " called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
	os << other.getName() << ", AForm. His status of sign is " << other.getStatus() << " their grade for sign and exec are in respect order " << other.getRankToSign() << " , " << other.getRankToExec();
	return os;
}
