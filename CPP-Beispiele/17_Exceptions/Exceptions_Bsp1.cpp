/* 
    Exceptions_Bsp1.cpp
    Das Beispiel ist entnommen C++ für C-Programmierer, RRZN Hannover, 11. Auflage    

 */



#include <iostream>
#include <cstdlib>

using namespace std;


class XTag  { };        //Exception-Klasse 'Tag falsch'
class XMonat { };       //Exception-Klasse 'Monat falsch'

class Datum
{
	friend ostream &operator<<(ostream &, const Datum &);

public:
	Datum(unsigned ptag, unsigned pmonat, unsigned pjahr):
		tag(ptag), monat(pmonat), jahr(pjahr)
{
		if ((monat > 12) || (monat < 1))
			throw XMonat( );       //Monat falsch
		if (! tagOK( ) )
			throw XTag( );         //Tag falsch
}
private:
	bool            tagOK(); // Der Einfachheit halber ist von 1..31 alles erlaubt
	unsigned        tag, monat, jahr;
};

///////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& ost, const Datum & var)
{
	// Ausgabe
	ost << "Datum: " << var.tag << "." << var.monat << "." << var.jahr;
	return ost;
}

bool Datum::tagOK() // Der Einfachheit halber ist von 1..31 alles erlaubt
{return ((tag>0) && (tag<32)); 
}



int main()
{
	cout << "Projekt 17_Exceptions, Beispiel 1" << endl;
	while(1)
	{
		try
		{
			unsigned myTag, myMonat, myJahr;
			cout << "Geben Sie den Tag des Datums ein: ";
			cin >> myTag;
			cout  << "\n Geben Sie den Monat des Datums ein: ";
			cin >> myMonat;
			cout << "\nGeben Sie das Jahr des Datums ein: ";
			if (! (cin >> myJahr)) {
				cin.clear();
				cin.ignore(sizeof(myJahr), '\n');
			}
			Datum d1(myTag, myMonat, myJahr), // Exception, wenn Initialisierungswerte
					// unzulässig
					d2(13, 12, 1313);           // wird bei Exception nicht ausgeführt

			cout << d1 << endl << d2 << endl;
		}
		catch (class XTag&)
		{
			cerr << "Tag falsch!" << endl;
		}
		catch (const XMonat&)
		{
			cerr << "Monat falsch!" << endl;
		}

		Datum d3 (22, 5, 1944);

		cout << d3 << endl;                // wird ausgeführt

		//    system ("pause");
	} // Ende der While-Schleife

	return 0;
};    

