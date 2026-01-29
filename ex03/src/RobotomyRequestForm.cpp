#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm () , _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy",72,45) , _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy) , _target(copy._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// AForm:operator=(other);
		this->_target = other._target;
	}
	return *this;
}

const char *RobotomyRequestForm::FormIsNotSignedException::what() const throw()
{
	return "The Form need to be signed for being executed";
}

bool RobotomyRequestForm::execute(Bureaucrat const &executeur) const
{
	if (this->getStatus() == false)
		throw RobotomyRequestForm::FormIsNotSignedException();
	if (this->getRankToExec() <  executeur.getGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << "MAKING SOME DRILL NOISE DRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been succefully Robotomized, he is now a GOLDFISH" << std::endl;
	else
		std::cout << this->_target << "'s mind is so strong, he cannot be Robotomized" << std::endl;
	return (true);

}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor RobotomyRequestForm " << this->getName() << " called" << std::endl;
}
