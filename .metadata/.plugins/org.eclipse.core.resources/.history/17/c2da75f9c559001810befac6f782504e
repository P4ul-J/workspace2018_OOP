/*!\file CVariableCounter.hpp
 * \brief Vorwärtszähler, inkrementiert um einen bei Erzeugung festzulegenden Wert, Klasse ist abgeleitet von CCounter
 *
 * Klasse aus Übung 2.
 * Methode count() in CCounter wird modifiziert, so dass sie nicht mehr zählt.
 * Dem Konstruktor wird das Zählerinkrement übergeben und intern gespeichert.
 * In CVariableCounter wird die Memberfunktion count() so überschrieben, dass sie
 * mit dem gewählten Zählerinkrement inkrementiert.
 *
 */
#pragma once
#include "CCounter.hpp"

/*!
 * CVariableCounter, überschreibt die Memberfunktion count() aus Basisklasse CCounter,
 * so dass diese um einen festzulegenden Wert inkrementiert.
 * Bei Erzeugung eines Objekts wird das Zählerinkrement festgelegt.
 */
class CVariableCounter : public CCounter
{
public:
	/*!
	 * Parameterloser Konstruktor, setzt den Zählerstand auf 0 und das Zählerinkrement auf 1
	 */
	CVariableCounter();
	/*!
	 * Konstruktor, setzt den Zählerstand auf 0 und das Zählerinkrement auf den Parameterwert param_stepSize
	 */
	CVariableCounter(int param_stepSize);
	/*!
	 * Inkrementiert um das über den Konstruktor festgelegte Zählerinkrement
	 */
	void count();
private:
	int stepSize; //!< Zählerinkrement
};

