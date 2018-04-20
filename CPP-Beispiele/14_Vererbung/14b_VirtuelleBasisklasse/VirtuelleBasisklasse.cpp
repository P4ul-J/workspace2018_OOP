/***************************************************************************
                          VirtuelleBasisklasse.cpp  -  Projekt 14b_VirtuelleBasisklasse
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
// Demonstration zu rautenförmiger Vererbung
//-------------------------------------------
// Um doppelte Erzeugung der obersten Basisklasse CA im Speicher zu vermeiden wird diese
// virtuell abgeleitet und dadurch beim Erzeugen eines Objekts vom Typ CC nur einmal angelegt.
//
// Die Klassen CB1 und CB2 sind diesmal _virtuell_ von CA abgeleitet.
// Klasse CC ist von CB1 und CB2 abgeleitet.
// Member ABC ist in den Klassen CA, CB1, CB2, CC definiert.
// Member AB ist in den Klassen CA, CB1, CB2 definiert.
// Member A ist in Klasse CA definiert.
// Member Bsolo ist in Klasse CB1 definiert.
// Die Initialisierung von CA muss im Konstruktor von CC erfolgen.
//
// Durch die virtuelle Ableitung ist nun die Klasse CA in Objekten vom Typ CC
// eindeutig enthalten und ihre Member können problemlos verwendet werden.
//
// Zu beachten ist lediglich, dass der Member A von CA nicht über die Adresse
// myCC.CB1::A oder myCC.CB2::A mit Daten beschrieben werden darf. Dies führt 
// beim nächsten Leseversuch zum Programmabbruch.


#include "VirtuelleBasisklasse.hpp"

#include <iostream>
#include <cstdlib>


#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

void druckeCC(CC & myCC)
{
	cout << "Membervariablen aus Objekt des Typs CC\n"

			<< "\nABC:"
			<< "\n         myCC.ABC >>>>> " << myCC.ABC
			<< "\n     myCC.CC::ABC >>>>> " << myCC.CC::ABC
			<< "\n    myCC.CB1::ABC >>>>> " << myCC.CB1::ABC
			<< "\n    myCC.CB2::ABC >>>>> " << myCC.CB2::ABC
			<< "\n     myCC.CA::ABC >>>>> " << myCC.CA::ABC   // durch virtual moeglich!

			<< "\nAB:"
			<< "\n     myCC.CB1::AB >>>>> " << myCC.CB1::AB
			<< "\n     myCC.CB2::AB >>>>> " << myCC.CB2::AB
			<< "\n      myCC.CA::AB >>>>> " << myCC.CA::AB    // durch virtual moeglich!

			<< "\n\nA:"
			<< "\n           myCC.A >>>>> " << myCC.A         // durch virtual moeglich!
			<< "\n      myCC.CB1::A >>>>> " << myCC.CB1::A
			<< "\n      myCC.CB2::A >>>>> " << myCC.CB2::A

			<< "\nBsolo:"
			<< "\n       myCC.Bsolo >>>>> " << myCC.Bsolo
			<< "\n  myCC.CB1::Bsolo >>>>> " << myCC.CB1::Bsolo

			<< "\n\n"<< endl;
}

void CC::zuweisung()
{
	ABC       ="ABC   nach Funktion zuweisung fuer CC         ";
	Bsolo     ="Bsolo nach Funktion zuweisung fuer CC         ";
	A         ="A     nach Funktion zuweisung fuer CC         ";
	CA::A     ="A     nach Funktion zuweisung fuer CA         ";
	//  CB1::A  ="A     nach Funktion zuweisung fuer CA ueber CB1"; // Diese Zeilen führen zu
	//  CB2::A  ="A     nach Funktion zuweisung fuer CA ueber CB2"; // Read-Fehler auf Speicher
	// myCC.A in drucke()
	CB1::AB   ="AB    nach Funktion zuweisung fuer CB1        ";
	CB1::ABC  ="ABC   nach Funktion zuweisung fuer CB1        ";
	CB2::AB   ="AB    nach Funktion zuweisung fuer CB2        ";
	CB2::ABC  ="ABC   nach Funktion zuweisung fuer CB2        ";

	cout << "\nZuweisung:\ndurch virtual CA ist das Mehrdeutigkeitsproblem CA behoben."
			<< "\n" << endl;
	CA::AB    ="AB    nach Funktion zuweisung fuer CA         ";
	CA::ABC   ="ABC   nach Funktion zuweisung fuer CA         ";

}


int main()
{
	cout << "Projekt 14b_VirtuelleBasisklasse zur Vermeidung von Mehrdeutigkeiten der Basisklasse" << endl;
	CC exemplarC;
	druckeCC(exemplarC);
	exemplarC.zuweisung();
	druckeCC(exemplarC);


	return 0;
}



