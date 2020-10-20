#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<int> s;
string str = "";
int main() {
	while (1) {
		getline(cin, str);
		if (str.size() == 1 && str[0] == '.') {
			break;
		}

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			if (str[i] == ')') {
				if (s.empty()) {
					cout << "no\n";
					break;

				}
				else if (s.top() == '(') {
					s.pop();
				}
				else {
					cout << "no\n";
					break;
				}
			}
			if (str[i] == ']') {
				if (s.empty()) {
					cout << "no\n";
					break;

				}
				else if (s.top() == '[') {
					s.pop();
				}
				else {
					cout << "no\n";
					break;
				}
			}
			if (i == str.size() - 1 && s.empty()) {
				cout << "yes\n";
			}
			else if(i == str.size() - 1 && !s.empty()){
				cout << "no\n";
				break;
			}
		}

		
		while (!s.empty()) {
			s.pop();
		}

	}

	return 0;
}