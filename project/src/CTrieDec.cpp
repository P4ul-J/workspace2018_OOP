/*!\file CTrieDec.cpp
 * \brief
 *
 *  Created on: 29.05.2018
 *      Author: diamo
 */

#include "CTrieDec.hpp"
#include <iostream> //mainly for Debugging purposes and some error messages
#include <algorithm> //for reverse()

CTrieDec::CTrieDec() {
	m_symbolTable = new CKnot[LZW_DICT_SIZE];//knots saved in an dyn array
	for(int i = 0; i < 256 ; i++){
			m_symbolTable[i].setSymbol(intToString(i));
			m_symbolTable[i].setParent(-1);
	}//no need for the missing elements -> automaticly initialized with parent -2 and empty string
}
CTrieDec::~CTrieDec(){
	delete[] m_symbolTable;//deletes the whole table
}
//tracks a knot to the root and output the string saved
std::string CTrieDec::getString(int knot){
	std::string reverse_str;
	while(knot != -1){//-1 entspricht der root
		reverse_str += m_symbolTable[knot].getSymbol();
		knot = m_symbolTable[knot].getParent();
		if(knot == -2){ //verweis auf ein leeres element als parent
			std::cerr << "Failure reading the Path, getString function" << std::endl;
		}
	}
	std::reverse(reverse_str.begin(), reverse_str.end()); // kehrt string um, da von unten/ hinten aus Baum gelesen wird
	return reverse_str;
}
//SOLVED: problem how to find the last index of a string
int CTrieDec::find_last_knot(const std::string in){
	CDoubleHashing& hash = CDoubleHashing::getInstance();
	int I, J;//I Parent-address, J char

	int newPos, rehash;//initial hash and rehash
	J = static_cast<unsigned char>(in.front());//w/o the cast J would get negative values from characters of the extended ASCII table
	I = J; //Value of J is the first Position of the Knot because of how the dict is initialized
	for(std::string::const_iterator it = ++in.begin(); it != in.end(); ++it){

		CForwardCounter attemptCounter;
		rehash = -1; //redundant
		J = static_cast<unsigned char>(*it);//w/o the cast J would get negative values from characters of the extended ASCII table
		newPos = hash.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());
		rehash = newPos;
		while(	m_symbolTable[rehash].getParent() != -2 && //leerer Knoten
				( J != m_symbolTable[rehash].getSymbol().front() || I != m_symbolTable[rehash].getParent() )// Knoten enth�lt I und J bereits
			)
		{
			attemptCounter.count();//rehash attempt +1
			rehash = hash.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());

			if(rehash == newPos){// kommt wieder beim urspr�nglichen Hashwert an-> keine aussicht auf �nderung
				/*//DEBUG:
				std::cout << "newPos: " << newPos << " rehash: " << rehash << std::endl; //DEBUG
				std::cout << "I:" << I << " J: " << J << " attempt: " << attemptCounter.getValue() << " String: " << in << std::endl; //DEBUG
				//std::vector<unsigned int> error;
				//return error;

				break;*/
				exit(99);//this case should never happen, instead maybe just return -1
			}

			//DEBUG:
			/*
			if( !(J != m_symbolTable[rehash].getSymbol().front() || I != m_symbolTable[rehash].getParent()) ){
				std::cout << m_symbolTable[rehash].getSymbol().front() << "\t" << m_symbolTable[rehash].getParent() << std::endl; //DEBUG
				std::cout << "J: " << J << " I: " << I << std::endl;//DEBUG
			}*/
		}

		//std::cout << I << "\t" << J << std::endl; //DEBUG
		if(!(J != m_symbolTable[rehash].getSymbol().front() || I != m_symbolTable[rehash].getParent())){//found knot of the string
					I = rehash; // last knot I get the addr of the new knot
				//std::cout << "string searched: " << in  << "\t I: " << I << "\t symbol: " << intToString(J)<< std::endl ; //DEBUG
				continue;
				}

		if(m_symbolTable[rehash].getParent() != -2){ //erreicht ende (nicht immer m�glich)
			//std::cout << "string searched: " << in << std::endl;
			return I;
		}


			}

	// std::cerr << I << " J: " << J << " rehash: "<< rehash <<  std::endl; // DEBUG
	return I;
}


