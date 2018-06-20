/*!\file CArrayEnc.hpp
 * \brief LZW Encoder, Dictionary implementiert als Array
 *
 *	Dieses File enthält die Klasse CArrayEnc
 *	Notwendig für Teil 1 des Praktikums
 *  Created on: 24.05.2018
 *      Author: diamo
 */

#ifndef CARRAYENC_HPP_
#define CARRAYENC_HPP_

#include "CEntry.hpp" // für Typ der Dictionary Elemente
#include "CArray.hpp"// eigene Array Implementierung
#include <string> // std::string -> Eingabe des zu komprimierenden Strings
#include <vector> // std::vector -> Ausgabe des komprimierten Strings
#include "CEnc.hpp" // Basisklasse
/*!
 * \class CArrayEnc
 * \brief LZW Encoder
 * Klasse für die Encodierung
 * erbt von CEnc
 *
 */
class CArrayEnc : public CEnc{
private:
	//! Dictionary implementiert als Array vom Typ CEntry, LZW_DICT_SIZE -> Makro für die Größe
	CArray<CEntry, LZW_DICT_SIZE> m_symbolTable;
	//! index, der hinter den neusten Eintrag zeigt, erleichtert das einfügen von neuen  Zeichenketten
	unsigned int m_index; //erleichtert den überblick über das neueste Element/Eintrag zu behalten
	/*!
	 * Sucht eine Zeichenkette im Dictionary
	 * @param whereAmI Gesuchte Zeichenkette
	 * @return Position an dem die Zeichenkette gefunden wurde, -1 wenn nicht gefunden
	 */
	int searchInTable(const std::string& whereAmI );
	/*!
	 * Fügt eine Zeichenkette ans Ende des Dictionarys
	 * @param newString String der angehängt werden soll
	 */
	void push_back(const std::string& newString); //erleichtert einfügen, macht encoder übersichtlicher
public:
	 /*!
	  * \brief Parameterloser Konstuktor der Klasse
	  * initialisiert das Dicitonary mit den ersten 256 ASCII Zeichen
	  */
	CArrayEnc();
	/*!
	 * LZW encoder-function
	 * @param in zu komprimierende Zeichenkette
	 * @return kompimierte Zeichenkette als vector
	 */
	std::vector<unsigned int> encode(const std::string& in);

};

#endif /* CARRAYENC_HPP_ */
