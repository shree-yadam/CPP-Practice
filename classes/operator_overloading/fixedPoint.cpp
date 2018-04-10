/* Write a class named FixedPoint2 that implements the recommended solution 
 * from the previous question. If either (or both) of the non-fractional and 
 * fractional part of the number are negative, the number should be treated as 
 * negative. Provide the overloaded operators and constructors required for 
 * the following program to run: 
 * 4c) Now add a constructor that takes a double. You can round a number (on 
 * the left of the decimal) by using the round() function (included in header 
 * cmath).
 *
 * Hint: You can get the non-fractional part of a double by static casting 
 * the double to an integer
 * Hint: To get the fractional part of a double, you'll first need to zero-out 
 * the non-fractional part. Use the integer value to do this.
 * Hint: You can move a digit from the right of the decimal to the left of the 
 * decimal by multiplying by 10. You can move it two digits by multiplying by 
 * 100.
 * Overload operator==, operator >>, operator- (unary), and operator+ (binary).
 */

#include <iostream>
#include <cstdint>

class FixedPoint2
{
	private:
		std::int16_t m_base;
		std::int8_t m_decimal;
	
	public:
		FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0)
			:m_base(base), m_decimal(decimal)
		{
		}
		
		FixedPoint2(double number)
		{
			m_base = static_cast<int16_t>(number);
			m_decimal = static_cast<int8_t>((number - m_base)*100);
		}
		
		friend std::ostream& operator<<(std::ostream &out, FixedPoint2 &fixed);

		operator double();
		
		bool operator==(FixedPoint2 &fixed);

		friend std::istream& operator>>(std::istream &in, FixedPoint2 &fixed);

		FixedPoint2 &operator+(FixedPoint2 &fixed);
		FixedPoint2 operator-();
			
};
		
bool FixedPoint2::operator==(FixedPoint2 &fixed)
{
		return(static_cast<double>(*this) == static_cast<double>(fixed));
}

std::istream& operator>>(std::istream &in, FixedPoint2 &fixed)
{
	double number;
	
	in>>number;
	FixedPoint2 temp(number);	
	fixed = temp;
	return in;
		
}

FixedPoint2 &FixedPoint2::operator+(FixedPoint2 &fixed)
{
	FixedPoint2 temp(static_cast<double>(*this) + static_cast<double>(fixed));
	
	*this = temp;
	return *this;
}
	
FixedPoint2 FixedPoint2::operator-()
{
		FixedPoint2 temp(-(static_cast<double>(*this)));
		return temp;
}

FixedPoint2::operator double()
{
	double temp;
	bool isNegative = false;
	if(m_base < 0 )
	{
		isNegative = true;
		temp = -static_cast<double>(m_base);
	}
	else
		temp = static_cast<double>(m_base);
				
	if(m_decimal < 0)
	{
		isNegative = true;
		temp = temp + (-static_cast<double>(m_decimal))/100;
	}
	else
		temp = temp + static_cast<double>(m_decimal)/100;

	if(isNegative)
		temp = -temp;
	return temp;
}
		
std::ostream& operator<<(std::ostream &out, FixedPoint2 & fixed)
{
	out<<static_cast<double>(fixed);
	return out;
}

/* int main()
{
	FixedPoint2 a(34, 56);
	std::cout << a << '\n';
 
	FixedPoint2 b(-2, 8);
	std::cout << b << '\n';
 
	FixedPoint2 c(2, -8);
	std::cout << c << '\n';
 
	FixedPoint2 d(-2, -8);
	std::cout << d << '\n';
 
	FixedPoint2 e(0, -5);
	std::cout << e << '\n';
 
	std::cout << static_cast<double>(e) << '\n';
 
	return 0;
} */
/*
int main()
{
	FixedPoint2 a(0.01);
	std::cout << a << '\n';
 
	FixedPoint2 b(-0.01);
	std::cout << b << '\n';
 
	FixedPoint2 c(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';
 
	FixedPoint2 d(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';
 
	return 0;
}*/

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}
 
int main()
{
	testAddition();
 
	FixedPoint2 a(-0.48); 
	std::cout << a << '\n';
 
	std::cout << -a << '\n';
 
	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	
	std::cout << "You entered: " << a << '\n';
 
	return 0;
}
