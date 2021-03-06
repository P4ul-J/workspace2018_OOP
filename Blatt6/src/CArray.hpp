/*!\file CArray.hpp
 * \brief Template-Klasse CArray
 *  Erzeugt ein Array vom Typ T mit N Elementen
 *
 *  Created on: 10.05.2018
 *      Author: diamo
 */

#ifndef CARRAY_HPP_
#define CARRAY_HPP_

#include "XOutOfBounds.hpp" //exception class

 /*!\class CArray
  * \brief Erzeugt ein Array vom Typ T mit N Elementen
  * Es existiert ein Kopierkonstruktor, der eine tiefe Kopie eines anderen Objekts gleichen Typs erzeugt.
  * Mithilfe des operators [] kann man direkt auf eine Referenz eines Elementes von entries zugreifen.
  */
template<typename T, unsigned int N>
class CArray{
private:
	//! Zeigt auf ein Feld  von Elementen des Typs T
	T* entries;
public:
	CArray(); //!< Paramenterloser Standartkonstruktor
	 /*!
	  *\brief Kopierkonstruktur
	  * Erzeugt eine tiefe Kopie von copy
	  * @param copy Referenz auf zu kopierendes Objekt
	  */
	CArray(const CArray<T,N>& copy);
	/*!
	 * \brief Destruktor der Klasse
	 * l�scht das gesamte Array und macht entries anschlie�end zum nullptr
	 */
	virtual ~CArray();
	/*!
	 * Zugriff auf ein einzelnes Element des Feldes entries
	 * @param index Stelle des Zugriffs
	 * @return Referenz auf das Element
	 */
	T& operator[](unsigned int index);
};

template<typename T, unsigned int N>
CArray<T,N>::CArray(){
		entries = new T[N];
	}
template<typename T, unsigned int N>
CArray<T,N>::~CArray(){
	if(entries != nullptr){
		delete[] entries;
		entries = nullptr;
	}
}
template<typename T, unsigned int N>
T& CArray<T,N>::operator[](unsigned int index){
	if(index >= N){
		throw XOutOfBounds("Index zu gro�!");
	}
	return entries[index];
}
template<typename T, unsigned int N>
CArray<T,N>::CArray(const CArray<T,N>& copy){
	entries = new T[N];
	for(int i = 0; i < N; i++){
		entries[i] = copy[i]; //Musterl�sung copy.entries[i]
	}
}
#endif /* CARRAY_HPP_ */
