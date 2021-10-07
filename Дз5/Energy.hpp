#pragma once

class Energy
{
public:
	Energy() : m_J(0.0), m_erg(0.0), m_eV(0.0)
	{}

	~Energy()
	{}

	void J_to_erg();
	void J_to_eV();
	void eV_to_J();
	void erg_to_J();

	void read();
	void print();

	static inline const double c_J_erg = 1.0e+7;
	static inline const double c_J_eV = 6.242e+18;

private:
	double m_J;
	double m_erg;
	double m_eV;
};