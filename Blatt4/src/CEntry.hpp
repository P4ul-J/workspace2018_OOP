/*!\file CEntry.hpp
 * \brief
 *
 *  Created on: 21.04.2018
 *      Author: diamo
 */
#include <string>

#ifndef CENTRY_HPP_
#define CENTRY_HPP_

/*!
 *
 */
class CEntry {
private:
	std::string m_symbol;
public:
	CEntry();
	const std::string& getSymbol() const;
	void setSymbol(std::string);
};

#endif /* CENTRY_HPP_ */
