/*!\file CEntry.cpp
 * \brief
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */

#include "CEntry.hpp"

CEntry::CEntry() : m_symbol("") {}
//Standartkonstruktor initialisiert automatisch mit ""
const std::string& CEntry::getSymbol() const{
	return m_symbol;
}
void CEntry::setSymbol(std::string symbol){
	m_symbol = symbol;
}

