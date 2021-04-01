#include<iostream>
#include<vector>
using namespace std;
vector<int> v;

int main() {
	int N, C; cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int start = 0, end = 0;
	int ans = 100001;
	long long tmp = v[0];
	while (1) {
		if (start == end) {
			if (v[start] >= C) {
				ans = 1;
				break;
			}
			else {
				end++;
				if (end == N) {
					break;
				}
				tmp += v[end];
				continue;
			}
		}
		if (tmp < C) {
			end++;
			if (end == N) {
				break;
			}
			tmp += v[end];
		}
		else {
			tmp -= v[start];
			start++;
		}
		if (tmp >= C) {
			if (ans > end - start + 1) ans = end - start + 1;
		}
	}
	if (ans == 100001) ans = 0;
	cout << ans;

	return 0;
}