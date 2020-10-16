#include <string>
#include <stack>
#include <iostream>
using namespace std;


int main() {
	stack <char> left;
	stack <char> right;
	string input;
	int n;
	cin >> input >> n;
	int len = input.size();
	for (int i = 0; i < len; i++) {
		left.push(input[i]);
	}
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		if (tmp == 'L') {
			if (left.empty()) {
				continue;
			}
			char swap = left.top();
			right.push(swap);
			left.pop();
		}
		else if (tmp=='D') {
			if (right.empty()) {
				continue;
			}
			char swap = right.top();
			left.push(swap);
			right.pop();
		}
		else if (tmp=='B') {
			if (left.empty()) {
				continue;
			}
			left.pop();
		}
		else if (tmp=='P') {
			char tmp2;
			cin >> tmp2;
			left.push(tmp2);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
}