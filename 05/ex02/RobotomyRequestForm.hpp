/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:42:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/01 12:26:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		// OCF
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		// custom constructor
		RobotomyRequestForm(std::string target);

		// getter
		std::string getTarget() const;

		void beExecuted() const;
};

#endif
