#include<iostream>
#include<algorithm>
using namespace std;

int d[10001][2];
int map[10001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
	d[1][0] = map[1];
	for (int i = 2; i <= N; i++) {
		d[i][0] = max(d[i - 2][0], d[i - 2][1]) + map[i];
		d[i][1] = d[i - 1][0] + map[i];
	}
	cout << max(d[N][0], d[N][1]);
	return 0;
}