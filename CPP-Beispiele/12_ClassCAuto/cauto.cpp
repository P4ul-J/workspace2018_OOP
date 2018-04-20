/***************************************************************************
                          cauto.cpp  -  description
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : wenzel@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

#include "cauto.hpp"

#include <iostream>

using namespace std;

// Standardkonstruktor
CAuto::CAuto() :
m_farbe("Schwarz")
{
    cout << "Auto standardmaessig initialisiert" << endl;
}



// Der Konstruktor mit einem Parameter
CAuto::CAuto(string farbe) :
m_farbe(farbe)
{
    cout << "Auto mit spezieller Farbe initialisiert" << endl;
}


// Destruktor, macht nichts
CAuto::~CAuto()
{
}


// Erste Funktion: Liefert die Farbe des Autos
string CAuto::farbe()
{
    return m_farbe;
}


// Zweite Funktion: Lackiert das Auto um
void CAuto::lackiere(string neuefarbe)
{
    m_farbe = neuefarbe;
}

