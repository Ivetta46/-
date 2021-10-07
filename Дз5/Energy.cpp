#include <iostream>
#include <string>
#include <iomanip>

#include "Energy.hpp"

void Energy::J_to_erg()
{
	m_erg = m_J *c_J_erg;
}

void Energy::J_to_eV()
{
	m_eV = m_J *c_J_eV;
}

void Energy::eV_to_J()
{
	m_J = m_eV * c_J_eV;
}

void Energy::erg_to_J()
{
	m_J = m_erg * c_J_erg;
}

void Energy::read()
{
	std::cout << " Enter the value and unit of energy(for example: 23 J): ";
	double e_value;
	std::string e_unit;
	std::cin >> e_value >> e_unit;
	if (e_unit == "J")
	{
		m_J = e_value;
		J_to_erg();
		J_to_eV();
	}
	else if (e_unit == "eV")
	{
		m_eV = e_value;
		eV_to_J();
		J_to_erg();
	}
	else if (e_unit == "erg")
	{
		m_erg = e_value;
		erg_to_J();
		J_to_eV();
	}
	else
	{
		std::cout << " You entered the wrong energy unit" << std::endl;
	}
}

void Energy::print()
{
	std::cout << "E = " << std::scientific << m_J << " J = " << std::scientific << 
		m_erg << " erg = " << std::scientific << m_eV << " eV" << std::endl;
}