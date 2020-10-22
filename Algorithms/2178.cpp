#include<iostream>
#include<queue>

using namespace std;

queue<pair<int,int>> q;

int map[101][100];
int v[101][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M;

void bfs() {
	int x = 0; int y = 0;
	q.push(make_pair(x, y));
	v[x][y] = 1;
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i]; 
			int nextY = nowY + dy[i];
			if (nextX >= 0 && nextY >= 0 && nextX < M && nextY < N && v[nextX][nextY] == 0 && map[nextX][nextY] == 1) {
				q.push(make_pair(nextX, nextY));
				v[nextX][nextY] = v[nowX][nowY] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf_s("%1d", &map[x][y]);
		}
	}
	bfs();
	cout << v[M-1][N-1];
	

	return 0;
}