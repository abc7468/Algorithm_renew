#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack <int> s;
int map[100001];
int main() {

	string ans="";
	int N;
	cin >> N;
	int val = 0;
	int count = 0;
	int index = 1;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	while (1) {
		if (!s.empty()) {
			if (s.top()==map[val]) {
				ans += '-';
				val++;
				count++;
				s.pop();
				continue;
			}
		}
		if (count == N * 2)break;

		s.push(index++);
		ans += '+';

		count++;
	}
	if (s.empty()) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}

	}
	else {
		cout << "NO\n";
	}
	return 0;
}