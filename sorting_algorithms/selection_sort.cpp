/* Program to implement selection sort function */

#include <iostream>
#include <algorithm>

void print_array(int a[], int n);
void get_array(int a[], int n);
void selection_sort(int a[], int n)
{
	int i, j;
	int pos;
	
	for (i=0; i<n-1; i++)
	{
		pos = i;
		for(j = i+1; j<n; j++)
			if(a[pos] > a[j])
				pos = j;
		std::swap(a[i],a[pos]);
		print_array(a,n);
	}
}

void get_array(int a[], int n)
{
	int i;
	for(i=0; i< n; i++)
	{
		while(1)
		{
			std::cin>>a[i];
			if(std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767,'\n');
				std::cout<<"Bad input. enter again"<<'\n';
			}
			else
				break;
		}
	}
}

void print_array(int a[], int n)
{
	int i;

	std::cout<<"The array is"<<'\n';

	for(i=0; i<n; i++)
		std::cout<<a[i]<<'\t';
}

int main()
{
	int a[10];

	std::cout<<"Enter 10 integers"<<'\n';
	get_array(a,10);

	selection_sort(a,10);

	print_array(a,10);
	
	return 0;
}
