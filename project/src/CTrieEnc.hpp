/*!\file CTrieEnc.hpp
 * \brief LZW Encoder, Dictionary implementiert als Trie
 *
 *	Dieses File enth�lt die Klasse CTrieEnc
 *	Notwendig f�r Teil 2 des Praktikums
 *  Created on: 29.05.2018
 *      Author: diamo
 */

#ifndef CTRIEENC_HPP_
#define CTRIEENC_HPP_

#include "CKnot.hpp" //f�r Datentyp Knot -> einzelne Knoten
#include <vector> //f�r std::vector -> Ausgabe des komprimierten Strings
#include <string> //f�r std::string -> Eingabe des zu komprimierenden Strings
#include "CDoubleHashing.hpp" //Hashing Funktion
#include "CForwardCounter.hpp"//counter, der Anzahl der ReHashing Versuch z�hlt
#include "CEnc.hpp" // Basisklasse

/*!
 * \class CTrieEnc
 * \brief LZW Encoder
 * Klasse f�r die Encodierung
 * erbt von CEnc
 *
 */
class CTrieEnc : public CEnc {
private:
	//! Dictionary in dem Knoten des Tries gespeichert werden, Gr��e der Tabelle: LZW_DICT_SIZE
	CKnot* m_symbolTable;
public:
	/*!
	 * Paramenterloser Konstruktor der Klasse
	 * Initialisiert das Dictionary
	 */
	CTrieEnc();
	~CTrieEnc();
	/*!
	 * LZW encoder-function
	 * @param in zu komprimierende Zeichenkette
	 * @return kompimierte Zeichenkette als vector
	 */
	std::vector<unsigned int> encode (const std::string& in);

};

#endif /* CTRIEENC_HPP_ */
