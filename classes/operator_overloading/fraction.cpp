#include <iostream>
#include <cassert>

#define __1C__

class Fraction
{
	private:
		int m_numerator;
		int m_denominator;
	
	public:
		Fraction(int numerator = 0, int denominator = 1)
		{
			assert(denominator!=0);
			m_numerator = numerator;
			m_denominator = denominator;
			reduce();
		}
		
		void print()
		{
			std::cout<<m_numerator<<"/"<<m_denominator<<std::endl;
		}

		int gcd(int a, int b) 
		{
    		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
		}
		
		void reduce()
		{
			int g = gcd(m_numerator, m_denominator);
			m_numerator /= g;
			m_denominator/= g;
		}

		friend Fraction operator*(const Fraction &f1, const Fraction &f2);
		friend Fraction operator*(const Fraction &f, int i);
		friend Fraction operator*(int i, const Fraction &f);
};
 
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return(Fraction(f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator));
}

Fraction operator*(const Fraction &f, int i)
{
	return (Fraction(f.m_numerator*i,f.m_denominator));
}

Fraction operator*(int i, const Fraction &f)
{
	return (operator*(f,i));
} 

#ifdef __1A__
int main()
{
    Fraction f1(1, 4);
    f1.print();
 
    Fraction f2(1, 2);
    f2.print();
}
#endif

#ifdef __1B__
 
int main()
{
    Fraction f1(2, 5);
    f1.print();
 
    Fraction f2(3, 8);
    f2.print();
 
    Fraction f3 = f1 * f2;
    f3.print();
 
    Fraction f4 = f1 * 2;
    f4.print();
 
    Fraction f5 = 2 * f2;
    f5.print();
 
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
}
#endif

#ifdef __1C__
 
int main()
{
    Fraction f1(2, 5);
    f1.print();
 
    Fraction f2(3, 8);
    f2.print();
 
    Fraction f3 = f1 * f2;
    f3.print();
 
    Fraction f4 = f1 * 2;
    f4.print();
 
    Fraction f5 = 2 * f2;
    f5.print();
 
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
 
    return 0;
}
#endif
