/*!\file XOutOfBounds.cpp
 * \brief
 *
 *  Created on: 10.05.2018
 *      Author: diamo
 */

#include "XOutOfBounds.hpp"

XOutOfBounds::XOutOfBounds(const char* msg) : m_msg(msg){} //Initialisierung von m_msg über Init.-Liste

XOutOfBounds::~XOutOfBounds() throw() {} //Destruktor darf keine exceptions werfen

const char* XOutOfBounds::what() const throw(){ //readonly, darf keine exceptions werfen
	return m_msg.c_str();  //wandelt c++ string in einen c string (also Array of char) um und gibt diesen aus
}
