#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map1[20][20];
int map2[20][20];
int v[20][20];
int dx[4] = { 0,-1,1,0 };
int dy[4] = { 1,0,0,-1 };
int shark_size = 2;
int eaten = 0;
int ans = 0;
int N;
int _max = 0;
int is_end = 0;
int is_eat = 0;
pair<int, int> now;
queue <pair<int, int>> q;
vector <pair<int, int>> vec;
void eat(int x, int y, int val) {
	eaten++;
	map1[x][y] = 0;
	if (shark_size == eaten) {
		eaten = 0;
		shark_size++;
	}
	while (!q.empty()) {
		q.pop();
	}
	now = make_pair(x, y);
	ans += val;
}

void bfs(int x, int y, int count) {
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (nextX < N && nextX>=0 && nextY<N && nextY>=0) {
				//언제 벡터에 담을지 확인해야해..
				if (map2[nextX][nextY] == 0 && v[nextX][nextY] == 0) { // 지나가는것
					q.push(make_pair(nextX, nextY));
					v[nextX][nextY] = v[nowX][nowY] + 1;
				}
				else if (map2[nextX][nextY] == 1 && v[nextX][nextY] == 0) {
					_max = v[nowX][nowY] + 1;
					vec.push_back(make_pair(nextX, nextY));
				}
			}
		}
	}
	is_end = 1;
}


int main() {
	cin >> N;
	for (int y = N-1; y >=0; y--) {
		for (int x = 0; x < N; x++) {
			cin >> map1[x][y];
			if (map1[x][y] == 9) now = make_pair(x, y);
		}
	}
	while (1) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (map1[x][y] == 9) {
					map2[x][y] = 0;
					v[x][y] = 0;
				}
				else if (map1[x][y] < shark_size && map1[x][y]!=0) {
					map2[x][y] = 1;
					v[x][y] = 0;
				}
				else if (map1[x][y] > shark_size) {
					map2[x][y] = 2;
					v[x][y] = -1;
				}
				else {
					map2[x][y] = 0;
					v[x][y] = 0;
				}
			}
		}

		bfs(now.first, now.second, 0);
		if (is_end == 1) {
			break;
		}
	}

	cout << ans;
	return 0;
}