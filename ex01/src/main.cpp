/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:20:23 by tsaby             #+#    #+#             */
/*   Updated: 2026/01/26 16:39:48 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat FF("Paul",150);
	Bureaucrat FG("Paul1",1);
	Form Fb("nana",30,30);

	FG.signForm(Fb);
	FF.signForm(Fb);

	return (0);

}
