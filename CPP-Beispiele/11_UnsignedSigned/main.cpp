/***************************************************************************
                          main.cpp  -  Project 11_UnsignedSigned
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : wenzel@tu-harburg.de
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

// Beispiel für Überlauf in vorzeichenbehafteten und vorzeichenlosen Datentypen


#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  
  // Vorzeichenbehaftete und vorzeichenlose Datentypen
  
  // Ein Byte
  char i=125;
  
  // Noch eins
  unsigned char j=i;
  
  // Die Werte werden 5 Mal erhöht
  for(int k=0; k<5; ++k){
  
    // Char - Datentypen werden als Buchstaben ausgegeben.
    // Hier soll allerdings eine Zahl angezeigt werden.
    // Deshalb wird der Datentyp "gecastet" mit static_cast<int>
    cout << "i ist " << static_cast<int>(i) << "; ";
    cout << "j ist " << static_cast<int>(j) << endl;
    
    ++i;
    ++j;
  }
  
//  system("PAUSE");
  return EXIT_SUCCESS;
}
