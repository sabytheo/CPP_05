#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm () , _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Pardon",25,5) , _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy) , _target(copy._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// AForm:operator=(other);
		this->_target = other._target;
	}
	return *this;
}

const char *PresidentialPardonForm::FormIsNotSignedException::what() const throw()
{
	return "The Form need to be signed for being executed";
}

bool PresidentialPardonForm::execute(Bureaucrat const &executeur) const
{
	if (this->getStatus() == false)
		throw PresidentialPardonForm::FormIsNotSignedException();
	if (this->getRankToExec() <  executeur.getGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << this->_target <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (true);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor PresidentialPardonForm " << this->getName() << " called" << std::endl;
}
