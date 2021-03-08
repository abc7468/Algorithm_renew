#include<iostream>
#include<queue>
#define MAX 20
using namespace std;
int N;
int map[MAX][MAX][6];
int order[5];
int max_ = 0;
void left(int n) {
	for (int c = 0; c < N; c++) {
		queue<int>q;
		for (int r = 0; r < N; r++) {
			if (map[c][r][n - 1] == 0) {
				map[c][r][n] = 0;
				continue;
			}
			else {
				q.push(map[c][r][n - 1]);
				map[c][r][n] = 0;
			}
		}
		int cnt = 0;
		while (!q.empty()) {
			int val = q.front();
			q.pop();
			if (q.empty()) {
				map[c][cnt++][n] = val;
			}
			else if (val == q.front()) {
				map[c][cnt++][n] = val * 2;
				q.pop();

			}
			else {
				map[c][cnt++][n] = val;
			}
		}
		for (int i = cnt; i < N; i++) {
			map[c][i][n] = 0;
		}
	}
}

void right_(int n) {
	for (int c = 0; c < N; c++) {
		queue<int>q;
		for (int r = N-1; r >= 0; r--) {
			if (map[c][r][n - 1] == 0) {
				map[c][r][n] = 0;
				continue;
			}
			else {
				q.push(map[c][r][n - 1]);
				map[c][r][n] = 0;
			}
		}
		int cnt = N-1;
		while (!q.empty()) {
			int val = q.front();
			q.pop();
			if (q.empty()) {
				map[c][cnt--][n] = val;
			}
			else if (val == q.front()) {
				map[c][cnt--][n] = val * 2;
				q.pop();

			}
			else {
				map[c][cnt--][n] = val;
			}
		}
		for (int i = cnt; i >= 0; i--) {
			map[c][i][n] = 0;
		}
	}
}

void up(int n) {
	for (int r = 0; r < N; r++) {
		queue<int>q;
		for (int c = 0; c < N; c++) {
			if (map[c][r][n - 1] == 0) {
				map[c][r][n] = 0;
				continue;
			}
			else {
				q.push(map[c][r][n - 1]);
				map[c][r][n] = 0;
			}
		}
		int cnt = 0;
		while (!q.empty()) {
			int val = q.front();
			q.pop();
			if (q.empty()) {
				map[cnt++][r][n] = val;
			}
			else if (val == q.front()) {
				map[cnt++][r][n] = val * 2;
				q.pop();

			}
			else {
				map[cnt++][r][n] = val;
			}
		}
		for (int i = cnt; i < N; i++) {
			map[cnt][r][n] = 0;
		}
	}
}

void down(int n) {
	for (int r = 0; r < N; r++) {
		queue<int>q;
		for (int c = N-1; c >= 0; c--) {
			if (map[c][r][n - 1] == 0) {
				map[c][r][n] = 0;
				continue;
			}
			else {
				q.push(map[c][r][n - 1]);
				map[c][r][n] = 0;
			}
		}
		int cnt = N-1;
		while (!q.empty()) {
			int val = q.front();
			q.pop();
			if (q.empty()) {
				map[cnt--][r][n] = val;
			}
			else if (val == q.front()) {
				map[cnt--][r][n] = val * 2;
				q.pop();

			}
			else {
				map[cnt--][r][n] = val;
			}
		}
		for (int i = cnt; i >= 0; i--) {
			map[cnt][r][n] = 0;
		}
	}
}

void back(int cnt) {
	if (cnt == 5) {
		for (int i = 1; i <= 5; i++) {
			if (order[i-1] == 0) {
				left(i);
			}
			else if (order[i-1] == 1) {
				right_(i);
			}
			else if (order[i-1] == 2) {
				up(i);
			}
			else if (order[i-1] == 3) {
				down(i);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (max_ < map[i][j][5]) max_ = map[i][j][5];
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		order[cnt++] = i;
		back(cnt);
		cnt--;
	}


}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			cin >> map[i][j][0];
			
		}
	}

	back(0);
	
	
	
	cout << max_;
	return 0;
}