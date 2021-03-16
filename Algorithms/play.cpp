#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int cmp = 1000 - n;
	int ans = 0;
	if (cmp >= 500) {
		ans++;
		cmp -= 500;
	}
	while (cmp >= 100) {
		cmp -= 100;
		ans++;
	}
	while (cmp >= 50) {
		cmp -= 50;
		ans++;
	}
	while (cmp >= 10) {
		cmp -= 10;
		ans++;
	}
	while (cmp >= 5) {
		cmp -= 5;
		ans++;
	}
	while (cmp >= 1) {
		cmp -= 1;
		ans++;
	}
	cout << ans;
	return 0;
}