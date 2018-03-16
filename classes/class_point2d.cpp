/* class point2d with members m_x and m_y. a constructor and print function*/

#include <iostream>

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
};

int main()
{
	Point2d first;
	Point2d second(3.0,4.0);
	
	first.print();
	second.print();

	return 0;
}	
