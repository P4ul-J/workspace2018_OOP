/*!\file CArrayEnc.cpp
 * \brief
 *
 *  Created on: 24.05.2018
 *      Author: diamo
 */

#include "CArrayEnc.hpp"
#include <iostream> //for err messages (and debugging)
CArrayEnc::CArrayEnc() {
	char letter{0};
	m_index = 0;
	for(m_index = 0; m_index < 256; m_index++, letter++){
		m_symbolTable[ charToInt(letter) ].setSymbol( intToString( charToInt(letter) ) );
	}
}
//searching for a string in the dict
int CArrayEnc::searchInTable(const std::string& whereAmI ){
	for(int i = 0; i < LZW_DICT_SIZE; i++){
		if(m_symbolTable[i].getSymbol() == whereAmI){
			return i;
		}
	}
	return -1;//not in the dict
}
//adds a string at the first empty position of the dict
void CArrayEnc::push_back(const std::string& newString){
	if(m_index >= LZW_DICT_SIZE){//no more space in dict
		std::cerr << "Dictionary full, error code 1235" << std::endl;
		exit(-1);
	}
	m_symbolTable[ m_index++ ].setSymbol( newString );
}

std::vector<unsigned int> CArrayEnc::encode(const std::string& in){
	char curr_char;
	//int i {0};
	vector<unsigned int> send;
//	if(! in.empty()){
//		curr_char = in.at(i++);
//		send.push_back( static_cast<unsigned int>(searchInTable(static_cast<std::string> (curr_char))) ); //no if statement needed, first char always in dict
//	}
//	else return send;

	std::string curr_str;
	for(std::string::const_iterator it = in.begin(); it != in.end() ; ++it){
		curr_char = *it;
		std::string working_copy = curr_str + curr_char; //
		if(searchInTable(working_copy) + 1){//if working copy is in the dict
			curr_str = working_copy;//curr str got extended with curr char
		}else{//found the next index to add
			//send.at(i++) = searchInTable(curr_str);
			send.push_back(searchInTable(curr_str));//adds the index of the curr str to the send
			push_back(working_copy);// adds working copy to dict
			curr_str = curr_char; //curr str in now the last letter of the last entry of the dict
		}
	}

	if(!curr_str.empty())//adds last (remaining) string to the send
		//send.at(i++) = searchInTable(curr_str);
		send.push_back(searchInTable(curr_str));
	return send;
/*todo
 * maybe later adding a func which deletes the whole dict except the first 256 entries
 * otherwise a second call of the encode func would lead to an error
 */
}



