/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:31:46 by etien             #+#    #+#             */
/*   Updated: 2025/03/31 15:17:04 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		// OCF
		AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		// custom constructor
		AForm(std::string name, int gradeToSign, int gradeToExecute);

		// getters
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);

		void execute(Bureaucrat const & executor) const;
		virtual void beExecuted() const = 0;

		// exception classes are typically nested classes
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &aform);

#endif
