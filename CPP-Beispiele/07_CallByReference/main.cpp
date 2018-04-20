/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

// Beispiel für Parameterübergabe mittels Call By Reference


#include <iostream>

void funktion(int& a)
{         // int& a  ist der Kern dieses Beispiels, lokale Variable a ist Referenz auf int-Variable.
	      // Referenz a wird mit dem Aufrufparameter initialisiert und
          // ist innerhalb der Funktion "funktion()" ein anderer Name für den
          // Aufrufparameter, keine Kopie! Neuer Speicherplatz wird für a nicht
          // erzeugt. Die Referenz a lebt bis zum Ende des
          // Funktionsblocks.
    std::cout << "Die lokale Zahl a in funktion() vor Zuweisung ist a=" << a << std::endl;
    a = 9;
    std::cout << "Die lokale Zahl a in funktion() nach Zuweisung ist a=" << a << std::endl;
}

int main()
{
	std::cout << "Projekt 07_CallByReference" << std::endl;
    int a = 5;
    
    std::cout << "Die Variable a vor Aufruf von funktion() ist a=" << a << std::endl;
    funktion(a);    // call by reference, vorgegeben durch int& in Definition von funktion()
    std::cout << "Die Variable a nach Ruecksprung aus funktion() ist a=" << a << std::endl;
    
    return 0;
}
