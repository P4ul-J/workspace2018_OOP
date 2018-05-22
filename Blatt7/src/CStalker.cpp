/*!\file CStalker.cpp
 * \brief
 *
 *  Created on: 18.05.2018
 *      Author: diamo
 */

#include "CStalker.hpp"

CStalker::CStalker() {
	// TODO Auto-generated constructor stub

}

CStalker::~CStalker() {
	// TODO Auto-generated destructor stub
}


void CStalker::stalk(CCounter* target){
	m_target = target;
	m_target-> registerObserver(this);
}
void CStalker::stop_stalk()
{
	m_target->unregisterObserver(this);
	m_target = nullptr;
}
int CStalker::newValue(){
	m_target ->
}
