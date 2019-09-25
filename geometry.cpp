#include <iostream>

class Polygon {
	public:
		virtual double area() = 0;
};

class Rectangle : public Polygon {
		int width, height;
	public:
		double area() { return width*height; }
		Rectangle(int a, int b) : width(a), height(b) { }
};

class Circle : public Polygon {
		const double pi = 3.14;
		double radius;
	public:
		Circle(double r) : radius(r) { }
		double area() { return pi * radius * radius; }
};

class Square : public Rectangle {
	public:
		Square(int a) : Rectangle(a, a) { }
};

int main(int argc, const char** argv){
	Rectangle rect(5,4);
	Square sq(5);
	Rectangle rect1(5,5);

	Circle circ(5);

	Polygon* poly;

	std::cout << "rect: " << rect.area() << std::endl;
	std::cout << "sq: " << sq.area() << std::endl;
	std::cout << "rect1: " << rect1.area() << std::endl;
	std::cout << "circ: " << circ.area() << std::endl;

	poly = new Rectangle(5, 4);
	std::cout << "poly: " << poly->area() << std::endl;
	poly = new Circle(5);
	std::cout << "poly: " << poly->area() << std::endl;
}
