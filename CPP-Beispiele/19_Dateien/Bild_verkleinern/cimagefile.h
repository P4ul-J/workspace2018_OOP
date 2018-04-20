/***************************************************************************
                          cimagefile.h  -  description
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



#ifndef CIMAGEFILE_H
#define CIMAGEFILE_H

#include "cimage.h"

#include <string>

/**
Diese Klasse kann Graubilder im *.pgm Format lesen und schreiben.
*/

class CImageFile
{
	public:
		// class constructor
		CImageFile(const std::string& filename);
		// class destructor
		~CImageFile();
		CImage* load_image();
		void save_image(CImage* outImage);
		
	private:
		const std::string m_filename;
};

#endif // CIMAGEFILE_H

