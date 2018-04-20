/************************************************************
 *                  Unit-Test für Blatt 5                   *
 ************************************************************/

// Benötigte Bibliotheken einbinden
#include <iostream>

// Google Test einbinden
#include "gtest/gtest.h"

#include "CEntry.hpp"

// Testen, ob das Symbol richtig gesetzt wird
TEST(CEntryTest, Symbol) {
	CEntry entry;
	entry.setSymbol("Test");
	EXPECT_EQ("Test", entry.getSymbol());
}

// Und testen, ob die Anzahl der Instanzen richtig zählt
unsigned int u_i = 0;
TEST(CEntryTest, CountInstances) {
	EXPECT_EQ(u_i, CEntry::getNumber());
	CEntry* entries[10];
	for (unsigned int i = 0; i < 10; i++) {
		entries[i] = new CEntry;
		EXPECT_EQ(i+1, CEntry::getNumber());
	}
	for (unsigned int i = 0; i < 10; i++) {
		delete entries[i];
		EXPECT_EQ(9-i, CEntry::getNumber());
	}
}

// Hauptprogramm
int main(int argc, char** argv) {
	// Google Test initialisieren
	testing::InitGoogleTest(&argc, argv);

	// alle Tests ausführen
	int ret = RUN_ALL_TESTS();

	// und Ergebnis anzeigen und zurückgeben
//	std::cin.get();  // Prozess stoppen und Ergebnis anzeigen
	return ret;
}
