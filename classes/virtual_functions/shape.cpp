/**
* Create an abstract class named Shape. This class should have three functions:
* a pure virtual print function that takes and returns a std::ostream, an 
* overloaded operator<< and an empty virtual destructor.
* 2b) Derive two classes from Shape: a Triangle, and a Circle. The Triangle 
*should have 3 Points as members. The Circle should have one center Point, and 
*an integer radius. Overload the print() function so the following program runs:
*2c) Given the above classes (Point, Shape, Circle, and Triangle), finish the 
*following program:
*/

#include <iostream>
#include <vector>

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;
 
public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{
 
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Shape
{

	public:
		virtual std::ostream& print(std::ostream& out) = 0;
	
		friend std::ostream& operator<<(std::ostream& out, Shape &shape)
		{
			return shape.print(out);
		}

		~Shape(){ }
};

class Triangle: public Shape
{
	private:
		Point m_point1;
		Point m_point2;
		Point m_point3;

	public:
		Triangle(Point p1, Point p2, Point p3)
			:m_point1(p1), m_point2(p2), m_point3(p3) { }

		virtual std::ostream& print(std::ostream& out)
		{
			out<< "Triangle("<<m_point1<<", "<<m_point2<<", "<<m_point3<<")";
			return out;
		}
};

class Circle:public Shape
{
	private:
		Point m_center;
		int m_radius;
	
	public:
		Circle(Point c, int r):m_center(c), m_radius(r) { }

		virtual std::ostream& print(std::ostream& out)
		{
			out<<"Circle("<<m_center<<", radius "<<m_radius<<")";
			return out;
		}
};

/*
//2b
int main()
{
    Circle c(Point(1, 2, 3), 7);
    std::cout << c << '\n';
 
    Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
    std::cout << t << '\n';
 
    return 0;
}
*/

//2c

int getLargestRadius(std::vector<Shape*> v)
{

}

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));
 
	// print each shape in vector v on its own line here
 	for(int i = 0; i< v.size(); i++)
		std::cout<<*(v[i])<<"\n";


       	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function
 
	// delete each element in the vector here
}
