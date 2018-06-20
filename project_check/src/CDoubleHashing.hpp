/*!\file CDoubleHashing.hpp
 * \brief Klasse zum Hashen
 *
 *	Dieses File enhält die Klasse CDoubleHashing
 *	wird später in CTrieEnc und CTrieDec benötigt
 *	(Notwendig für Teil_2)
 *
 *  Created on: 18.05.2018
 *      Author: diamo
 */

#ifndef CDOUBLEHASHING_HPP_
#define CDOUBLEHASHING_HPP_

/*!
 * \class
 * \brief Hashingklasse zum gernerieren der neuen Adressen des Tries
 *
 * nach dem Singleton Entwurfsmuster, also nur eine Instanz der Klasse zur Zeit existent
 */
class CDoubleHashing {
private:
	//! Instanz der Klasse, mit der gearbeitet werden soll
	static CDoubleHashing m_instance;
	//! Konstruktor privat -> Singleton
	CDoubleHashing();
	//! Kopierkonstruktor privat -> Singleton
	CDoubleHashing(const CDoubleHashing& other);
	//! Zuweisungsoperator privat -> Singleton
	CDoubleHashing operator=(const CDoubleHashing& other);

public:
	//! Standard Destruktor
	virtual ~CDoubleHashing();
	/*!
	 * Einzige Möglichkeit an ein Objekt dieser Klasse zu gelangen
	 * static -> Singleton, nur Objekt der Klasse vorhanden
	 * @return Objekt der Klasse
	 */
	static CDoubleHashing& getInstance();
	/*!
	 * individuelle Hashing Funktion, doppeltes Hashing
	 * @param I	Elternposition
	 * @param J ASCII Wert des neu eingelesenen Zeichens
	 * @param dict_size Größe des Dictionarys
	 * @param attempt Anzahl der Hashversuches
	 * @return Hashwert
	 */
	unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt);
};

#endif /* CDOUBLEHASHING_HPP_ */
