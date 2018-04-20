/************************************************************
 *                  Unit-Test für Blatt 7                   *
 ************************************************************/

// Bitte hier die aktuelle Aufgabe festlegen
#define AUFGABE_2

// Benötigte Bibliotheken einbinden
#include <iostream>

// Google Test einbinden
#include "gtest/gtest.h"

#include "CDoubleHashing.hpp"

TEST(CDoubleHashingTest, SimpleHashing) {
	CDoubleHashing& hash = CDoubleHashing::getInstance();
	EXPECT_EQ(static_cast<unsigned int>(4), hash.hash(3, 4, 7, 0));
	EXPECT_EQ(static_cast<unsigned int>(1), hash.hash(1, 2, 7, 0));
	EXPECT_EQ(static_cast<unsigned int>(0), hash.hash(2, 1, 7, 0));
}

TEST(CDoubleHashingTest, DoubleHashing) {
	CDoubleHashing& hash = CDoubleHashing::getInstance();
	EXPECT_EQ(static_cast<unsigned int>(10), hash.hash(3, 4, 11, 0));
	EXPECT_EQ(static_cast<unsigned int>(5), hash.hash(3, 4, 11, 1));
	EXPECT_EQ(static_cast<unsigned int>(0), hash.hash(3, 4, 11, 2));
	EXPECT_EQ(static_cast<unsigned int>(6), hash.hash(3, 4, 11, 3));
}

// Hauptprogramm
int main(int argc, char** argv) {
	// Google Test initialisieren
	testing::InitGoogleTest(&argc, argv);

	// alle Tests ausführen
	int ret = RUN_ALL_TESTS();

	// und Ergebnis anzeigen und zurückgeben
//	std::cin.get();   // Prozess stoppen und Ergebnis anzeigen
	return ret;
}
