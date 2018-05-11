/*!\file CEntry.hpp
 * \brief Enth�lt die Basisklasse CEntry
 * Wird sp�ter von CKnot ben�tigt
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */
#ifndef CENTRY_HPP_
#define CENTRY_HPP_

#include <string>
/*!
 * \class CEntry
 * \brief Enth�lt Zeichenketten und Anzahl der Objekte dieser Klasse
 * Wird sp�ter von CKnot ben�tigt/erweitert.
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
