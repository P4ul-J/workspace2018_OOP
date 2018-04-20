/***************************************************************************
                          main.cpp  -  Projekt 01_HelloWorld
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03
	last modified		 : Rosenstiel 2008
 ***************************************************************************/

 /**************************************************************************
 Gegenstand dieses Hello-World Beispiels:
 #include <...>
 using namespace
 Ausgabe mit cout in ein DOS-Fenster
 Programmausführung anhalten um Ausgabetext sichtbar zu halten
 ***************************************************************************/

// Durch #include <...> wird im include-Pfad gesucht (Project->Properties)
// Bei #include   "..." wird im Verzeichnis des aktuellen Files gesucht, dann im include-Pfad

#include <iostream>     // Ein- und Ausgaberoutinen, z.B. std::cout, std::cin, std::endl
#include <cstdlib>      // EXIT_SUCCESS und system()

using namespace std;    // Namensraum std wird voreingestellt.
                        // Ohne diese Zeile müsste es z.B. std::cout statt cout und std::endl  statt endl heissen.
                        
int main()              // das Hauptprogramm heisst immer main
{             
    cout << "Projekt 01_HelloWorld" << endl;        // endl beginnt eine neue Zeile.
    cout << 4 << " ist eine tolle Zahl" << endl;
    
//    system("PAUSE");    // MS-DOS Befehl, hält Programmausführung an;
                          // sonst schließt das Ausgabefenster sofort (nicht erforderlich bei Eclipse)

    return EXIT_SUCCESS;    
    

}
