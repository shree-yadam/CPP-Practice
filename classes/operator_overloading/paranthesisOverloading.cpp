/*
1) Write a class that holds a string. Overload operator() to return the substring that starts at the index of the first parameter. The length of the substring should be defined by the second parameter.

Hint: You can use array indices to access individual chars within the std::string
Hint: You can use operator+= to append something to a string*/

#include <iostream>
#include <string>

class Mystring 
{
	private:
	std::string m_string;

	public:
	Mystring(const std::string string=""):m_string(string)
	{
	}

	std::string operator()(int start, int len)
	{
		std::string temp;
		int i;
		for(i = 0; i < len ;i++)
		{
			temp += m_string[start+i];
		}
		return temp;
		
	}
};

int main()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 5); // start at index 7 and return 5 characters
 
    return 0;
}
