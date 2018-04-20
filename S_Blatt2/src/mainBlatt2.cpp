/************************************************************
 *                  Unit-Test für Blatt 2                   *
 ************************************************************/

// Bitte hier die aktuelle Aufgabe festlegen
#define AUFGABE_3

// Benötigte Bibliotheken einbinden
#include <iostream>

// Google Test einbinden
#include "gtest/gtest.h"

// CCounter einbinden
#include "ccounter.hpp"

// bei Aufgabe 2 von Übung 2 auch noch die beiden Unterklassen einbinden
#ifdef AUFGABE_3
#include "CForwardCounter.hpp"
#include "CVariableCounter.hpp"
#endif

// Erst testen, ob Zähler initial 0 ist
TEST(CCounterTest, InitialZero) {
	CCounter ccounter;
	EXPECT_EQ(0, ccounter.getValue()) << "Zaehler ist nach Erstellung nicht 0!";
}

// Und testen, ob man den Wert setzen kann
TEST(CCounterTest, SetValue) {
	CCounter ccounter;
	int currValue = ccounter.getValue();
	ccounter.setValue(currValue + 10);
	EXPECT_EQ(currValue + 10, ccounter.getValue()) << "Zaehlerwert kann nicht gesetzt werden!";
}

// Jetzt testen, ob der Zähler auch zählt, bzw. bei Aufgabe_3 eben nicht zählt
TEST(CCounterTest, Counting) {
	CCounter ccounter;
	int value = ccounter.getValue();
#ifdef AUFGABE_2
	value++;
#endif
	ccounter.count();
	std::string msg;
#ifdef AUFGABE_2
	msg = "Zaehlerwert wird bei count() nicht um 1 erhoeht!";
#endif
#ifdef AUFGABE_3
	msg = "Zaehlerwert aendert sich bei count(), soll aber (nur) in Basisklasse ohne Funktion sein!";
#endif
	EXPECT_EQ(value, ccounter.getValue()) << msg;
}

// ab hier Tests für Aufgabe 3
#ifdef AUFGABE_3
// Initialwert des CForwardCounter testen
TEST(CForwardCounterTest, InitialZero) {
	CForwardCounter counter;
	EXPECT_EQ(0, counter.getValue()) << "Vorwaertszaehler ist nach Erstellung nicht 0!";
}

// Zählen des CForwardCounter testen
TEST(CForwardCounterTest, Counting) {
	CForwardCounter counter;
	int value = counter.getValue() + 1;
	counter.count();
	EXPECT_EQ(value, counter.getValue()) << "Zaehlerwert wird bei count() nicht um 1 erhoeht!";
}

// Initialwert des CVariableCounter testen
TEST(CVariableCounterTest, InitialZero) {
	CVariableCounter counter(2);
	EXPECT_EQ(0, counter.getValue()) << "Variabler Zaehler ist nach Erstellung nicht 0!";
}

// Zählen des CVariableCounter testen
TEST(CVariableCounterTest, Counting) {
	CVariableCounter counter(2);
	int value = counter.getValue() + 2;
	counter.count();
	EXPECT_EQ(value, counter.getValue()) << "Zaehlerwert des variablen Zaehlers wird nicht richtig erhoeht!";
}
#endif // Tests für Aufgabe 3

/*! Hauptprogramm main() mit Google Test (einkommentieren für den Google Test)
 *
 * Dieses Hauptprogramm führt den Google Test aus.
 * @param argc ist die Anzahl der Kommandozeilenparameter
 * @param argv ist ein Array aus Zeigern auf Kommandozeilenparameter
 * @return liefert 0, wenn alle Google Tests fehlerfrei durchlaufen
 */
int main(int argc, char** argv) {
	// Google Test initialisieren
	testing::InitGoogleTest(&argc, argv);

	// alle Tests ausführen
	int ret = RUN_ALL_TESTS();

	// und Ergebnis anzeigen und zurückgeben
//	std::cin.get();   // nicht erforderlich in Eclipse, da Konsole dort nicht schließt
	return ret;
}

///*! Hauptprogramm ohne Google Test (einkommentieren für erste Schritte und manuelle Tests)
// *
// */
//int main(){
//	CCounter myCounter;   // Zähler erzeugen
//	myCounter.count();    // Erstes Inkrement
//	myCounter.count();    // Weiteres Inkrement
//	myCounter.count();
//	std::cout << myCounter.getValue() << std::endl;
//	return 0;
//}
