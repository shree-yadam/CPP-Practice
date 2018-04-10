/**
 * Let’s implement our Fruit example that we talked about in our introduction 
 * to inheritance. Create a Fruit base class that contains two private members:
 * a name (std::string), and a color (std::string). Create an Apple class that 
 * inherits Fruit. Apple should have an additional private member: fiber 
 * (double). Create a Banana class that also inherits Fruit. Banana has no 
 * additional members.
 **/

#include <iostream>

class Fruit
{
	private:
		std::string m_name;
		std::string m_color;
		
	public:
		Fruit(std::string name = "", std::string color = "")
			:m_name(name), m_color(color)
		{
		}
		
		std::string getName()const{return m_name;}
		std::string getColor()const{return m_color;}
};

class Apple: public Fruit
{
	private:
		double m_fiber;

	public:
		Apple(std::string name ="", std::string color = "", double fiber = 0.0)
			:Fruit(name,color),m_fiber(fiber)
		{
		}

		double getFiber()const{return m_fiber;}

		friend std::ostream& operator<<(std::ostream &out,const Apple &a);
			
};

std::ostream& operator<<(std::ostream &out, const Apple &a) 
{
	out<<"Apple("<<a.getName()<<", "<<a.getColor()<<", "<<a.getFiber()<<")\n";
	return out;
}

class Banana:public Fruit
{
	public:
		Banana(std::string name="", std::string color ="")
			:Fruit(name,color)
		{
		}
		
		friend std::ostream& operator<<(std::ostream &out, const Banana &b);
};

std::ostream& operator<<(std::ostream &out, const Banana &b) 
{
	out<<"Banana("<<b.getName()<<", "<<b.getColor()<<")\n";
	return out;
}

int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;
 
	return 0;
}
