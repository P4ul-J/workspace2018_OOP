/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/


// Beispiel für Call By Value Parameterübergabe an die Funktion funktion



#include <iostream>
void funktion(int a)    // call by value, d.h. es wird eine lokale Kopie angelegt
{   
    std::cout << "Die lokale Variable a in funktion() vor Zuweisung ist a=" << a << std::endl;
    a = 9;
    std::cout << "Die lokale Variable a in funktion() nach Zuweisung ist a=" << a << std::endl;
}

int main()
{
	std::cout << "Projekt 06_CallByValue - Kopie der Parameter bei Funktionsaufruf" << std::endl;
    int a = 5;

    std::cout << "Die Variable a vor Aufruf von funktion() ist a=" << a << std::endl;
    funktion(a);    // call by value
    std::cout << "Die Variable a nach Ruecksprung aus funktion() ist a=" << a << std::endl;

    return 0;
    

}
