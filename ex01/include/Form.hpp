/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:13 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/26 16:22:39 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool	_isSigned;
		const size_t _rankNeededToSign;
		const size_t _rankNeededToExec;
	public:
		Form();
		Form(const std::string& name, const size_t _rankNeededToSign , const size_t _rankNeededToExec);
		Form(const Form &copy);
		Form& operator=(const Form& other);
		~Form();

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
		bool	getStatus() const;

};

std::ostream& operator<<(std::ostream& os,const Form& other);


#endif
