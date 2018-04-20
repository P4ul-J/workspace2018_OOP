/***************************************************************************
                          main.cpp  -  Projekt 10_DatentypenSizeof
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : wenzel@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
  cout << "Projekt 10_DatentypenSizeof" << endl;
  // Datentypen und sizeof - operator
  char a='a';
  cout << "Character a ist " << a << " für ASCII Nr. " << static_cast<int>(a)  << "; ein char    ist " << sizeof(a) << " Byte lang" << endl;
  cout << "Character A ist " << 'A' << " für ASCII Nr. " << static_cast<int>('A')  << "; ein char    ist " << sizeof(a) << " Byte lang" << endl;

  // Integer b wird nicht initialisiert, der Wert ist also undefiniert
  // (Der Wert, der dort vorher im Speicher war, nur im release-Modus)
  int b;
  cout << "Integer   b ist " << b << "; ein Integer ist " << sizeof(b) << " Bytes lang" << endl;
  float c=1.0;
  cout << "Float     c ist " << c << "; ein Float   ist " << sizeof(c) << " Bytes lang" << endl;
  double d=c;
  cout << "Double    d ist " << d << "; ein Double  ist " << sizeof(d) << " Bytes lang" << endl;
  char e = 'e';
  cout << "char      e ist " << e << "; ein char    ist " << sizeof(e) << " Byte lang" << endl;
  unsigned char f = 'f';
  cout << "unsigned char f ist " << f << "; ein unsigned char ist " << sizeof(f) << " Byte lang" << endl<<endl;


  
  // Hier kommen als Anwendungsbeispiel noch einige weitere Typen und zugehörige Literale:
  
  double mydouble = 1.23E-6;
  long long myLongLong = 1234LL;
  long mylong = 1234L;
  int myInt = 1234;
  short myshort = 1234;

  unsigned long ul = 1234UL;
  unsigned int ui = 1234U;
  unsigned short us = 1234U;
  
  // Alle Ganzzahlen (short, int, long und deren unsigned Varianten
  // können auch binär, oktal oder hexadezimal ein- und ausgegeben werden.
  // Suffix l oder L für long, u oder U für unsigned, ll oder LL für long long
  // Präfix 0b oder 0B für binär, 0 für Oktal, 0x oder 0X für hexadezimal

  //short, int, long sind per default signed.
  //"signed" in signed short, signed int, signed long kann also entfallen
  
  cout << "Long Long mylong  ist " << myLongLong <<   "; ein long long      ist  " << sizeof(myLongLong) << " Bytes lang" << endl;
  cout << "Long     mylong   ist " << mylong     <<   "; ein long           ist  " << sizeof(mylong) << " Bytes lang" << endl;
  cout << "Integer  myInt    ist " << myInt <<        "; ein int            ist  " << sizeof(myInt) << " Bytes lang" << endl;
  cout << "Short    myshort  ist " << myshort <<      "; ein short          ist  " << sizeof(myshort) << " Bytes lang" << endl;
  cout << "Unsigned short us ist " << us <<           "; ein unsigned short ist  " << sizeof(us) << " Bytes lang" << endl;
  cout << "Unsigned int  ui  ist " << ui <<           "; ein unsigned int   ist  " << sizeof(ui) << " Bytes lang" << endl;
  cout << "Unsigned long ul  ist " << ul <<           "; ein unsigned long  ist  " << sizeof(ul) << " Bytes lang" << endl;

  return 0;
}
