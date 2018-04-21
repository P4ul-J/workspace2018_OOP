/*!\file CSwapper.cpp
 * \brief
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */

#include "CSwapper.hpp"

CSwapper::CSwapper() {
	// TODO Auto-generated constructor stub

}

CSwapper::~CSwapper() {
	// TODO Auto-generated destructor stub
}

void CSwapper::swap_byValue(int value1, int value2){
	int temp = value2;
	value2 = value1;
	value1 = temp;
}
void CSwapper::swap_byReference(int& value1, int& value2){
	int temp = value2;
	value2 = value1;
	value1 = temp;
}
void CSwapper::swap_byPointer(int* value1, int* value2){
	int temp = *value2;
	*value2 = *value1;
	*value1 = temp;
}
