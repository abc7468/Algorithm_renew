#include <iostream>

using namespace std;

class Student {
public:
	int _age;
	Student() {};
	Student(int age) : _age(age) {}
};

int main() {
	Student s = Student(21);
	Student* p = &s;


	cout << "Value로 속성 접근 : " << s._age << '\n';
	cout << "Pointer 타입으로 속성 접근 : " << p->_age << '\n';
}


