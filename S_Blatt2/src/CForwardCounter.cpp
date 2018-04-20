/*!\file CForwardCounter.cpp
 * \brief
 *
 *  Created on: 07.04.2018
 *      Author: diamo
 */

#include "CForwardCounter.hpp"

CForwardCounter::CForwardCounter() : CCounter(){
}

void CForwardCounter::count(){
	setValue(getValue() + 1);
	;
}
