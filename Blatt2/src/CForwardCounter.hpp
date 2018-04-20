/*!\file CForwardCounter.hpp
 * \brief Vorw�rtsz�hler, inkrementiert um 1, Klasse ist abgeleitet von CCounter
 *
 * Klasse aus �bung 2.
 * Methode count() in Basisklasse CCounter wird modifiziert, so dass sie nicht mehr z�hlt.
 * In CForwardCounter wird die Memberfunktion count() so �berschrieben, dass sie
 * mit Schrittweite 1 inkrementiert.
 *
 */
#pragma once
#include "CCounter.hpp"
/*!
 * CForwardCounter, �berschreibt die Memberfunktion count() aus Basisklasse CCounter,
 * so dass diese den internen Z�hlerstand um 1 inkrementiert.
 */
class CForwardCounter : public CCounter
{
public:
	/*!
	 * Parameterloser Konstruktor, setzt den Z�hlerstand auf 0
	 */
	CForwardCounter();
	/*!
	 * Z�hler, inkrementiert den Z�hlerstand um 1
	 */
	void count();
};



