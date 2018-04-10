#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string m_name;
	char grade;
};

class GradeMap
{
	private:
		std::vector<StudentGrade> m_map;
	
	public:
		GradeMap(){}
		char& operator[](std::string);

};

char& GradeMap::operator[](std::string name)
{
	StudentGrade sg;
	for(StudentGrade & element:m_map)
	{
		if(element.m_name==name)
			return element.grade;
	}
	
	sg.m_name = name;
	m_map.push_back(sg);
	return m_map.back().grade;	
}

/*
int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
 
	return 0;
}
*/

#include <iostream>
 
int main()
{
	GradeMap grades;
 
	char& gradeJoe = grades["Joe"]; // does a push_back
	gradeJoe = 'A';
 
	char& gradeFrank = grades["Frank"]; // does a push_back
	gradeFrank = 'B';
 
	std::cout << "Joe has a grade of " << gradeJoe << '\n';
	std::cout << "Frank has a grade of " << gradeFrank << '\n';
 
	return 0;
}
