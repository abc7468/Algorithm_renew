#include<iostream>
#include<algorithm>

using namespace std;

int map[10001];
int d[10001][3];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
	d[1][1] = map[1];
	for (int i = 1; i <= N; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i-1][0] + map[i];
		d[i][2] = d[i - 1][1] + map[i];
	}
	cout << max(d[N][0], max(d[N][1], d[N][2])) << '\n';
	return 0;
}