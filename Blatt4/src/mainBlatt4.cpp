/************************************************************
 *                  Unit-Test f�r Blatt 4                   *
 ************************************************************/

// Ben�tigte Bibliotheken einbinden
#include <iostream>
#include <string>

// Google Test einbinden
#include "gtest/gtest.h"

#include "CEntry.hpp"
#include "CSwapper.hpp"

#define AUFGABE_1

#ifdef AUFGABE_1
TEST(CEntryTest, InitialEmpty) {
	CEntry entry;
	EXPECT_EQ("", entry.getSymbol()) << "Symbol ist initial nicht leer!";
}

TEST(CEntryTest, SetSymbol) {
	CEntry entry;
	std::string str = "TEST";
	entry.setSymbol(str);
	EXPECT_EQ(str, entry.getSymbol()) << "Symbol kann nicht gesetzt werden!";
}

// Hauptprogramm
int main(int argc, char** argv) {
	// Google Test initialisieren
	testing::InitGoogleTest(&argc, argv);

	// alle Tests ausf�hren
	int ret = RUN_ALL_TESTS();

	// und Ergebnis anzeigen und zur�ckgeben
//	std::cin.get();  // Prozess stoppen und Ergebnis anzeigen
	return ret;
}
#endif

#ifdef AUFGABE_2
int main(){
	int value1, value2;
	value1 = 1;
	value2 = 2;
	CSwapper test;
	test.swap_byValue(value1, value2); //is just handling local copies

	test.swap_byReference(value1, value2);

	test.swap_byPointer(&value1, &value2);
}
#endif

#ifdef AUFGABE_3
using namespace std;
int main(){
	int Zahlen[] = {11, 22, 33, 44, 55};
	cout << Zahlen[2] << endl; //expect: 33
	cout <<*(Zahlen+2) << endl; //expect: 33
	cout << *Zahlen+2 << endl; //expect: 13
	//guessed right



	/*
	 * Aufgabe 3b:
	 *
	 * array ist nichts anderes als eine tabelle mit einer spalte/vektor
	 * eine matrix ist eine mehrdimensionale tabelle, hier also eine tabello von spalten/vektoren
	 */
}
#endif
