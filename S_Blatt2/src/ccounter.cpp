/*!\file ccounter.cpp
 * \brief
 *
 *  Created on: 06.04.2018
 *      Author: diamo
 */
#include "ccounter.hpp"

CCounter::CCounter(): mem(0){
}

CCounter::~CCounter(){
}

int CCounter::getValue(){
	return mem;
}

void CCounter::setValue(int value){
	mem = value;
}

void CCounter::count(){
}

