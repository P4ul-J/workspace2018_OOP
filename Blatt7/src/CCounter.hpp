/*!\file ccounter.hpp
 * \brief
 *
 *  Created on: 06.04.2018
 *      Author: diamo
 */
// pragma once auch gut
#ifndef CCOUNTER_HPP_
#define CCOUNTER_HPP_

#include <list>
#include "CCounterObserver.hpp"

/*! Klasse CCounter
 *
 *Enthalt Membervariable mem
 *
 *
 */
class CCounter{
public:
	CCounter();//!< Kontstruktor, paramenterlos
	virtual ~CCounter();//!< Dekonstruktor
	virtual void count();//!< Erh�ht Z�hlerstand um 1
	int getValue()const;//darf Objekt nicht ver�ndern
	/*!<Getter
	 * @return Wert der Membervariable
	 */
	void setValue(int value);
	/*!<Setter
	 * @param value neuer Wert der Membervariable
	 */
	bool operator>( const CCounter& right)const;
	bool operator<( const CCounter& right)const;

	void registerObserver(CCounterObserver* observer);
	void unregisterObserver(CCounterObserver* observer);

protected:
	void notifyObserver();
private:
	int m_value; //!< private Membervariable f�r den Z�hlerstand
	 std::list<CCounterObserver*> m_observers;
};



#endif /* CCOUNTER_HPP_ */
