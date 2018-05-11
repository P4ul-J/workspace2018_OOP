/*!\file CKnot.hpp
 * \brief
 *
 *  Created on: 11.05.2018
 *      Author: diamo
 */

#ifndef CKNOT_HPP_
#define CKNOT_HPP_
#include "CEntry.hpp"
/*!
 *
 */
class CKnot : public CEntry{
private:
	int m_parent;
public:
	CKnot();
	virtual ~CKnot();
	int getParent()const;
	void setParent(int parent);
};

#endif /* CKNOT_HPP_ */
