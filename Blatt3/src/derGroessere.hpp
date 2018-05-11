/*!\file derGroessere.hpp
 * \brief
 *
 *  Created on: 04.05.2018
 *      Author: diamo
 */

#ifndef DERGROESSERE_HPP_
#define DERGROESSERE_HPP_


template<typename T> const T& derGroessere(const T& val1,const T& val2) {
	return (val1 > val2) ? val1 : val2;
}


#endif /* DERGROESSERE_HPP_ */
