/*!\file CEntry.hpp
 * \brief Enthält die Basisklasse CEntry
 * Wird später von CKnot benötigt
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */
#ifndef CENTRY_HPP_
#define CENTRY_HPP_

#include <string>
/*!
 * \class CEntry
 * \brief Enthält Zeichenketten und Anzahl der Objekte dieser Klasse
 * Wird später von CKnot benötigt/erweitert.
 */
class CEntry {
private:
	std::string m_symbol; //!< Bekannte Zeichenkette
	static unsigned int m_number; //!< Anzahl der Objekten dieser Klasse, die existieren
public:
	/*!
	 * Parameterloser Konstruktor
	 */
	CEntry();
	/*!
	 * Destruktor
	 */
	virtual ~CEntry();
	/*!
	 * Getter
	 * @return Bekannte Zeichenkette
	 */
	const std::string& getSymbol() const;
	/*!
	 * Setter
	 * @param symbol Bekannte Zeichenkette
	 */
	void setSymbol(std::string symbol);
	/*!
	 * Getter
	 * @return Anzahl der Objekten dieser Klasse, die existieren
	 */
	static unsigned int getNumber();
};
#endif /* CENTRY_HPP_ */
