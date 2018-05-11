/*!\file XOutOfBounds.hpp
 * \brief
 *
 *  Created on: 10.05.2018
 *      Author: diamo
 */

#ifndef XOUTOFBOUNDS_HPP_
#define XOUTOFBOUNDS_HPP_

#include <exception>
#include <string>
/*!
 *
 */
class XOutOfBounds : public std::exception {
private:
	std::string m_msg;
public:
	XOutOfBounds(const char* msg);
	virtual ~XOutOfBounds() throw();

	const char* what() const throw();
};

#endif /* XOUTOFBOUNDS_HPP_ */