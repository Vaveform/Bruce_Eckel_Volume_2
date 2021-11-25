#include "shapes.h"

namespace Polymorphic
{
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
}



namespace RTTI
{
	// Bad way - very long draw method in absract base class
	Shape::~Shape(){}

	void Shape::draw(std::ostream& os) const
	{
		const Circle* c_ptr = nullptr;
		const Square* sq_ptr = nullptr;
		if(c_ptr = dynamic_cast<const Circle*>(this))
		{
			os << "Radius of circle " << (void*)this << ": " << c_ptr->getR() << std::endl;
		}
		if(sq_ptr = dynamic_cast<const Square*>(this))
		{
			os << "Side of the square " << (void*)this << ": " << sq_ptr->getSide() << std::endl;
		}
	}

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

	double Circle::getR() const
	{
		return radius;
	}

	void Circle::setR(double r)
	{
		radius = r;
	}

	Square::Square(double a) : side(a) {}


	double Square::getSide() const
	{
		return side;
	}

	void Square::setSide(double a)
	{
		side = a;
	}
}
