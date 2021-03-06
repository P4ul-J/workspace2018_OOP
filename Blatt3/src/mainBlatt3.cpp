/*!
\mainpage �bungsblatt 3, Polymorphie-�bung
Diese �bung demonstriert die Auswirkung, ob eine �berschriebene Funktion in der Basisklasse
virtuell ist oder nicht. Es stehen Klassen mit Z�hlerinkrement 1 und mit variablem Inkrement zur Verf�gung.
\author Grigat
 */


/************************************************************
 *                  Unit-Test f�r Blatt 3                   *
 ************************************************************/

// Bitte hier die aktuelle Aufgabe festlegen
#define AUFGABE_2b

// Ben�tigte Bibliotheken einbinden
#include <iostream>

// Google Test einbinden
#include "gtest/gtest.h"

#include "CCounter.hpp"
#include "CForwardCounter.hpp"
#include "CVariableCounter.hpp"

// Grundfunktionalit�t der Z�hler testen
#ifdef AUFGABE_1
TEST(TypeTest, CCounter) {
	CCounter counter;
	EXPECT_EQ(0, counter.getValue()) << "Wert von CCounter ist initial nicht 0!";
	int value = counter.getValue() + 10;
	counter.setValue(value);
	EXPECT_EQ(value, counter.getValue()) << "Wert von CCounter kann nicht gesetzt werden!";
	counter.count();
	EXPECT_EQ(value, counter.getValue()) << "CCounter zaehlt faelschlicherweise!";
}

TEST(TypeTest, CForwardCounter) {
	CForwardCounter counter;
	EXPECT_EQ(0, counter.getValue()) << "Wert von CForwardCounter ist initial nicht 0!";
	int value = counter.getValue() + 10;
	counter.setValue(value);
	EXPECT_EQ(value, counter.getValue()) << "Wert von CForwardCounter kann nicht gesetzt werden!";
	counter.count();
	EXPECT_EQ(value + 1, counter.getValue()) << "CForwardCounter zaehlt falsch!";
}

TEST(TypeTest, CVariableCounter) {
	CVariableCounter counter(5);
	EXPECT_EQ(0, counter.getValue()) << "Wert von CVariableCounter ist initial nicht 0!";
	int value = counter.getValue() + 10;
	counter.setValue(value);
	EXPECT_EQ(value, counter.getValue()) << "Wert von CVariableCounter kann nicht gesetzt werden!";
	counter.count();
	EXPECT_EQ(value + 5, counter.getValue()) << "CVariableCounter zaehlt falsch!";
}

// Jetzt kommen die Polymorphietests
TEST(PolymorphieTest, CForwardCounter) {
	CCounter *counter = new CForwardCounter;
	int value = counter->getValue();
	counter->count();
	EXPECT_EQ(value + 1, counter->getValue()) << "Polymorhpie mit CForwardCounter klappt nicht!";
	delete counter;
}

TEST(PolymorphieTest, CVariableCounter) {
	CCounter *counter = new CVariableCounter(5);
	int value = counter->getValue();
	counter->count();
	EXPECT_EQ(value + 5, counter->getValue()) << "Polymorphie mit CVariableCounter klappt nicht!";
}
#endif

// Es folgen die Tests f�r die zweite Aufgabe
#ifdef AUFGABE_2
TEST(OperatorTest, LessThan) {
	CCounter counter1;
	CCounter counter2;
	counter1.setValue(10);
	counter2.setValue(20);
	EXPECT_LT(counter1, counter2) << "Operator fuer kleiner als funktioniert nicht!";
	EXPECT_FALSE(counter2 < counter1) << "Operator fuer kleiner als funktioniert nicht!";
}

TEST(OperatorTest, GreaterThan) {
	CCounter counter1;
	CCounter counter2;
	counter1.setValue(10);
	counter2.setValue(20);
	EXPECT_GT(counter2, counter1) << "Operator fuer groesser als funktioniert nicht!";
	EXPECT_FALSE(counter1 > counter2) << "Operator fuer groesser als funktioniert nicht!";
}
#endif

// Hauptprogramm Google Test
#ifndef AUFGABE_2b
int main(int argc, char** argv) {
	// Google Test initialisieren
	testing::InitGoogleTest(&argc, argv);

	// alle Tests ausf�hren
	int ret = RUN_ALL_TESTS();

	// und Ergebnis anzeigen und zur�ckgeben
	//	std::cin.get();   // Konsole offen halten, in Eclipse auskommentieren
	return ret;
}
#endif

// Hauptprogramm f�r Programmentwicklung
#ifdef AUFGABE_2b

#include "derGroessere.hpp"

int main(){
//// F�gen Sie hier Ihre eigene main-Funktion f�r Aufgabe 2b ein
	CForwardCounter obj1;
	CVariableCounter obj2(-2);
	obj1.setValue(10);
	obj2.setValue(50);
	int x {0};
	while(obj2 > obj1){
		x++;
		obj2.count();
		obj1.count();
	}
	std::cout << "Nach " << x << " Schritten ist der CVariableCounter (" << obj2.getValue()<<
				") kleiner als der CForwardCounter("<< obj1.getValue()<<")"<<std::endl;

	/*
	 * CForwardCounter cf; cf.setValue(10);
	 * CVariableCounter cv(-2); cv.setValue(50);
	 * CCounter& big = istGroesser<CCounter>(cf, cv);
	 * big.count;
	 * std::cout << big.getValue() << std::endl;
	 * std::cout << cv.getValue() << std::endl;
	 */

	//std::cout << derGroessere(2,3) << std::endl;
}


#endif
