/***************************************************************************
                          cauto.h  -  description
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : wenzel@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

#ifndef CAUTO_H
#define CAUTO_H

#include <string>

// Hier fehlt "using namespace std;". Warum?
// Antwort: Weil sonst jede Datei, die "auto.h"
// einbindet den namespace std; benutzt - das will man
// vielleicht gar nicht

class CAuto
{
	public:
		// Standardkonstruktor (eine Klasse kann mehrere Konstruktoren haben)
		CAuto();

		// Konstruktor
		CAuto(std::string farbe);
	
		// Destruktor
		~CAuto();
		
		// Funktion, liefert die Farbe des Autos, die gesetzt wurde
		std::string farbe();
		
		// Zweite Funktion
		void lackiere(std::string neuefarbe);
		
	private:
	
	    // Datenmitglied der Klasse, dort kann von "auﬂen" nicht zugegriffen werden
	    std::string m_farbe;
};

#endif // CAUTO_H

