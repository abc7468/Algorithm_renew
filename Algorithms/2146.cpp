#include<iostream>
#include<queue>
using namespace std;
int N;
int map[100][100];
int map2[100][100];
int visit[100][100];
int ans = 987654321;
int val = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int check = 1;

queue<pair<int, int>> q;

void dfs(int x, int y) {
	int nowX = x; int nowY = y;
	map2[nowX][nowY] = check;
	visit[nowX][nowY] = 1;

	for (int k = 0; k < 4; k++) {
		int nextX = nowX + dx[k];
		int nextY = nowY + dy[k];
		if (nextX >= 0 && nextX < N &&nextY >= 0 && nextY < N) {
			if (visit[nextX][nextY] == 0 && map[nextX][nextY]==1) {
				map2[nextX][nextY] = check;
				dfs(nextX, nextY);
			}
		
		}
	}
}

void bfs(int x, int y) {
	q.push(make_pair(x, y));

	int nowIsl = map2[x][y];
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextX = nowX + dx[k];
			int nextY = nowY + dy[k];
			if (nextX >= 0 && nextX < N &&nextY >= 0 && nextY < N) {
				if (map[nextX][nextY] == 0 && visit[nextX][nextY] == 0) {
					q.push(make_pair(nextX, nextY));
					visit[nextX][nextY] = visit[nowX][nowY] + 1;
				}
				else if (map2[nextX][nextY] != 0 && map2[nextX][nextY] != nowIsl ) {
					val = visit[nowX][nowY];
					if (ans > val) ans = val;
					while (!q.empty()) {
						q.pop();
					}
					return;
				}

			}
		}
	}


}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[x][y];

		}
	}
	if (N == 1 && map[0][0] == 1) {
		cout << "0" << '\n';
		return 0;
	}
	else if (N == 1 && map[0][0] == 0) {
		cout << "1" << '\n';
		return 0;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[x][y] == 1 && map2[x][y]== 0) {
				dfs(x, y);
				check++;
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < N; x++) {
						visit[x][y] = 0;
					}
				}
			}
		}
	}


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[x][y] == 1) {
				bfs(x, y);
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < N; x++) {
						visit[x][y] = 0;
					}
				}
			}
		}
	}

	


	cout << ans << '\n';
}