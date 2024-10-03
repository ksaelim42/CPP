#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string     _target;

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const& r);
        ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& r);
        ~ShrubberyCreationForm();

        void    execute();
};

#endif