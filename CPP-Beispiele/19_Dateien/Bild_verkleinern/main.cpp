/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : 01.12.2002
    copyright            : (C) 2002 by TUHH, Vision Systems
    email                : kricke@tu-harburg.de
    origin               : Informatik fuer Ingenieure II, WS 2002/03

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This file is used in the class "Informatik fuer Ingenieure" as        *
 *   a solution to an excercise. You can redistribute it and/or modify it  *
 *   under the terms of the GNU General Public License as published by     *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "cimage.h"
#include "cimagefile.h"

#include <cstdlib>

using namespace std;

int main()
{

	CImageFile inFile("test.pgm");
	CImageFile outFile("test_bak.pgm");
	
	CImage* image = inFile.load_image();
	               // intern wird new aufgerufen, 
	               // Speicher muss mit delete freigegegeben werden
	
	image->resize();
	
	outFile.save_image(image);
	
	delete image; // in load_image() wird new aufgerufen
	
	return EXIT_SUCCESS;
}
