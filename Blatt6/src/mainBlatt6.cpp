/************************************************************
 *                  Unit-Test f�r Blatt 6                   *
 ************************************************************/
// Version 2016-03-31

// Bitte hier die aktuelle Aufgabe festlegen, 3 oder 4
#define AUFGABE_4

// Ben�tigte Bibliotheken einbinden
#include <iostream>

// Google Test einbinden
#include "gtest/gtest.h"

// Tests f�r Aufgabe 3
#ifdef AUFGABE_3

#include "CArray.hpp"
#include "XOutOfBounds.hpp"

// Test ob Zugriff auf Arrayelemente funktioniert
TEST(CArrayTest, Array) {
	CArray<unsigned int, 10> dict;
	for (unsigned int i = 0; i < 10; i++) {
		dict[i] = i;
	}
	for (unsigned int i = 0; i < 10; i++) {
		EXPECT_EQ(i, dict[i]);
	}
}

// Test ob Exception bei Bereichs�berschreitung wirklich geworfen wird
TEST(CArrayTest, Exception) {
	CArray<int, 10> dict;
	EXPECT_THROW(dict[10], XOutOfBounds) << "Exception wird bei zu grossem Index nicht geworfen!";
}

#endif

// Tests f�r Aufgabe 4
#ifdef AUFGABE_4

#include "CKnot.hpp"

// Test der Methoden f�r Attribut symbol
TEST(CKnotTest, symbol) {
	CKnot knot;
	EXPECT_EQ("", knot.getSymbol()) << "symbol ist initial nicht leer!";
	knot.setSymbol("Unit-Test");
	EXPECT_EQ("Unit-Test", knot.getSymbol()) << "symbol kann nicht gesetzt werden!";
}

// Test der Methoden f�r Attribut parent
TEST(CKnotTest, parent) {
	CKnot knot;
	EXPECT_EQ(0, knot.getParent()) << "parent ist initial nicht 0!";
	knot.setParent(6);
	EXPECT_EQ(6, knot.getParent()) << "parent kann nicht gesetzt werden!";
}

#endif

// Hauptprogramm
int main(int argc, char** argv) {
	// Google Test initialisieren
	testing::InitGoogleTest(&argc, argv);

	// alle Tests ausf�hren
	int ret = RUN_ALL_TESTS();

	// und Ergebnis anzeigen und zur�ckgeben
//	getchar();   // Prozess stoppen und Ergebnis anzeigen
	return ret;
}
