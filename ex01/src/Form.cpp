/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:26 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/23 12:14:31 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default") , _isSigned(false), _rankNeededToSign(150) , _rankNeededToExec(150)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string& name, const int rankNeededToSign , const int rankNeededToExec): \
_name(name) , _isSigned(false) ,  _rankNeededToSign(rankNeededToSign), _rankNeededToExec(rankNeededToExec)
{
	if (rankNeededToSign < 1 || rankNeededToExec < 1 )
		throw Form::GradeTooHighException() ;
	else if (rankNeededToSign > 150 || rankNeededToExec > 150)
		throw Form::GradeTooLowException() ;
	std::cout << "Form " << name << " constructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name) , _rankNeededToSign(copy._rankNeededToSign) , _rankNeededToExec(copy._rankNeededToExec)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_isSigned = copy._isSigned;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}


const char* Form::isAlreadySign::what() const throw()
{
	return "The form is already Sign by someone";
}

std::string Form::getName() const
{
	return(this->_name);
}

int Form::getRankToExec() const
{
	return (this->_rankNeededToExec);
}

int Form::getRankToSign() const
{
	return (this->_rankNeededToSign);
}

bool Form::getStatus() const
{
	return(this->_isSigned);
}

bool Form::beSigned(Bureaucrat& other)
{
	std::cout << "Grade of Signer " << other.getGrade() << std::endl;
	std::cout << "Rank for Signing form " << this->_rankNeededToSign << std::endl;
	if (this->_isSigned == true)
		throw Form::isAlreadySign();
	else if (this->_rankNeededToSign < other.getGrade())
		throw Form::GradeTooLowException();
	else
	{
		this->_isSigned = true;
		return (true);
	}
}

Form::~Form(void)
{
	std::cout << "Destructor Form " << this->_name << " called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
	os << other.getName() << ", Form. His status of sign is " << other.getStatus() << " their grade for sign and exec are in respect order " << other.getRankToSign() << " , " << other.getRankToExec();
	return os;
}
