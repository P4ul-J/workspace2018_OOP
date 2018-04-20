/***************************************************************************
                          main.cpp  -  Projekt 09_ForIfWhileSwitch
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : wenzel@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

// Dieses Beispiel demonstriert einige Kontrollstrukturen, wie z.B.
// for, if, while, switch

#include <iostream>

using namespace std;

int main()
{
  // Kontrollstrukturen
  
  // 1. For-Schleife und If - Abfrage
  
  cout << "For-Schleife: " << endl;
  
  // Variable i ist nur innerhalb der For-Schleife bekannt
  for(int i=0; i<10 ; i++){
    cout << i << " ";
    
    // If - Abfrage
    if ( i == 7 ){
        cout << "...jetzt ist i gerade 7... ";
    }
  }
  
  // Zeilenende und Leerzeile
  cout << endl << endl;
  
  // 2. Switch - Abfrage und While - Schleife
  
  // Neue Variable i, die alte galt nur oben in der for-Schleife
  int i=0;
  
  // While - Schleife
  while (i<10){

    // Switch - Abfrage
    switch(i){
    
    case 1:
        cout << "i ist gerade 1" << endl;
        break;
        
    case 2:
        cout << "i ist gerade 2" << endl;
        break;
        
    case 3:
        // Achtung: Hier fehlt das "break", d.h., es wird nicht
        // aus der switch - Schleife herausgesprungen!
    	// Eclipse gibt eine Warnung aus, denn es könnte unbeabsichtigt sein.
        cout << "i ist gerade 3" << endl;
        
    case 4:
        // Dieser Fall wird auch bei i==3 ausgeführt
        cout << "i ist gerade 3 oder 4, nämlich i=" << i << endl;
        break;
        
    default:
        cout << "Dieser Fall wird nicht abgefangen: i ist naemlich " << i << endl;
        break;
    }    // end of switch(i)
    
    i++;
  }      // end of while(i<10)
  
  return 0;
}
