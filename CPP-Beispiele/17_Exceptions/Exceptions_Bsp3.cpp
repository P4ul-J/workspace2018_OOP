/* 
    Exceptions_Bsp3.cpp
    Dieses Beispiel erweitert Exceptions_Bsp2.cpp dahingeghend, dass die Korrektheit
    der Eingabe ebenfalls ueber Exceptions sichergestellt wird. Dazu werden die
    die Standard-Exceptions von <iostream> benutzt.

    vgl. Bjarne Stroustrup, "Die C++ Programmiersprache", 4. Auflage, Kap. 21.3.6

 */



#include <iostream>
#include <cstdlib>
#include <limits.h>


using namespace std;

class XDatum
{
public:
	XDatum (unsigned tm) : xtm (tm) {}

	unsigned wert () const { return xtm;}

private:
	unsigned xtm;
};

class XTag: public XDatum
{
public:
	XTag (unsigned t): XDatum(t) { }
};

class XMonat: public XDatum
{
public:
	XMonat (unsigned t): XDatum(t) {}
};

class Datum
{
public:
	Datum(unsigned ptag, unsigned pmonat, unsigned pjahr):
		tag(ptag), monat(pmonat), jahr(pjahr)
{
		if ((monat < 1) || (monat > 12))
			throw XMonat(monat);
		if (! tagOK( ) )
			throw XTag(tag);
}
private:
	bool            tagOK();
	unsigned        tag, monat, jahr;
};

bool Datum::tagOK()
{
	return ((tag > 0) && (tag < 32)); // Der Einfachheit halber ist von 1..31 alles erlaubt
}

int main()
{
	cout << "Projekt 17_Exceptions, Beispiel 3" << endl;

	cin.exceptions(ios_base::badbit | ios_base::failbit);
	// Mit diesem Aufruf wird festgelegt, wann
	// Ausnahmen geworfen werden.
	// * badbit: Ausnahme, wenn der Stream kaputt ist
	// * failbit: Ausnahme, wenn die Zuweisung an eine
	//              Variable fehlschlägt, z. B. weil
	//              die Typen inkompatibel sind

	// * eofbit: Ausnahme, wenn end of file (EOF) erreicht ist
	//          (wird hier nicht verwendet)
	while (1) {
		try
		{
			unsigned myTag, myMonat, myJahr;
			cout << "Tag: ";
			cin >> myTag;
			cout << "\nMonat: ";
			cin >> myMonat;
			cout << "\nJahr: ";

			Datum d1(myTag, myMonat, myJahr); // Exception, wenn Initialisierungswerte
			// unzulässig

		}
		catch (const XTag &xt)
		{
			cerr << "Tag falsch: " << xt.wert() << endl;
		}
		catch (const XMonat &xm)
		{
			cerr << "Monat falsch: " << xm.wert() << endl;
		}
		catch (const XDatum&)
		{
			cerr << "Datum falsch!" << endl;
		}
		catch (ios_base::failure&){
			cerr << "\nungueltige Eingabe! " << endl;
			cin.clear();
			cin.ignore(INT_MAX);

		}

		//    system ("pause");
	} // Ende von while
	return 0;
};    
