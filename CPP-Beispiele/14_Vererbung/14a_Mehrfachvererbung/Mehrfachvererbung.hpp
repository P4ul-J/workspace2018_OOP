/***************************************************************************
                          Mehrfachvererbung.hpp  -  Projekt 14a_Mehrfachvererbung
                             -------------------
    begin                : 01.10.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : grigat@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This file is used in the class "Informatik fuer Ingenieure" as        *
 *   a demo program. You can redistribute it and/or modify it              *
 *   under the terms of the GNU General Public License as published by     *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#pragma GCC diagnostic ignored "-Wwrite-strings"

// Basisklasse A


class CA
{ public: 
	CA(char a[100]="A default in CA",
			char b[100]="AB default in CA",
			char c[100]="ABC default CA"):
				A(a), AB(b), ABC(c)
{ };

	char* A;
	char* AB;
	char* ABC;
};


// CB1 und CB2 sind von CA abgeleitet
// CB1 und CB2 enthalten die Membervariablen BC und C
// CB1 enthält zusätzlich die Membervariablen Bsolo
class CB1 : public CA
{ public: 
	CB1(char a[100]="A default in CB1 fuer CA",
			char b[100]="AB default in CB1 fuer CA",
			char c[100]="ABC default in CB1 fuer CA",
			char d[100]="AB default in CB1",
			char e[100]="Bsolo default in CB1",
			char f[100]="ABC default in CB1"):
				CA(a, b, c), AB(d), Bsolo(e), ABC(f)
{ };

	char* AB;
	char* Bsolo;
	char* ABC;
};

class CB2 : public CA
{ public: 
	CB2(char a[100]="A default in CB2 fuer CA",
			char b[100]="AB default in CB2 fuer CA",
			char c[100]="ABC default in CB2 fuer CA",
			char d[100]="AB default in CB2",
			char e[100]="ABC default in CB2"):
				CA(a, b, c), AB(d), ABC(e)
{ };

	char* AB;
	char* ABC;
};

// CC ist von CB1 und CB2 abgeleitet und erbt daher
// zweimal von CA
class CC : public CB1, public CB2
{ public: 
	CC(char a[100]="ABC   default in CC fuer CC         ",
			char b[100]="A     default in CC fuer CA ueber C1",
			char c[100]="AB    default in CC fuer CA ueber C1",
			char d[100]="ABC   default in CC fuer CA ueber C1",
			char e[100]="A     default in CC fuer CA ueber C2",
			char f[100]="AB    default in CC fuer CA ueber C2",
			char g[100]="ABC   default in CC fuer CA ueber C2",
			char h[100]="AB    default in CC fuer CB1        ",
			char i[100]="Bsolo default in CC fuer CB1        ",
			char j[100]="ABC   default in CC fuer CB1        ",
			char k[100]="AB    default in CC fuer CB2        ",
			char l[100]="ABC   default in CC fuer CB2        "):
				CB1(b,c,d,h,i,j), CB2(e,f,g,k,l), ABC(a)
{ };
	void zuweisung(CB1* pmyCB1, CB2* pmyCB2);
	char* ABC;

};

void druckeCC(CC & myCC);


