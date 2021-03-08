#include<iostream>
#include<algorithm>
#define MAX 101
#define INF 987654321
using namespace std;
int map[MAX][MAX];
int main() {
	int V, E; cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (map[a][b] > c) map[a][b] = c;
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (map[i][j] == INF) map[i][j] = 0;
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}