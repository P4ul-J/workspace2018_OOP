/***************************************************************************
                          cimage.h  -  description
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


#ifndef CIMAGE_H
#define CIMAGE_H

/**
Diese Klasse kann die Daten von rechteckigen Bildern im Speicher halten
und diese Bilder um den Faktor 2 verkleinern (CImage::resize()).
*/
class CImage
{
	public:
		// class constructor
		CImage(unsigned int width = 0, unsigned int height = 0);
		// class destructor
		~CImage();
		char* begin(); // liefert Zeiger auf Beginn der Bilddaten
		char* end(); // liefert Zeiger auf Ende der Bilddaten
	 							// (das erste Element nach dem letzten gültigen)
         						// (kann als Abbruchbedingung in Schleifen
               					// benutzt werden) 
		unsigned int width();
		unsigned int height();
		void resize(); // verkleinert ein Bild um Faktor 2
		
	private:
		unsigned int m_width;
		unsigned int m_height;
		char * m_data;
};

#endif // CIMAGE_H

