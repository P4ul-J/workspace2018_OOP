/*!\file Flaeche
 * \brief Programm zum Rechnen mit Quadraten
 * 
 * In der Klasse Quadrat können Länge und Breite gesetzt werden.
 * Es existieren hierfür getter und setter Methoden.
 * Außerdem kann die Fläche mit der Methode area berechnet werden.
 */

#include <iostream>
#include "Quadrat.hpp"

int main(){ 
    std::cout << "Projekt Geometrie mit class Quadrat" << std::endl;
    Quadrat myQuadrat(2, 3);
    std::cout << "Die Breite des Quadrats betr�gt " << myQuadrat.getWidth() << std::endl;
    std::cout << "Die H�he des Quadrats betr�gt " << myQuadrat.getHeight() << std::endl;
    std::cout << "Die Fl�che des Quadrats betr�gt " << myQuadrat.area() << std::endl;
  
	return 0;
}
