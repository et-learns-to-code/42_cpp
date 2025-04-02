/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:33:59 by etien             #+#    #+#             */
/*   Updated: 2025/04/02 12:52:55 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
	public:
		// OCF
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm *makeForm(const std::string &form, const std::string &target);

	private:
		// static factory helper functions for makeForm
		static AForm *makeShrubberyCreationForm(const std::string &target);
		static AForm *makeRobotomyRequestForm(const std::string &target);
		static AForm *makePresidentialPardonForm(const std::string &target);
};

#endif
