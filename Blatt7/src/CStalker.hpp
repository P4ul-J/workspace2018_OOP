/*!\file CStalker.hpp
 * \brief
 *
 *  Created on: 18.05.2018
 *      Author: diamo
 */

#ifndef CSTALKER_HPP_
#define CSTALKER_HPP_

#include ""

/*!
 *
 */
class CStalker {
public:
	CStalker();
	virtual ~CStalker();
	int newValue();
	void stalk(CCounter* target);
	void stop_stalk();
};

#endif /* CSTALKER_HPP_ */
