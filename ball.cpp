/* class ball with members color and radius */

#include <iostream>
#include <string>


class Ball
{
	private:
		std::string m_color;
		double m_radius;
	public:
		Ball(const std::string &color)
		{
			m_color = color;
			m_radius = 10.0;
		}

		Ball(double radius)
		{
			m_color = "black";
			m_radius = radius;
		}			

		Ball(const std::string &color, double radius)
		{
			m_color = color;
			m_radius = radius;
		}	

		Ball()
		{
			m_color = "black";
			m_radius = 10.0;
			
		}

		void print()
		{
			std::cout<<"color: "<<m_color<<", radius: "<<m_radius<<std::endl;
		}	
};

int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball bluetwenty("blue",20.0);
	bluetwenty.print();

	return 0;
}
