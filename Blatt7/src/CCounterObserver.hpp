/*!\file CCounterObserver.hpp
 * \brief
 *
 *  Created on: 18.05.2018
 *      Author: diamo
 */

#ifndef CCOUNTEROBSERVER_HPP_
#define CCOUNTEROBSERVER_HPP_

/*!
 *
 */
class CCounterObserver {
public:
	CCounterObserver();
	virtual ~CCounterObserver();
	virtual int newValue() = 0;
	virtual void stalk(CCounter* target) = 0;
	virtual void stop_stalk();
protected:
	CCounter* m_target;
};

#endif /* CCOUNTEROBSERVER_HPP_ */
