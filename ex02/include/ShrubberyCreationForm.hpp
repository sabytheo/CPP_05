#ifndef SCHRUBBERYCREATIONFORM_HPP
#define SCHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		class FormIsNotSignedException : public std::exception {
			public:
				virtual const char * what() const throw() ;
		};

		bool execute(Bureaucrat const & executor) const;
};

#endif

