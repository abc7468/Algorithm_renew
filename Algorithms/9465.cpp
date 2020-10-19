#include<iostream>
#include<algorithm>
using namespace std;

long long d[100001][3];
long long map[100000][2];

void clear(int n) {
	for (int i = 0; i < n; i++) {
		map[i][0] = 0;
		map[i][1] = 0;
	}
}

int main() {
	int T, N;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> map[i][0];
		}
		for (int i = 1; i <= N; i++) {
			cin >> map[i][1];
		}
		d[1][0] = 0;
		d[1][1] = map[1][0];
		d[1][2] = map[1][1];
		for (int i = 2; i <= N; i++) {
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0]+map[i][0], d[i - 1][2] + map[i][0]);
			d[i][2] = max(d[i - 1][0]+map[i][1], d[i - 1][1] + map[i][1]);

		}

		cout << max(d[N][0], max(d[N][1], d[N][2]))<<'\n';
		clear(N);
			
	}
	return 0;
}