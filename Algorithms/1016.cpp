#include<iostream>
#include<cmath>
using namespace std;
bool map[1000001];
long long s, e;
void check() {
	int endPoint = sqrt(e);
	for (int i = 2; i <= endPoint; i++) {
		long long val = pow(i , 2);
		long long stand = (long long)s / val;
		stand = stand * val;
		if (stand > e) { break; }
		if (stand < s) stand = stand + val;
		for (stand; stand <= e; stand = stand + val) {
			if (map[stand - (s-1)] == true) continue;
			map[stand - (s - 1)] = true;
		}
	}
}

int main() {
	cin >> s >> e;
	int dis = e - s + 1;
	int ans = 0;
	check();
	for (int i = 1; i <= dis; i++) {
		if (!map[i]) ans++;
	}
	cout << ans;
	return 0;
}