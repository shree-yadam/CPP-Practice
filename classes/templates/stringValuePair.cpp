/**
*A string-value pair is a special type of pair where the first value is always 
*a string type, and the second value can be any type. Write a template class 
*named StringValuePair that inherits from a partially specialized Pair class 
*(using std::string as the first type, and allowing the user to specify the 
*second type).
*/

#include <iostream>
#include <string>

template <class T1, class T2>
class Pair
{
	private:
		T1 m_first;
		T2 m_second;

	public:

		Pair(T1  first, T2 second):m_first(first), m_second(second) { }

		T1& first()
		{
			return m_first;
		}

		const T1& first() const
		{
			return m_first;
		}
		
		T2& second()
		{
			return m_second;
		}

		const T2& second()const
		{
			return m_second;
		}

};

template <class T2>
class StringValuePair : public Pair<std::string, T2>
{
	public:
		StringValuePair(std::string first, T2 second)
			:Pair<std::string, T2>(first, second) 
		{
		}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
 
	return 0;
}
