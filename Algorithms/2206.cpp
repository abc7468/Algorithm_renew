#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int map[1001][1001];
int visit[1001][1001][2];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue <pair<pair<int, int>, int>> q;
int Y, X;
bool check = false;
void bfs() {
	while (!q.empty()) {
		int nowX = q.front().first.first;
		int nowY = q.front().first.second;
		int use = q.front().second;
		if (nowX == X && nowY == Y) {
			cout << visit[X][Y][use];
			check = true;
			return;
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextX = nowX + dx[k];
			int nextY = nowY + dy[k];
			if (nextX > 0 && nextY > 0 && nextX <= X && nextY <= Y) {
				//º®ÀÏ ¶§
\
				if (map[nextX][nextY] == 1 && use == 1) {
					q.push(make_pair(make_pair(nextX, nextY), 0));
					visit[nextX][nextY][0] = visit[nowX][nowY][1] + 1;
				}
				else if (map[nextX][nextY] == 0 && visit[nextX][nextY][use]==0) {
					if (visit[nextX][nextY][use] == 0 ) {
						q.push(make_pair(make_pair(nextX, nextY), use));
						visit[nextX][nextY][use] = visit[nowX][nowY][use] + 1;
					}
				}
			}
		}
	}



}

int main() {
	cin >> Y >> X;
	for (int y = 1; y <= Y; y++) {
		string str; cin >> str;
		for (int x = 0; x < X; x++) {
			if (str[x] == '0') {
				map[x + 1][y] = 0;
			}
			else {
				map[x + 1][y] = 1;
			}
		}
	}
	visit[1][1][1] = 1;
	q.push(make_pair(make_pair(1, 1), 1));
	bfs();
	if (check == false) {
		cout << "-1" << '\n';
	}
	
}