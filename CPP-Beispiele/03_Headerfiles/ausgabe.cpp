/***************************************************************************
                          ausgabe.cpp  -  description
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/
// Header-Dateien *.hpp enthalten Deklarationen und Makros
// Header-Dateien werden vor jeder anderen Datei inkludiert, noch vor jeder anderen Deklaration
// #include <...>     Dateien <> werden im include-Pfad gesucht (Project->Properties)
// #include "..."     Dateien "" werden vom aktuellen Verzeichnis aus gesucht, hier 03_Headerfiles
#include "ausgabe.hpp"
#include <iostream>

using namespace std;   // Ersparnis von Schreibarbeit, z.B. cout statt std::cout, endl statt std::endl

void ausgabe()
{
	// Woher ist Meine_Tolle_Int_Zahl bekannt? Es ist eine Konstante aus der
	// Header-Datei ausgabe.hpp, die oben mittels #include in die vorliegende Datei kopiert wurde
	// Umschalten zwischen cpp und hpp in Eclipse mit Strg-TAB
    cout << " Ausgabe der Konstante Meine_Tolle_Int_Zahl durch Funktion ausgabe() in ausgabe.cpp: "
    		<< Meine_Tolle_Int_Zahl << " ist eine tolle Zahl" << endl;
}

