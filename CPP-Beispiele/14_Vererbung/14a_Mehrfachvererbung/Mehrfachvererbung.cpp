/***************************************************************************
                          Mehrfachvererbung.cpp  -  Projekt 14a_Mehrfachvererbung
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : grigat@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This file is used in the class "Informatik fuer Ingenieure" as        *
 *   a demo program. You can redistribute it and/or modify it              *
 *   under the terms of the GNU General Public License as published by     *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

//
// Demonstration von Vererbungsprinzipien
// Die Klassen CB1 und CB2 sind von CA abgeleitet.
// Klasse CC ist von CB1 und CB2 abgeleitet.
// Member ABC ist in den Klassen CA, CB1, CB2, CC definiert.
// Member AB ist in den Klassen CA, CB1, CB2 definiert.
// Member A ist in Klasse CA definiert.
// Member Bsolo ist in Klasse CB1 definiert.
//


#include "Mehrfachvererbung.hpp"
#include <iostream>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;

void druckeCC(CC & myCC, CB1* pmyCB1, CB2* pmyCB2)
{
	cout << "Membervariablen aus Objekt des Typs CC\n"

			<< "\nABC:"
			<< "\n         myCC.ABC >>>>> " << myCC.ABC
			<< "\n     myCC.CC::ABC >>>>> " << myCC.CC::ABC
			<< "\n    myCC.CB1::ABC >>>>> " << myCC.CB1::ABC
			<< "\n    myCC.CB2::ABC >>>>> " << myCC.CB2::ABC
			<< "\n  pmyCB1->CA::ABC >>>>> " << pmyCB1->CA::ABC
			<< "\n  pmyCB2->CA::ABC >>>>> " << pmyCB2->CA::ABC

			<< "\nAB:"
			<< "\n     myCC.CB1::AB >>>>> " << myCC.CB1::AB
			<< "\n     myCC.CB2::AB >>>>> " << myCC.CB2::AB
			<< "\n   pmyCB1->CA::AB >>>>> " << pmyCB1->CA::AB
			<< "\n   pmyCB2->CA::AB >>>>> " << pmyCB2->CA::AB

			<< "\nA:"
			//       << "\n           myCC.A >>>>> " << myCC.A      //Request for Member A is ambigous
			//       << "\n       myCC.CA::A >>>>> " << myCC.CA::A  //Request for Member A is ambigous
			<< "\n      myCC.CB1::A >>>>> " << myCC.CB1::A
			<< "\n      myCC.CB2::A >>>>> " << myCC.CB2::A
			<< "\n    pmyCB1->CA::A >>>>> " << pmyCB1->CA::A
			<< "\n    pmyCB2->CA::A >>>>> " << pmyCB2->CA::A

			<< "\nBsolo:"
			<< "\n       myCC.Bsolo >>>>> " << myCC.Bsolo
			<< "\n  myCC.CB1::Bsolo >>>>> " << myCC.CB1::Bsolo

			<< "\n\n"<< endl;
}

void CC::zuweisung(CB1* pmyCB1, CB2* pmyCB2)
{
	ABC       ="ABC   nach Funktion zuweisung fuer CC         ";
	Bsolo     ="Bsolo nach Funktion zuweisung fuer CB1        ";
	CB1::A    ="A     nach Funktion zuweisung fuer CA ueber CB1";
	CB2::A    ="A     nach Funktion zuweisung fuer CA ueber CB2";
	CB1::AB   ="AB    nach Funktion zuweisung fuer CB1        ";
	CB1::ABC  ="ABC   nach Funktion zuweisung fuer CB1        ";
	CB2::AB   ="AB    nach Funktion zuweisung fuer CB2        ";
	CB2::ABC  ="ABC   nach Funktion zuweisung fuer CB2        ";

	cout << "\nZuweisung:\nAB und ABC in CA werden ueber"
			<< "\nZeiger auf CB1 bzw. CB2 angesprochen. \n" << endl;
	pmyCB1->CA::AB    ="AB    nach Funktion zuweisung fuer CA ueber CB1";
	pmyCB1->CA::ABC   ="ABC   nach Funktion zuweisung fuer CA ueber CB1";
	pmyCB2->CA::AB    ="AB    nach Funktion zuweisung fuer CA ueber CB2";
	pmyCB2->CA::ABC   ="ABC   nach Funktion zuweisung fuer CA ueber CB2";

}


int main()
{
	cout << "Projekt 14a_Mehrfachvererbung in Rautenform " << endl;
	CC exemplarC;

	// Lösung um an die Member von CA heranzukommen (Dank an Matthias Flege)
	// Cast eines Zeigers auf CC in Richtung Basisklasse ist eindeutig und daher erlaubt
	CB1* pCB1_exemplarC = &exemplarC; // Cast CC* auf CB1*
	CB2* pCB2_exemplarC = &exemplarC; // Cast CC* auf CB2*

	druckeCC(exemplarC, pCB1_exemplarC, pCB2_exemplarC);
	exemplarC.zuweisung(pCB1_exemplarC, pCB2_exemplarC);
	druckeCC(exemplarC, pCB1_exemplarC, pCB2_exemplarC);

	return 0;
}



