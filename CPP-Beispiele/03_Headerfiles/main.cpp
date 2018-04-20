/***************************************************************************
                          main.cpp  in 03_Headerfiles
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

/***************************************************************************
 *                                                                          
 *   In diesem Programm wurde gegenüber o2_FunktionDefineConst ausgelagert:                                  
 *   die Deklarationen, d.h. die Beschreibung der Schnittstelle,in das 
 *   sogenannte Header-File ausgabe.h;
 *   die Definition von ausgabe(), d.h. die Implementation, in das File ausgabe.cpp.
 *   Hierdurch wird das Programm für den Anwender übersichtlicher. 
 *                                                                         *
 ***************************************************************************/
// #include <> sucht im include-Pfad, eingestellt in den Projekt-Properties
// #include "" sucht im aktuellen Verzeichnis, dann im include-Pfad

#include <iostream>   // enthält std::cout, std::endl
#include <cstdlib>    // C-Bibliothek mit system(), EXIT_SUCCESS
#include "ausgabe.hpp"  // Auch in ausgabe.cpp wird dieses include eingebunden.

using namespace std;


int main()
{
    cout << "Projekt 03_Headerfiles" << endl;
    ausgabe();
    
//    system("PAUSE");  // wartet auf Tastaturklick, so dass cmd Fenster geöffnet bleibt, in Eclipse nicht erforderlich
    return EXIT_SUCCESS;    
}
