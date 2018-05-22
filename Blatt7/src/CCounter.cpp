/*!\file ccounter.cpp
 * \brief
 *
 *  Created on: 06.04.2018
 *      Author: diamo
 */
#include "CCounter.hpp"

CCounter::CCounter(): m_value(0){
}

CCounter::~CCounter(){
}

int CCounter::getValue()const{
	return m_value;
}

void CCounter::setValue(int value){
	m_value = value;
}

void CCounter::count(){
}
bool CCounter::operator>( const CCounter&  right)const{
	if(this->m_value > right.m_value)return true;
	else return false;
}

bool CCounter::operator<(const CCounter& right)const{
	if(this->m_value < right.m_value)return true;
	else return false;
}



void CCounter::registerObserver(CCounterObserver* observer){
	m_observer.push_back(observer);
}
void CCounter::unregisterObserver(CCounterObserver* observer){
	m_observer.remove(observer);
}

void CCounter::notify(){
	for(auto& observer : m_observers){
		observer->newValue();
	}
}
