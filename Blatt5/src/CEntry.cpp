/*!\file CEntry.cpp
 * \brief
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */

#include "CEntry.hpp"
unsigned int CEntry::m_number = 0; //really necessary

CEntry::CEntry() : m_symbol("") {
	m_number++;
}
CEntry::~CEntry(){
	m_number--;
}
//Standartkonstruktor initialisiert automatisch mit ""
const std::string& CEntry::getSymbol() const{
	return m_symbol;
}
void CEntry::setSymbol(std::string symbol){
	m_symbol = symbol;
}
unsigned int CEntry::getNumber(){
	return m_number;
}
