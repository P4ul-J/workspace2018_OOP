/*!\file XOutOfBounds.hpp
 * \brief Enthält die Klasse XOutOfBounds
 * Es handelt sich hierbei um eine Klasse die Ausnahmeobjekte erstellt.
 *
 *  Created on: 10.05.2018
 *      Author: diamo
 */

#ifndef XOUTOFBOUNDS_HPP_
#define XOUTOFBOUNDS_HPP_

#include <exception> //Basisklasse von XOutOfBounds
#include <string> //für die Klasse string (+ Memberfunktion c_str()
/*!
 *\class XOutOfBounds
 *\brief Ausnahmeklasse
 * Abgeleitete Klasse von std::exception.
 * Speichert Ausnahmen und gibt diese auch wieder aus.
 */
class XOutOfBounds : public std::exception {
private:
	std::string m_msg;//!<Bescheibung der Ausnahme
public:
	/*!
	 * Konstruktor
	 * @param msg Beschreibung / Bezeichnung der Ausnahme
	 */
	XOutOfBounds(const char* msg);
	/*!
	 * Destruktor
	 *
	 * Kann aufgrund von throw() selbst keine exceptions werfen.
	 */
	virtual ~XOutOfBounds() throw();
	/*!
	 * \brief Getter
	 * Kann aufgrund von throw() selbst keine exceptions werfen.
	 * @return Beschreibung / Bezeichnung der Ausnahme
	 */
	const char* what() const throw();
};

#endif /* XOUTOFBOUNDS_HPP_ */
