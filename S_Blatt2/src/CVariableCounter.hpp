/*!\file CVariableCounter.hpp
 * \brief
 *
 *  Created on: 07.04.2018
 *      Author: diamo
 */
#include "ccounter.hpp"

#ifndef CVARIABLECOUNTER_HPP_
#define CVARIABLECOUNTER_HPP_

class CVariableCounter: public CCounter{
public:
	/*!
	 * Konstruktor, m_step normal mit 0 initialisiert
	 */
	CVariableCounter();
	/*!
	 * Konstruktor
	 * @param step Schrittgröße
	 */
	CVariableCounter(int step);
	/*!
	 * Zählfunktion
	 */
	void count();
private:
	int m_step; //!< Schrittvariable
};



#endif /* CVARIABLECOUNTER_HPP_ */
