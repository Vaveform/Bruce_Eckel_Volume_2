#ifndef SHAPES_H
#define SHAPES_H


#include <iostream>
#include <memory>
#include <utility>


class Shape
{
	public:
		virtual void draw(std::ostream&) const = 0;
		virtual ~Shape() = 0;
		friend std::ostream& operator<<(std::ostream& os, const Shape*);
		friend std::ostream& operator<<(std::ostream& os, const Shape&);
};


class Triangle : public Shape
{
	private:
		double a, b, c;
	public:
		Triangle(double _a = 0.0, double _b = 0.0, double _c = 0.0);
		virtual void draw(std::ostream&) const override;
		double getA() const;
		double getB() const;
		double getC() const;
		void setA(double);
		void setB(double);
		void setC(double);
};


class Circle : public Shape
{
	private:
		double radius;
	public:
		Circle(double r = 0.0);
		virtual void draw(std::ostream&) const override;
		double getR() const;
		void setR(double);
};

class Square : public Shape
{
	private:
		double side;
	public:
		Square(double a = 0.0);
		virtual void draw(std::ostream&) const override;
		double getSide() const;
		void setSide(double);
};

class Rectangle : public Shape
{
	private:
		double length;
		double width;
	public:
		Rectangle(double l = 0.0, double w = 0.0);
		virtual void draw(std::ostream&) const override;
		double getLength() const;
		double getWidth() const;
		void setLength(double);
		void setWidth(double);
};

#endif
