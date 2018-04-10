/**
 * Integer Array class that implements most of the common functionality of 
 * contaiers.
 **/

#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <initializer_list>

class IntArray{

	private:
		int m_length;
		int *m_data;

	public:
		IntArray():m_length(0),m_data(nullptr)
		{
		}

		IntArray(int length):m_length(length)
		{
			assert(length>=0);
			if(length > 0)
				m_data = new int[length];
			else
				m_data = nullptr;
		}

		IntArray(const std::initializer_list<int> &list):
			IntArray(list.size())
		{
			int count = 0;
			for(auto &element:list)
			{
				m_data[count] = element;
				++count;
			}
		}
			
		~IntArray()
		{
			delete[] m_data;
		}
	
		void erase()
		{
			delete[] m_data;
			m_data = nullptr;
			m_length = 0;
		}

		int& operator[](int index)
		{
			assert(index >= 0 && index < m_length);
			return m_data[index];
		}

		int getLength()
		{
			return m_length;
		}

		void reallocate(int length)
		{
			erase();
			
			if(length <  0)
				return;

			m_data = new int[length];
			m_length = length;
		}

		void resize(int length)
		{
			if(length == m_length)
				return;
			
			if(length <= 0)
			{
				erase();
				return;
			}

			int *data = new int[length];

			if(m_length > 0)
			{
				int numElementsToCopy = (length > m_length)? m_length:length;

				for(int i = 0; i < numElementsToCopy; i++)
					data[i] = m_data[i];
			}

			delete[] m_data;
			m_data = data;
			m_length = length;
		}

		void insertBefore(int value, int index)
		{
			assert(index >= 0 && index < m_length+1);

			int *data = new int[m_length + 1];

			for (int i = 0; i < index ; i++)
				data[i] = m_data[i];

			data[index] = value;
	
			for (int i = index + 1 ; i < (m_length + 1) ; i++)
				data[i] = m_data[i-1];

			delete[] m_data;
	
			m_data = data;
			m_length++;
		}

		void remove(int index)
		{
			assert(index >= 0 && index < m_length);

			if(index == 1)
			{
				erase();
				return;
			}

			int *data = new int[m_length - 1];
			
			for(int i = 0; i < index; i++)
				data[i] = m_data[i];

			for(int i = index+1; i < m_length; i++)
				data[i-1] = m_data[i];

			delete[] m_data;

			m_data = data;
			m_length--;
		}

		void insertAtBeginning(int value){ insertBefore(value, 0);}

		void insertAtEnd(int value){insertBefore(value, m_length);}

		IntArray& operator=(const std::initializer_list<int> &list)
		{
			if(list.size() != m_length)
			{
				delete[] m_data;
			
				m_length = list.size();
				m_data = new int[m_length];
			}
			
			int count = 0;
			for(auto &element:list)
				m_data[count++] = element;
			
			return *this;
		}
};

#endif
