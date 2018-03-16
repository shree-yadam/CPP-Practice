/* class ball with members color and radius */

#include <iostream>
#include <string>


class Ball
{
	private:
		std::string m_color = "black";
		double m_radius = 10.0;
	public:
		Ball(const std::string &color): m_color(color)
		{
		}

		Ball(double radius): m_radius(radius)
		{
		}			

		Ball(const std::string &color, double radius): m_color(color), m_radius(radius)
		{
		}	

		Ball() 
		{
			
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
