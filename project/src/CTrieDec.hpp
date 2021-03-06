/*!\file CTrieDec.hpp
 * \brief LZW Decoder, Dictionary implementiert als Trie
 *
 *	Dieses File enth�lt die Klasse CTrieDec
 *	Notwendig f�r Teil 2 des Praktikums
 *  Created on: 29.05.2018
 *      Author: diamo
 */

#ifndef CTRIEDEC_HPP_
#define CTRIEDEC_HPP_

#include "CKnot.hpp" //f�r Datentyp Knot -> einzelne Knoten
#include <vector> //f�r std::vector -> Ausgabe des komprimierten Strings
#include <string> //f�r std::string -> Eingabe des zu komprimierenden Strings
#include "CDoubleHashing.hpp" //Hashing Funktion
#include "CForwardCounter.hpp"//counter, der Anzahl der ReHashing Versuch z�hlt
#include "CDec.hpp" //Basisklasse
/*!
 * \class CTrieDec
 * \brief LZW Decoder
 * Klasse f�r die Decodierung
 * erbt von CEnc
 *
 */
class CTrieDec : public CDec{
private:
	//! Dictionary in dem Knoten des Tries gespeichert werden, Gr��e der Tabelle: LZW_DICT_SIZE
	CKnot* m_symbolTable;
	/*!
	 * Getter
	 * @param knot Knoten des letzten Zeichens
	 * @return String der (von der Wurzel) bis zu knot geht
	 */
	std::string getString(int knot);
	/*!
	 * Sucht nach dem Knoten des letzten Zeichens eines Strings im dictionary
	 * @param in String dessen letzter Buchstabe (Knoten davon) ausgegeben werden soll
	 * @return den Knoten des letzten Buchstabens von in
	 */
	int find_last_knot(const std::string in);
public:
	/*!
		 * Paramenterloser Konstruktor der Klasse
		 * Initialisiert das Dictionary
		 */
	CTrieDec();
	/*!
	 * Destruktor
	 */
	~CTrieDec();
	/*!
	 * LZW decoder-function
	 * @param enc komprimierte Zeichenkette als vector
	 * @return Enschl�sselte Zeichenkette
	 */
	std::string decode(const std::vector<unsigned int>& enc);


};

#endif /* CTRIEDEC_HPP_ */
