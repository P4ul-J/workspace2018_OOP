/***************************************************************************
                          main.cpp  -  Projekt 08_CallByPointer
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

// Beispiel für Parameterübergabe durch Übergabe der Adresse, d.h. durch Zeiger


#include <iostream>
#include <cstdlib>

using namespace std;

void funktion(int* b)    // Parameterübergabe durch Zeiger, der die Adresse 
                         // des Parameters enthält. 

{
    cout << "In funktion():  Die Adresse (d.h. der Zeiger) b ist " << hex
        << b << endl;

    cout << "In funktion():  Der alte Inhalt *b ist " << *b << endl;
    *b = 9;
    cout << "In funktion():  Der neue Inhalt *b ist " << *b << endl;
}

int main()
{
    cout << "Projekt 08_CallByPointer" << endl;
    int a = 5;
    
    cout << "Vor Aufruf von funktion(): Der Inhalt von a ist " << a << endl;
    cout << "Vor Aufruf von funktion(): Die Adresse &a von a ist " << hex << &a << endl;
    funktion(&a);   // uebergebe Pointer
    cout << "Nach Rücksprung aus funktion():  Der Inhalt von a ist " << a << endl;
    cout << "Nach Rücksprung aus funktion():  Die Adresse &a von a ist " << hex << &a << endl;
    
//    system("PAUSE");
    return EXIT_SUCCESS;
}
