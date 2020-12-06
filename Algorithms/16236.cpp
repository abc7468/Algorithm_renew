#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int x, y;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { 1,0,0,-1 };
int n;
int map[20][20];
int trav[20][20];
int visit[20][20];
int sharkSize = 2;
int yum = 0;
int eaten = 0;
int dis = 987654321;
int ans = 0;
vector<pair<int, int>> prey;
queue<pair<int, int>> q;

bool cmp(const pair<int, int> &a, const pair<int, int> &b);
void eat(int dist);
void bfs(int x, int y);
void makeTravel(int sharkSize);

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (b.second == a.second) return a.first < b.first;
	return a.second > b.second;
}

void eat(int dist) {
	sort(prey.begin(),prey.end(),cmp);
	eaten++;
	ans += dist;
	dis = 987654321;

	if (eaten == sharkSize) {
		eaten = 0;
		sharkSize++;
	}
	int x = prey.front().first;
	int y = prey.front().second;

	while (!prey.empty()) {
		prey.pop_back();
	}
	while (!q.empty()) {
		q.pop();
	}
	map[x][y] = 0;
	makeTravel(sharkSize);

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			visit[x][y] = 0;
		}
	}

	bfs(x, y);


}

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nowX = q.front().first; int nowY = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextX = nowX + dx[k];
			int nextY = nowY + dy[k];
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
				if (visit[nextX][nextY] == 0 && trav[nextX][nextY] == 0) {
					if (nextX == x && nextY == y) {
						continue;
						cout << "°°´Ù";
					}
					q.push(make_pair(nextX, nextY));
					visit[nextX][nextY] = visit[nowX][nowY] + 1;
					if (dis < visit[nextX][nextY]) {
						eat(dis);
						return;
					}
				}
				else if (visit[nextX][nextY] == 0 && trav[nextX][nextY] == 1) {
					if (dis <= visit[nowX][nowY]) {
						eat(dis);
						return;
					}
					dis = visit[nowX][nowY] + 1;
					prey.push_back(make_pair(nextX, nextY));
				}
				
			}
		}

	}
	if (!prey.empty()) {
		eat(dis);
	}
}

void makeTravel(int sharkSize) {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 0 || map[x][y]==sharkSize) {
				trav[x][y] = 0;
			}
			else if (map[x][y] < sharkSize) {
				trav[x][y] = 1;
			}
			else {
				trav[x][y] = 2;
			}

		}
	}
}

int main() {
	cin >> n;
	int startX, startY;
	for (int y = n-1; y >= 0; y--) {
		for (int x = 0; x < n; x++) {
			cin >> map[x][y];
			if (map[x][y] == 9) {
				startX = x;
				startY = y;
				map[x][y] = 0;
			}
		}
	}
	makeTravel(sharkSize);
	bfs(startX, startY);
	cout << ans;

	return 0;
}