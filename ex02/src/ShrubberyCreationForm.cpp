#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm () , _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery",145,137) , _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy) , _target(copy._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// AForm:operator=(other);
		this->_target = other._target;
	}
	return *this;
}

const char *ShrubberyCreationForm::FormIsNotSignedException::what() const throw()
{
	return "The Form need to be signed for being executed";
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executeur) const
{
	if (this->getStatus() == false)
		throw ShrubberyCreationForm::FormIsNotSignedException();
	if (this->getRankToExec() <  executeur.getGrade())
		throw Bureaucrat::GradeTooLowException();

	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if(outfile.fail())
	{
		std::cout << "Error for creating outfile" << std::endl;
		return (false);
	}

	outfile << "               ,@@@@@@@," << std::endl;
	outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outfile << "       |o|        | |         | |" << std::endl;
	outfile << "       |.|        | |         | |" << std::endl;
	outfile << "       |.|        | |         | |" << std::endl;
	outfile << "       |.|        | |         | |" << std::endl;
	outfile << "       |.|        | |         | |" << std::endl;
	outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

	return (true);

}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor ShrubberyCreationForm " << this->getName() << " called" << std::endl;
}
