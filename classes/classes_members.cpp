// Class to hold 2 integers and functions to set and print the values
//#define __GNU++11__

#include <iostream>

class IntPair
{
	public:
		int m_value1;
		int m_value2;
		
		void set(int value1, int value2)
		{
			m_value1 = value1;
			m_value2 = value2;
		}
		void print()
		{
			std::cout<<"Pair("<<m_value1<<", "<<m_value2<<")"<<std::endl;
		}
};

int main()
{
	IntPair p1;
	p1.set(1,1);//set p1 values to (1,1)

#ifdef __GNU++11__	
	IntPair p2{2,2};
#else
	IntPair p2;
	p2.set(2,2); // initialize p2 values to (2,2)
#endif
	p1.print();
	p2.print();

	return 0;
}	
		