/*
 * SOLVED:had problems adding the new string to the dictionary, so cuz the next string  isnt in the dict, it insteads extends just the old string
 * 		-> get_last_knot() wouldnt find some strings in the dict
 */
std::string CTrieDec::decode(const std::vector<unsigned int>& enc){
	if(enc.empty())return "";//no input/ empty input
	CDoubleHashing& hash = CDoubleHashing::getInstance();
	std::string decoded_str, last_str, curr_str;
	int I, J;
	int newPos, rehash;//initial hash and rehash
	int index; //could probably replace by I

	index = *enc.begin();
	last_str = getString(index); // first string/character always in initial dict, easy to handle
	decoded_str = last_str; //directly add first char. to output string

	for(std::vector<unsigned int>::const_iterator it = ++enc.begin(); it != enc.end(); ++it){//++enc.begin because the first element already got read
		CForwardCounter attemptCounter;//keeps track of the rehashing attemps
		index = *it;
		//std::cout << "Symbol: "<< m_symbolTable[index].getSymbol() <<std::endl;
		if(m_symbolTable[index].getParent() != -2){//dict not empty a this position -> substring already known
			//std::cout << curr_str << std::endl; // already has wrong string, right format after the getString call
			curr_str = getString(index);
			//std::cout << curr_str << "\t" << index << std::endl;
		}
		else{//special case where string of this (sended) index has yet to be saved in the dict -> last str
			//SOLVED: error here just adds one string to the end, REASON: find_last_knot() wouldnt find some strings thus gave a false index where dict empty
			//std::cout << m_symbolTable[index].getParent() << std::endl;
			//std::cout << last_str << "\t"<< curr_str <<std::endl;
			curr_str = last_str + last_str.front(); //in this case last (yes missing) char of the current str is the last str and its first char
			//std::cout << last_str << "\t" << curr_str <<std::endl;
		}
		decoded_str += curr_str;
		//std::cout << curr_str << std::endl; //DEBUG
		//Hash loop adds new found str to dict
		I = find_last_knot(last_str);//need to find the exact knot
		// std::cout << I  << "\t"<< last_str<< std::endl; // DEBUG
		J = curr_str.front();//last char of last str, so unknown part of last str gets added
		newPos = hash.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());
		rehash = newPos;
		//same as above (find_last_knot()):
		while(
				m_symbolTable[rehash].getParent() != -2  //leerer Knoten
				//&& ( J != m_symbolTable[rehash].getSymbol().front() || I != m_symbolTable[rehash].getParent() )// Knoten enth�lt I und J bereits, -> not relevant here
			)
		{
			attemptCounter.count();
			rehash = hash.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());

			if(rehash == newPos){// kommt wieder beim urspr�nglichen Hashwert an
				exit(99);
			}
		}
		if(m_symbolTable[rehash].getParent() == -2){//leeren knoten gefunden
			m_symbolTable[rehash].setParent(I);
			m_symbolTable[rehash].setSymbol(intToString(J));
			//std::cout << intToString(J) << " I: " << I << std::endl; //DEBUG
			/* HIER DEBUG:
			std::cout << getString(rehash) << "\t" <<  getString(I) << "\t last_str:" << last_str << "\t curr_str: " << curr_str << "\t J: " << intToString(J) << std::endl;
			std::cout << rehash << "\t" << I <<std::endl;
			std::cout << find_last_knot("xyx") << "\t" << find_last_knot("xy") << std::endl;//doesnt find xyx for example*/
		}else{//never happens-> should always find an empty space
		//HIER	std::cout << "Throw anscheinend falsch angeh�ngt\t I:" << I << " j: " << J <<  std::endl; //DEBUG
		}
		//end Hash loop

		last_str = curr_str;//now the current str get the last str of the next alteration of the loop
		//std::cout << last_str << std::endl; //DEBUG
	}

	return decoded_str;
}

