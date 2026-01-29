/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:13 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/26 16:22:39 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool	_isSigned;
		const size_t _rankNeededToSign;
		const size_t _rankNeededToExec;
	public:
		AForm();
		AForm(const std::string& name, const size_t _rankNeededToSign , const size_t _rankNeededToExec);
		AForm(const AForm &copy);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw() ;
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class isAlreadySign : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		std::string getName() const;
		size_t getGrade() const;
		size_t getRankToSign() const;
		size_t getRankToExec() const;
		bool beSigned(Bureaucrat& other);
		virtual bool execute(Bureaucrat const & executor) const = 0;
		bool	getStatus() const;

};

std::ostream& operator<<(std::ostream& os,const AForm& other);


#endif
