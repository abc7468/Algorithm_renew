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


	cout << "Value�� �Ӽ� ���� : " << s._age << '\n';
	cout << "Pointer Ÿ������ �Ӽ� ���� : " << p->_age << '\n';
}


