#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include "vector.h"
#include "student.h"

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(16);
	v.push_back(25);

	cout<<v.back()<<endl;
	v.pop_back();

	cout<<v.back()<<endl;

	
	vector<string> v1;
	v1.push_back("risti");
	v1.push_back("e pich");

	cout<<v1.back()<<endl;
	cout<<v1.front()<<endl;
	v1.clear();
	Student student1("Iliqn",20);
	Student student2("Batvlad",19);

	Vector<Student> stud;
	stud.push_back(student1);
	stud.push_back(student2);

	system("pause");
	return 0;
}
