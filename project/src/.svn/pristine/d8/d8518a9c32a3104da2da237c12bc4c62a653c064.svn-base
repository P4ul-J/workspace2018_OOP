/*!\file CKnot.hpp
 * \brief Enthält die Klasse CEntry
 *	Erbt von CKnot
 *
 *  Created on: 11.05.2018
 *      Author: diamo
 */

#ifndef CKNOT_HPP_
#define CKNOT_HPP_
#include "CEntry.hpp"
/*!
 * \class CKnot
 * \brief Erweiterung von CEntry
 * Erweitert CEntry zusätzlich um die Variable m_parent und wird zur Verwaltung bisher bekannter Zeichenketten verwendet.
 */
class CKnot : public CEntry{
private:
	int m_parent; //!< Adresse des übergeodneten Knotens (Parent)
public:
	/*!
	 * Parameterloser Konstruktor
	 */
	CKnot();
	/*!
	 * Destruktor
	 */
	virtual ~CKnot();
	/*!
	 * Getter
	 * @return Adresse des übergeodneten Knotens (Parent)
	 */
	int getParent()const;
	/*!
	 * Setter
	 * @param parent neue Adresse des übergeodneten Knotens (Parent)
	 */
	void setParent(int parent);
};

#endif /* CKNOT_HPP_ */
