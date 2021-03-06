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
	static unsigned int m_number;
public:
	CEntry();
	virtual ~CEntry();
	const std::string& getSymbol() const;
	void setSymbol(std::string);
	static unsigned int getNumber();
};
#endif /* CENTRY_HPP_ */
