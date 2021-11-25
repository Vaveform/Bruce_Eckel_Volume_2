#ifndef SHAPES_H
#define SHAPES_H


#include <iostream>
#include <memory>
#include <utility>



namespace Polymorphic{
	class Shape
	{
		public:
			virtual void draw(std::ostream&) const = 0;
			virtual ~Shape() = 0;
			friend std::ostream& operator<<(std::ostream& os, const Shape*);
			friend std::ostream& operator<<(std::ostream& os, const Shape&);
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

}


namespace RTTI
{
	class Shape
	{
		public:
			void draw(std::ostream&) const;
			virtual ~Shape() = 0;
			friend std::ostream& operator<<(std::ostream& os, const Shape*);
			friend std::ostream& operator<<(std::ostream& os, const Shape&);
	};

	class Circle : public Shape
	{
		private:
			double radius;
		public:
			Circle(double r = 0.0);
			double getR() const;
			void setR(double);
	};

	class Square : public Shape
	{
		private:
			double side;
		public:
			Square(double a = 0.0);
			double getSide() const;
			void setSide(double);
	};
}



#endif
