/***************************************************************************
                          cimagefile.cpp  -  description
                             -------------------
    begin                : 01.12.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

#include "cimagefile.h" // class's header file
#include <fstream>
#include <iostream>

using namespace std;

// class constructor
CImageFile::CImageFile(const string& filename):
	m_filename(filename)
{
}

// class destructor
CImageFile::~CImageFile()
{
	// insert your code here
}

CImage* CImageFile::load_image()
{
	ifstream infile(m_filename.c_str(), ios::binary);
	if(!infile){
 		std::cerr << "Fehler beim oeffnen der Datei " << m_filename.c_str() << std::endl;
 		return NULL;
 	}
	string magic;
	infile >> magic;
	unsigned int width;
	infile >> width;
	unsigned int height;
	infile >> height;
	unsigned int maxValue;
	infile >> maxValue;
	infile.get(); // Das LF Zeichen nach maxValue muss
 					// manuell uebersprungen werden
	CImage* inImage = new CImage(width, height);
	infile.read(inImage->begin(), width * height);
		// read (Ch* p, streamsize n) liest n Zeichen
		// eines Streams und schreibt diese Zeichen an die Adresse p
 	infile.close();
	return inImage;
}

void CImageFile::save_image(CImage* outImage)
{
	ofstream outfile(m_filename.c_str(), ios::binary | ios::trunc);
	if(!outfile){
 		cerr << "Fehler beim oeffnen der Datei " << m_filename.c_str() << endl;
 		return;
 	}
	outfile << "P5\n";
	outfile << outImage->width() << " ";
	outfile << outImage->height() << char(10);
	outfile << 255 << char(10); // Achtung: hier *nicht \n verwenden.
								// \n fuegt unter MS-DOS zwei Zeichen ein (CR LF),
								// aber es ist nur ein Zeichen erlaubt (LF).
								// LF hat ist ASCII Zeichen 10, daher kann man
								// mit char(10) ein LF Zeichen erzeugen.
	outfile.write(outImage->begin(), outImage->width() * outImage->height());
		// write (Ch* p, streamsize n) schreibt n Zeichen ab der Adresse p
		// an einen Stream
	outfile.close();
	return;
}
