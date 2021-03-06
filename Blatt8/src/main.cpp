/************************************************************
 *                  Unit-Test f�r Blatt 8                   *
 ************************************************************/

// Bitte hier die aktuelle Aufgabe festlegen
#define AUFGABE_2

// Ben�tigte Bibliotheken einbinden
#include <iostream>

// Google Test einbinden
#include "gtest/gtest.h"

// Unit-Tests f�r Aufgabe 1
#ifdef AUFGABE_1

#include <windows.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include "CArray.hpp"

// Testen der Suche mit einer festen Folge
TEST(CArrayTest, FixNumbers) {
	CArray<int, 10> dict;
	for (int i = 0; i < 10; i++) {
		dict[i] = 2*i;
	}
	// einen vorhandenen Wert suchen
	EXPECT_EQ(static_cast<long int>(5), dict.find(10)) << "Wert 10 wurde nicht an der richtigen Stelle gefunden";
	// einen nicht vorhandenen Wert suchen
	EXPECT_EQ(static_cast<long int>(-1), dict.find(5)) << "Nicht vorhandener Wert wurde faelschlicherweise gefunden";
}

// Testen ob die Sortierung richtig implementiert wurde
TEST(CArrayTest, Sort) {
	CArray<int, 10> dict;
	std::vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int r = rand();
		dict[i] = r;
		vec.push_back(r);
	}
	std::sort(dict.begin(), dict.end());
	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < 10; i++) {
		ASSERT_EQ(vec[i], dict[i]) << "Sortierung funktioniert nicht";
	}
}
#endif

#ifdef AUFGABE_2

#include <sstream>
#include "CBaum.hpp"

TEST(CBaumTest, BaumTest) {
	CBaum<int> baum;
	baum.insert(3);
	baum.insert(7);
	baum.insert(5);
	baum.insert(1);
	baum.insert(0);
	baum.insert(2);
	baum.insert(4);
	baum.insert(6);
	std::stringstream inorder;
	baum.inorder(inorder);
	EXPECT_EQ("01234567", inorder.str()) << "inorder falsch";
	std::stringstream preorder;
	baum.preorder(preorder);
	EXPECT_EQ("31027546", preorder.str()) << "preorder falsch";
	std::stringstream postorder;
	baum.postorder(postorder);
	EXPECT_EQ("02146573", postorder.str()) << "postorder falsch";
}

#endif

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
