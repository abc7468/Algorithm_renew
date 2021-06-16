#include <deque>
#include <iostream>

using namespace std;



int highly(int *list) {
	for (int i = 9; i >= 1; i--) {
		if (list[i] != 0) {
			list[i]--;
			return i;
		}
	}
	return 0;
}

int main() {
	int T; cin >> T;
	while (T--) {
		deque<pair<int, bool>> dq;
		int importance[10];
		for (int i = 1; i <= 9; i++) {
			importance[i] = 0;
		}
		int a, b; cin >> a >> b;
		int count = 0;
		for (int i = 0; i < a; i++) {
			int val; cin >> val;
			dq.push_back({ val, false });
			importance[val]++;
		}
		dq[b].second = true;
		while (1) {
			int findValue = highly(importance);
			while (dq.front().first != findValue) {
				pair<int, int> tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
			count++;
			if (dq.front().second == true) {
				break;
			}
			else {
				dq.pop_front();
			}
		}
		cout << count << '\n';




	}
		
	return 0;
}