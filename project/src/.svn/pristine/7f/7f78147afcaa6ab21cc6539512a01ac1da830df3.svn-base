/*!\file CArrayDec.cpp
 * \brief
 *
 *  Created on: 24.05.2018
 *      Author: diamo
 */

#include "CArrayDec.hpp"
#include <iostream> //for error message
CArrayDec::CArrayDec() {
	char letter{0};
	m_index = 0; //keeps track of the newest element / points at the next empty space
	for(m_index = 0; m_index < 256; m_index++, letter++){
		m_symbolTable[ charToInt(letter) ].setSymbol( intToString( charToInt(letter) ) );//initialises array according to the ansi/ascii table
	}
}
//for searching a string in the dict
int CArrayDec::searchInTable(const std::string& whereAmI ){
	for(int i = 0; i < LZW_DICT_SIZE; i++){//easier to search the whole array (since i added the m_index var, could make a bit faster)
		if(m_symbolTable[i].getSymbol() == whereAmI){
			return i;
		}
	}
	return -1;
}
//decoder:
std::string CArrayDec::decode(const std::vector<unsigned int>& enc){
	if(enc.empty()) return "";//if no/empty input

	//char curr_char;
	unsigned int index; //curr index
	std::string decoded_str, last_str, curr_str;

	index = *(enc.begin());
	last_str = m_symbolTable[index].getSymbol();//first symbol always in the table
	decoded_str = last_str; //since its the first latter -> directly added to output str

	for(std::vector<unsigned int>::const_iterator it = ++enc.begin(); it != enc.end() ; ++it){
//		last_str = curr_str;
		index = *it;
		if(index >= LZW_DICT_SIZE){//index larger than the dict -> error not possible
			std::cerr << "Dictionary full, error code 1234" << std::endl;
			exit(-1);
		}
		if(index < m_index ) // index already known
			curr_str = m_symbolTable[index].getSymbol();
		else if(index == m_index)//special case, if element of this index ius going to be saved next step
			curr_str = last_str + last_str.front(); //but format known, cuz index is last str + curr first and last str is itself + next latter-> curr str is last str and its front letter
		else
			throw "Encoding is bad!";//throw exception this case should never happen
		decoded_str += curr_str; //add new str to output
		m_symbolTable[m_index++].setSymbol( last_str + curr_str.front() ); //add last str to dict
		last_str = curr_str; //now curr str becomes last str
	}

	return decoded_str;
}



