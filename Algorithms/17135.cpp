#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int map1[15][16];
int map2[15][16];
int N, M, R, _M;
int dx[3] = { -1,0,1 };
int dy[3] = { 0,-1,0 };
int visit[15][16];
int ans = 0;
int _max = 0;
int _round = 0;
vector<vector<int>> archer;
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void shot();
void bfs(int x, int y);
void move();
void start();
void init();


void start() {
	init();
	int size = archer.size();
	for (int i = 0; i < size; i++) {

		map2[archer[i][0]][M] = 9;
		map2[archer[i][1]][M] = 9;
		map2[archer[i][2]][M] = 9;
		
		while (_round != _M) {
			bfs(archer[i][0], M);
			for (int i = 0; i <= M; i++) {
				for (int j = 0; j < N; j++) {
					visit[j][i] = 0;

				}
			}
			bfs(archer[i][1], M);
			for (int i = 0; i <= M; i++) {
				for (int j = 0; j < N; j++) {
					visit[j][i] = 0;

				}
			}
			bfs(archer[i][2], M);
			for (int i = 0; i <= M; i++) {
				for (int j = 0; j < N; j++) {
					visit[j][i] = 0;
				}
			}

			shot();

			move();
		}
		for (int y = 0; y <= _M; y++) {
			for (int x = 0; x < N; x++) {
				map2[x][y] = map1[x][y];
			}
		}

		if (_max < ans) {
			_max = ans;
		}
		ans = 0;
		M = _M;
		_round = 0;
	}

}

//±Ã¼ö À§Ä¡
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				vector<int> tmp;
				tmp.push_back(i);
				tmp.push_back(j);
				tmp.push_back(k);
				archer.push_back(tmp);
			}
		}
	}
}

//±Ã¼ö¸¦ y-1·Î
void move() {
	for (int i = 0; i < N; i++) {
		map2[i][M - 1] = map2[i][M];
	}
	M--;
	_round++;
}

void shot() {
	if (!v.empty()) {
		for (int i = 0; i < v.size(); i++) {
			if (map2[v[i].first][v[i].second] == 1) {
				map2[v[i].first][v[i].second] = 0;
				ans++;
			}
		}
	}
	while (!v.empty()) {
		v.pop_back();
	}
}





//Å½»ö
void bfs(int x, int y) {
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		int now = visit[nowX][nowY];
		q.pop();
		if (now > R) {
			while (!q.empty()) {
				q.pop();
			}
			return;
		}
		if (map2[nowX][nowY] == 1) {
			v.push_back(make_pair(nowX, nowY));
			while (!q.empty()) {
				q.pop();
			}
			return;
		}
		for (int k = 0; k < 3; k++) {
			int nextX = nowX + dx[k];
			int nextY = nowY + dy[k];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (visit[nextX][nextY] == 0 && map2[nextX][nextY] == 0) {
					visit[nextX][nextY] = visit[nowX][nowY] + 1;
					if (visit[nextX][nextY] > R) {
						while (!q.empty()) {
							q.pop();
						}
						return;
					}
					q.push(make_pair(nextX, nextY));
				}
				else if(visit[nextX][nextY] == 0 && map2[nextX][nextY] == 1){
					if (visit[nowX][nowY] >= R) {
						while (!q.empty()) {
							q.pop();
						}
						return;
					}

					v.push_back(make_pair(nextX, nextY));
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
	cin >> M >> N >>R;
	_M = M;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map1[x][y];
			map2[x][y] = map1[x][y];
		}
	}
	start();

	cout << _max << '\n';

}