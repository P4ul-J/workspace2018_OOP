/* 
    Exceptions_Bsp2.cpp
    Das Beispiel ist entnommen C++ für C-Programmierer, RRZN Hannover, 11. Auflage 

    In diesem Beispiel sind die Exception-Klassen XMonat und XTag von XDatum abgeleitet.
    XDattum wiederum enaelt eine private Membervariable xtm, in der der falsch
    einegegebene Wert abgspeichert werden kann. Dieser Wert steht dann dem catch-Block
    zur Verfügung.   

 */


#include <iostream>
#include <cstdlib>

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
	cout << "Projekt 17_Exceptions, Beispiel 2" << endl;

	while (1) {
		try
		{
			unsigned myTag, myMonat, myJahr;
			cout << "Tag: ";
			cin >> myTag;
			cout << "\nMonat: ";
			cin >> myMonat;
			cout << "\nJahr: ";
			if (! (cin >> myJahr)) {
				cin.clear();
				cin.ignore(sizeof(myJahr), '\n');
			}
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

		//    system ("pause");
	} // Ende von while
	return 0;
};    
