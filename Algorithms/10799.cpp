#include<string>
#include<iostream>
#include<stack>
using namespace std;
stack<int> str;
int main() {
	string tmp;
	cin >> tmp;
	int val = 0;
	int n = tmp.size();
	for (int i = 0; i < n; i++) {
		if (tmp[i] == '(') {
			str.push(i);
		}
		else if (tmp[i] == ')' && i - str.top() == 1) {
			str.pop();
			val += str.size();
		}
		else {
			val += 1;
			str.pop();
		}
	}
	cout << val;
	return 0;
}