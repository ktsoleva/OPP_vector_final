#include <string>
using namespace std;
 class Student
 {
 public:
	 Student();
	 Student(string name,int age)
	 {
		 m_name=name;
		 m_age=age;
	 }
 private:
	 string m_name;
	 int m_age;
 };
	 
