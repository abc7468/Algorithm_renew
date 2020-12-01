#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack <char> s;

int main() {
	int n; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		for (int j = 0; j < str.size(); j++) {
			if (str[j] != ' ') {
				s.push(str[j]);
			}
			else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
			if (j+1 == str.size()) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
			}

		}
		cout << "\n";
	}

	return 0;
}