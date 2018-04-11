/**
*It’s sometimes useful to define data that travels in pairs. Write a templated class named Pair1
* that allows the user to define one template type that is used for both values in the pair. The
* following function should work:
*
*/

#include <iostream>

template <class T>
class Pair1
{
	private:
		T m_first;
		T m_second;

	public:

		Pair1(T  first, T second):m_first(first), m_second(second) { }

		T& first()
		{
			return m_first;
		}

		const T& first() const
		{
			return m_first;
		}
		
		T& second()
		{
			return m_second;
		}

		const T& second()const
		{
			return m_second;
		}

};


int main()
{
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
 
	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
 
	return 0;
}
