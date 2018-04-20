/***************************************************************************
                          main.cpp  -  Projekt 12_ClassCAuto
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : wenzel@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

#include <iostream>
#include "cauto.hpp"
using namespace std;

int main()
{
  CAuto erstwagen;
  CAuto zweitwagen("Blau");
  
  cout << "Mein Erstwagen  hat die Farbe " << erstwagen.farbe()  << endl;
  cout << "Mein Zweitwagen hat die Farbe " << zweitwagen.farbe() << endl;
  
  cout << "Lackiere Erstwagen um...";
  
  erstwagen.lackiere("Rot");
  
  cout << "fertig. Nun hat mein Erstwagen die Farbe " << erstwagen.farbe() << endl;
  
  return 0;
}
