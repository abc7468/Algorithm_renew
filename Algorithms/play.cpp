#include<queue>
#include<iostream>
#define MAX 1000
using namespace std;
int sX, sY;
int W, H;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int>>q;

void bfs() {
	visited[sY][sX] = 1;
	q.push(make_pair(sX, sY));
	while (!q.empty()) {
		int nowX = q.front().first; int nowY = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextX = nowX + dx[k]; int nextY = nowY + dy[k];
			if (nextX >= 0 && nextX < W && nextY >= 0 && nextY < H) {
				if (visited[nextY][nextX] == 0 && map[nextY][nextX]==1) {
					q.push(make_pair(nextX, nextY));
					visited[nextY][nextX] = visited[nowY][nowX] + 1;
				}
			}
		}
	}
}


int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				sX = j;
				sY = i;
			}
		}
	}
	bfs();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (visited[i][j] == 0 && map[i][j]==0) visited[i][j]=1;
			else if (visited[i][j] == 0 && map[i][j] == 1) visited[i][j] = 0;
			cout << visited[i][j]-1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}