/*!\file CKnot.cpp
 * \brief
 *
 *  Created on: 11.05.2018
 *      Author: diamo
 */

#include "CKnot.hpp"

CKnot::CKnot() : m_parent(-2){ //TODO changed to -2 instead of 0, cuz gtest
	// setSymbol(""); // nicht notwendig da Konst. parameterlos, auch nicht Initialisierungliste
}

CKnot::~CKnot() {}

int CKnot::getParent()const{
	return m_parent;
}

void CKnot::setParent(int parent){
	m_parent = parent;
}
