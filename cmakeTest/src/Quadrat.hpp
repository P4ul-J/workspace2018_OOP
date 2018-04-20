#pragma once

class Quadrat{
public:
	Quadrat(double height=0, double width=0);
	double getHeight();
	double getWidth();
	void setHeight(double);
	void setWidth(double);
	double area();

private:
	double m_height;
	double m_width;
};
