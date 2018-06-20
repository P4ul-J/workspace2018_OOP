/*!\file CDoubleHashing.hpp
 * \brief
 *
 *  Created on: 18.05.2018
 *      Author: diamo
 */

#ifndef CDOUBLEHASHING_HPP_
#define CDOUBLEHASHING_HPP_

/*!
 *
 */
class CDoubleHashing {
private:
	static CDoubleHashing m_instance;
	CDoubleHashing();
	CDoubleHashing(const CDoubleHashing& other);
	CDoubleHashing operator=(const CDoubleHashing& other);

public:
	virtual ~CDoubleHashing();
	static CDoubleHashing& getInstance();
	unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt);
};

#endif /* CDOUBLEHASHING_HPP_ */
