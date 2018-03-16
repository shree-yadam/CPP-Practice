/* class point2d with members m_x and m_y. a constructor and print function*/
/*	1b. Add a member function named distanceTo. distanc ebetween (x1,y1) and 
	(x2.y2) = sqrt((x1-x2)*(x1-x2) + (y1-y1)*(y1-y2)) 
*/

#include <iostream>
#include <cmath>

class Point2d
{
	private:
		double m_x, m_y;
	public:
		Point2d(double x = 0.0, double y = 0.0):m_x(x), m_y(y) { }
	
		void print()
		{
			std::cout<<"Point2d ("<<m_x<<", "<<m_y<<")\n";
		}

		double distanceTo(const Point2d &point)
		{
			return (sqrt((m_x-point.m_x)*(m_x-point.m_x) + 
					(m_y-point.m_y)*(m_y-point.m_y)));
		}
};

int main()
{
	Point2d first;
	Point2d second(3.0,4.0);
	
	first.print();
	second.print();

	std::cout<<"Distance between two points: "<<first.distanceTo(second)<<"\n";

	return 0;
}	
