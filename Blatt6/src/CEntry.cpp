/*!\file CEntry.cpp
 * \brief
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */

#include "CEntry.hpp"
unsigned int CEntry::m_number = 0; //Initialisierung der statischen Variable (necessary!)

CEntry::CEntry() : m_symbol("") {//m_symbol wird mit "" initialisiert
	m_number++; //Anzahl der Objekte wird erhört -> vermerkt in m_number
}//(Standartkonstruktor initialisiert automatisch mit "")-> nicht zwingend notwendig
CEntry::~CEntry(){
	m_number--; //Anzahl der Objekte wird verrringert -> vermerkt in m_number
}
const std::string& CEntry::getSymbol() const{
	return m_symbol;
}
void CEntry::setSymbol(std::string symbol){
	m_symbol = symbol;
}
unsigned int CEntry::getNumber(){
	return m_number;
}
