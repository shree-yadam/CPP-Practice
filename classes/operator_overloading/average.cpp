/**
 *2) Write a class named Average that will keep track of the average of all 
 *integers passed to it. Use two members: The first one should be type int32_t,
 * and used to keep track of the sum of all the numbers you’ve seen so far. 
 *The second should be of type int8_t, and used to keep track of how many 
 *numbers you’ve seen so far. You can divide them to find your average.
 */

#include <iostream>
#include <cstdint>

class Average
{
	private:
		int32_t m_sum;
		int8_t m_count;

	public:
		Average(int32_t sum=0):m_sum(sum){}
		Average(Average &average)
		{
			m_sum = average.m_sum;
			m_count = average.m_count;
		}
		friend Average & operator+(Average & average, int32_t i);
		friend std::ostream &operator<<(std::ostream &out, Average &average) 
		{
			out<<(double)average.m_sum/average.m_count;
			return out;
		}
		Average & operator=(Average &average);
		friend Average & operator+=(Average & average, int32_t i)
		{
			average = average + i;
			return average;
		}
					

};

Average & operator+(Average & average, int32_t i)
{
	average.m_sum +=i;
	average.m_count++;
	return average;
}

Average & Average::operator=(Average &average)
{
	m_sum = average.m_sum;
	m_count = average.m_count;
	return *this;
}

int main()
{
	Average avg;
	
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4
	
	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}
