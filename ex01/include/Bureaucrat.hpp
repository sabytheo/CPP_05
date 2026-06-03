/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:13 by tsaby             #+#    #+#             */
/*   Updated: 2026/06/02 18:58:59 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _rank;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int rank);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw() ;
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		std::string getName() const;
		int getGrade() const;

		void	signForm(Form& other);
		void 	incrementGrade();
		void 	decrementGrade();
};

std::ostream& operator<<(std::ostream& os,const Bureaucrat& other);


#endif
