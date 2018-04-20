#include "Quadrat.hpp"
Quadrat::Quadrat(double height, double width)
          : m_height(height), m_width(width)  {}
double Quadrat::getHeight(){return m_height;}
double Quadrat::getWidth(){return m_width;}
void Quadrat::setHeight(double height){m_height=height;}
void Quadrat::setWidth(double width){m_width=width;}
double Quadrat::area(){return m_width*m_height;}

