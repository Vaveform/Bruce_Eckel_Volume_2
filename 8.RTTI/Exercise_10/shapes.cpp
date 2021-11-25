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


Triangle::Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

void Triangle::draw(std::ostream& os) const
{
	os << "Triangle " << (void*)this << " has a = " << a 
		<< " b = " << b << " c = " << c << std::endl;
}

double Triangle::getA() const { return a; }

double Triangle::getB() const { return b; }

double Triangle::getC() const { return c; }

void Triangle::setA(double _a) { a = _a; }

void Triangle::setB(double _b) { b = _b; }

void Triangle::setC(double _c) { c = _c; }

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

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

void Rectangle::draw(std::ostream& os) const
{
	os << "Rectangle " << (void*)this 
		<< " has length " << length 
		<< " and width " << width << std::endl;
}

double Rectangle::getLength() const{
	return length;
}

double Rectangle::getWidth() const
{
	return width;
}

void Rectangle::setLength(double l) { length = l; }

void Rectangle::setWidth(double d) { width = d; }



