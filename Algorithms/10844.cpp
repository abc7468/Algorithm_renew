#include<iostream>
using namespace std;

int d[100][10];
int main() {
	int N;
	int ans = 0;
	cin >> N;
	d[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				d[i][j] = (d[i][j]+d[i - 1][j + 1]) % 1000000000;
			}
			else if (j == 9) {
				d[i][j] = (d[i][j] + d[i - 1][j - 1]) % 1000000000;

			}
			else {
				d[i][j] = (d[i][j] + d[i - 1][j - 1]) % 1000000000;
				d[i][j] = (d[i][j] + d[i - 1][j + 1]) % 1000000000;

			}

		}
	}

	for (int i = 0; i < 10; i++) {
		ans = (ans + d[N][i]) % 1000000000;
	}
	cout << ans;
	return 0;
}