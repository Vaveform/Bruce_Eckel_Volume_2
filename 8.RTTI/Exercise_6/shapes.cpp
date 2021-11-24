#include "shapes.h"


Shape::~Shape(){}

std::ostream& operator<<(std::ostream& os, const Shape* p_shape)
{
	p_shape->draw(os);
	return os;
}

std::ostream& operator<<(std::ostream& os, const Shape& r_shape)
{
	r_shape.draw(os);
	return os;
}



Circle::Circle(double r) : radius(r){}



void Circle::draw(std::ostream& os) const 
{
	os << "Radius of circle " << (void*)this << ": " << this->radius << std::endl;
}


double Circle::getR() const
{
	return radius;
}

void Circle::setR(double r)
{
	radius = r;
}

Square::Square(double a) : side(a) {}



void Square::draw(std::ostream& os) const
{
	os << "Side of the square " << (void*)this << ": " << this->side << std::endl;
}


double Square::getSide() const
{
	return side;
}

void Square::setSide(double a)
{
	side = a;
}
