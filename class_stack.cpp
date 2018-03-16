/* Simple class implementation of stack */
#include <iostream>
#include <cassert>

#define ARRAY_SIZE 10

class Stack
{
	private:
		int m_array[ARRAY_SIZE];
		int m_top;
	public:
		void reset()
		{
			int i;
			for(i=0; i <= ARRAY_SIZE; i++)
				m_array[i] = 0;
			m_top = 0;
		}

		bool push(int num)
		{
			if(m_top == ARRAY_SIZE)
				return false;
		
			m_array[m_top] = num;
			m_top++;
			return true;
		}
		
		int pop()
		{
			assert(m_top > 0);
			return m_array[m_top--];
		}

		void print()
		{
			int i;
			std::cout<<"( ";
			for(i=0;i<m_top;i++)
				std::cout<<m_array[i]<<" ";
			std::cout<<")\n";
		}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	
	stack.print();

	return 0;
}
