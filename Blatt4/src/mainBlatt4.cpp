/************************************************************
 *                  Unit-Test f�r Blatt 4                   *
 ************************************************************/

// Ben�tigte Bibliotheken einbinden
#include <iostream>
#include <string>

// Google Test einbinden
#include "gtest/gtest.h"

#include "CEntry.hpp"

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
