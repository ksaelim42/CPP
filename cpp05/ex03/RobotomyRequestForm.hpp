#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <time.h>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string	_target;

    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const& r);
        RobotomyRequestForm&	operator=(RobotomyRequestForm const& r);
        ~RobotomyRequestForm();

        void	execute(Bureaucrat const& executor) const;
};

#endif