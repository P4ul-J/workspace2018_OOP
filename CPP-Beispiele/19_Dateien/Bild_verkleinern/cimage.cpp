/***************************************************************************
                          cimage.cpp  -  description
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



#include "cimage.h" // class's header file

// class constructor
CImage::CImage(unsigned int width, unsigned int height):
	m_width(width),
	m_height(height),
	m_data(new char[width * height])
{
}

// class destructor
CImage::~CImage()
{
	delete[] m_data;
}

char* CImage::begin()
{
	return m_data;
}

char* CImage::end()
{
	return m_data + (m_width * m_height);
}

unsigned int CImage::width()
{
	return m_width;
}

unsigned int CImage::height()
{
	return m_height;
}

void CImage::resize()
{
	unsigned int smallWidth = m_width >> 1;	// "shift rechts" operator >>
 											// bewirkt Division durch 2 
	unsigned int smallHeight = m_height >> 1;
	char * smallImage = new char[smallWidth * smallHeight];
	
	for (unsigned int y = 0; y < smallHeight; ++y){
 		for (unsigned int x = 0; x < smallWidth; ++x){
   			smallImage[y*smallWidth + x] = m_data[(y << 1)*m_width + (x << 1)];
   											// "shift links" operator <<
   											// bewirkt Multiplikation mit 2
			// Die Bilder sind jeweils in einem zusammenhängenden Speicherbereich
			// zeilenweise abgelegt. Um ein Bild um den Faktor 2 zu verkleinern,
			// wird der Wert jedes 2. Pixels des Quellbildes in das Zielbild
			// kopiert.
   		}
	}
	
	m_width = smallWidth;
	m_height = smallHeight;
	delete[] m_data;
	m_data = smallImage;
	
	return;
}
