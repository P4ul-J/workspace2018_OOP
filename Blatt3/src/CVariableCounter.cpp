/*!\file CVariableCounter.cpp
 * \brief
 *
 *  Created on: 07.04.2018
 *      Author: diamo
 */

#include "CVariableCounter.hpp"

CVariableCounter::CVariableCounter()  :CCounter(), m_step(0){
}

CVariableCounter::CVariableCounter(int step) : CCounter(), m_step(step){
}

void CVariableCounter::count(){
	setValue(getValue() + m_step);
}


