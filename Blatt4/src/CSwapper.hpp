/*!\file CSwapper.hpp
 * \brief
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */

#ifndef CSWAPPER_HPP_
#define CSWAPPER_HPP_

/*!
 *
 */
class CSwapper {
public:
	CSwapper();
	virtual ~CSwapper();
	void swap_byValue(int, int); //Funktioniert nicht, da nur werte in F kopiert werden
	void swap_byReference(int&, int&);
	void swap_byPointer(int*, int*);
};

#endif /* CSWAPPER_HPP_ */
