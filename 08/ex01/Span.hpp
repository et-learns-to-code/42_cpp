/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:37 by etien             #+#    #+#             */
/*   Updated: 2025/04/15 18:52:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

class Span
{
	private:
		std::set<int> _set;

	public:
		// OCF
		Span();
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

};

#endif
