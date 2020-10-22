#include<iostream>
using namespace std;

long long ans = 0;

void cq(int a, int b) {
	if (a == 1) {
		ans += b;
		return;
	}
	else if (a == b) {
		ans += 1;
		return;
	}
	for (int i = 1; i <= b - a + 1; i++) {
		cq(a-1, b - i);
	}
}

int main() {
	int t,n, m; cin>> t ;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cq(n, m);
		cout << ans<<'\n';
		ans = 0;
	}
	return 0;
}