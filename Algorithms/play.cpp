#include<iostream>
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	int val = a * b;
	for (int i = 0; i < 5; i++) {
		int m; cin >> m;
		cout << m - val << ' ';
	}
	return 0;
}