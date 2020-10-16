#include<queue>
#include<iostream>
using namespace std;

queue<int>q;
queue<int>val;
int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		q.push(i);
	}
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int front = q.front();

		q.pop();
		if (cnt%b == 0) {
			val.push(front);
			continue;
		}
		q.push(front);
	}
	cout << '<';
	for (int i = 0; i < a; i++) {
		cout << val.front();
		val.pop();
		if (i + 1 != a) {
			cout << ", ";
		}
	}
	cout << '>';
	return 0;
}