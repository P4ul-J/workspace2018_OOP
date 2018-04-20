/*!\file Flaeche
 * \brief Programm zum Rechnen mit Quadraten
 * 
 * In der Klasse Quadrat k√∂nnen L√§nge und Breite gesetzt werden.
 * Es existieren hierf√ºr getter und setter Methoden.
 * Au√üerdem kann die Fl√§che mit der Methode area berechnet werden.
 */

#include <iostream>
#include "Quadrat.hpp"

int main(){ 
    std::cout << "Projekt Geometrie mit class Quadrat" << std::endl;
    Quadrat myQuadrat(2, 3);
    std::cout << "Die Breite des Quadrats betr‰gt " << myQuadrat.getWidth() << std::endl;
    std::cout << "Die Hˆhe des Quadrats betr‰gt " << myQuadrat.getHeight() << std::endl;
    std::cout << "Die Fl‰che des Quadrats betr‰gt " << myQuadrat.area() << std::endl;
  
	return 0;
}
