/* Write your own integer array class named IntArray from scratch (do not use 
 * std::array or std::vector). Users should pass in the size of the array when 
 * it is created, and the array should be dynamically allocated. Use assert 
 * statements to guard against bad data. Create any constructors or overloaded 
 * operators needed to make the following program operate correctly:
 * This programs should print:
 *
 * 5 8 2 3 6
 * 5 8 2 3 6
*/

#include <iostream>
#include <cassert>

class IntArray
{
	private:
		int *m_array = nullptr;
		int m_count = 0;
	
	public:
		IntArray(int count):m_count(count)
		{
			assert(count > 0 && "IntArray count should be a positive integer");
			m_array = new int[count];
		}

		IntArray(const IntArray &array):m_count(array.m_count)
		{
			m_array = new int[m_count];
			for(int i = 0; i < m_count ; i++)
				m_array[i] = array.m_array[i];
		}

		~IntArray()
		{
			delete [] m_array;
		}
		
		IntArray &operator=(const IntArray &array);
		friend std::ostream & operator<<(std::ostream &out, const IntArray & array);
		int &operator[](const int index)
		{
			assert(index < m_count);
			assert(index >= 0);
			return m_array[index];
		}
		
};

IntArray &IntArray::operator=(const IntArray &array)
{
		if(this == &array)
			return *this;

		delete [] m_array;

		m_count = array.m_count;
		m_array = new int[m_count];
		for(int i = 0; i < m_count ; i++)
			m_array[i] = array.m_array[i];
		return *this;
}
 
std::ostream &operator<<(std::ostream &out, const IntArray & array)
{
	for(int i = 0; i < array.m_count; i++)
		out<<array.m_array[i]<<" ";
	out<<"\n";
	return out;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
 
	return a;
}
 
int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';
 
	IntArray b(1);
	a = a;
	b = a;
 
	std::cout << b << '\n';
 
	return 0;
}
