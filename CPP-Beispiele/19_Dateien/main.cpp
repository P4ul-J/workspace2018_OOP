/***************************************************************************
                          main.cpp  -  Projekt 19_Dateien
                             -------------------
    begin                : 01.12.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This file is used in the class "Informatik fuer Ingenieure" as        *
 *   a solution to an excercise. You can redistribute it and/or modify it  *
 *   under the terms of the GNU General Public License as published by     *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <fstream>
#include <iostream>
#include <cstdlib>

const int breite = 255;
const int hoehe = 128;
const int max_val = 255;

const char* dateiname = "test.pgm";

using namespace std;

int main()
{
	cout << "Projekt 18_Dateien" << endl;

	ofstream bild_header(dateiname, ios::out | ios::trunc | ios::binary);
	// oeffnet eine Datei fuer Schreibzugriff (ios::out) (default für ofstream)
	// und loescht den Inhalt einer evtl. vorhandenen Datei (ios::trunc)
	// Der Binaermodus (ios::binary) bewirkt, dass beim Schliessen der Datei
	// kein Zeilenumbruch eingefügt wird, der bei MS-DOS durch die
	// beiden ASCII-Zeichen CR LF representiert wird. Die *.pgm
	// Spezifikation erlaubt aber nur *ein* Zeichen Whitespace
	// nach dem Header.

	if (!bild_header) {
		cout << "Kann " << dateiname << " nicht fuer Header oeffnen " << endl;
		system("pause");
		return EXIT_FAILURE;

	}

	bild_header << "P5" << char(10);
	bild_header << breite << " " << hoehe << " " << max_val << char(10);
	//Dies ist der Header fuer eine *.pgm Datei

	bild_header.close();

	ofstream bild_daten(dateiname, ios::app | ios::binary);
	// oeffnet eine Datei fuer Schreibzugriff, haengt an das Ende einer
	// bestehenden Date (ios::app),
	// schaltet auf Binaermodus (ios::binary)

	if (!bild_daten) {
		cout<< "Kann " << dateiname << " nicht fuer Daten oeffnen " << endl;
		system("pause");
		return EXIT_FAILURE;

	}


	for (int y = 0; y < hoehe; y++){
		for (int x = 0; x < breite; x++){
			bild_daten.put( (x==y)? 255 : x );
			// put() schreibt Daten byteweise
		}

	}

	bild_daten.close();
	cout << "Datei " << dateiname  << " erfolgreich geschrieben." << endl;


	return EXIT_SUCCESS;
}
