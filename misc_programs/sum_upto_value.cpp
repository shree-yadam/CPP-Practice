// Program to print sum of all numbers from 1 to value

#include <iostream>

// Function to return suma of numbers from 1 to value
int sumTo(int value)
{
	if (value <=  0)
		return 0;
	else if (value ==1)
		return 1;
	else return value+sumTo(value-1);
}

int main()
{
	int num;
	
	std::cout<<"Enter value to print sum to ";
	std::cin>>num;
	std::cout<<std::endl<<"Sum is "<<sumTo(num)<<std::endl;
	return 0;
}
