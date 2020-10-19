#include<iostream>

using namespace std;

int d[1001][10];
int main() {
	int N;
	int ans=0;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (k > j) continue;
				d[i][j] = (d[i][j] + d[i-1][k]) % 10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		ans = (d[N][i] + ans) % 10007;
	}
	cout << ans;
	return 0;
}