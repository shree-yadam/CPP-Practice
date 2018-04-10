/**
 * Update the Teacher/Dept example so the Dept can handle multiple Teachers. 
 * The following code should execute:
**/
#include <string>
#include <iostream>

#define MAX_TEACHERS 50
 
class Teacher
{
private:
    std::string m_name;
 
public:
    Teacher(std::string name)
        : m_name(name)
    {
    }
 
    std::string getName() { return m_name; }
};
 
class Department
{
private:
    Teacher **m_arrayTeacher;
	int m_numberOfTeachers; // This dept holds only one teacher for simplicity, but it could hold many teachers
 
public:
    Department()
    {
		m_arrayTeacher = new Teacher *[MAX_TEACHERS];	
		m_numberOfTeachers = 0;	
    }

	~Department()
	{
		delete [] m_arrayTeacher;
	}
		
	void add(Teacher *teacher)
	{
		m_arrayTeacher[m_numberOfTeachers] = teacher;
		m_numberOfTeachers += 1;
	}
	
	friend std::ostream &operator<<(std::ostream &out, Department &department);
};

std::ostream &operator<<(std::ostream &out, Department &department)
{
	for(int i = 0; i < department.m_numberOfTeachers; i++)
		out<< department.m_arrayTeacher[i]->getName()<<" ";
	out<<"\n";
	return out;
}
 
int main()
{
    // Create a teacher outside the scope of the Department
    Teacher *t1 = new Teacher("Bob"); // create a teacher
    Teacher *t2 = new Teacher("Frank");
    Teacher *t3 = new Teacher("Beth");
 
    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department dept; // create an empty Department
        dept.add(t1);
        dept.add(t2);
        dept.add(t3);
 
        std::cout << dept;
 
    } // dept goes out of scope here and is destroyed
 
    std::cout << t1->getName() << " still exists!\n";
    std::cout << t2->getName() << " still exists!\n";
    std::cout << t3->getName() << " still exists!\n";
 
    delete t1;
    delete t2;
    delete t3;
 
    return 0;
}
