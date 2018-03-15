/* Class Point 3d containing:
	# Three private member variables of type double named m_x, m_y, and m_z
	# A public member function named setValues() that allows you to set values
	   for m_x, m_y, and m_z,
	# A public member function names print() that prints the Point in the
	  following format:
		<m_x,m_y,m_z>
*/

#include <iostream>

class Point3d
{
	private:
		double m_x;
		double m_y;
		double m_z;
	public:
		void setValues(double x, double y, double z)
		{
			m_x = x;
			m_y = y;
			m_z = z;
		}
		
		void print()
		{
			std::cout<<"<"<<m_x<<","<<m_y<<","<<m_z<<">"<<std::endl;
		}
};

int main()
{
	Point3d point;
	point.setValues(1.0,2.0,3.0);

	point.print();

	return 0;
}
