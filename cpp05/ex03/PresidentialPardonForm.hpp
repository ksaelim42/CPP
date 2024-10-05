#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
    private:
        std::string	_target;

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const& r);
        PresidentialPardonForm&	operator=(PresidentialPardonForm const& r);
        ~PresidentialPardonForm();

        void	execute(Bureaucrat const& executor) const;
};

#endif