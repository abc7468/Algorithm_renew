#include <iostream>
#include <deque>
using namespace std;
int map[102][102];
int visited[102][102][3];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
deque<pair<int, int>> start;
int min_ = 987654321;
int col, row;
void bfs() {
	start.push_front(make_pair(0, 0));
	for (int s = 0; s < 3; s++) {
		int startCol = start.front().first; int startRow = start.front().second; start.pop_front();
		visited[startCol][startRow][s] = 0;
		deque<pair<int, int>> tmpQ;
		tmpQ.push_back(make_pair(startCol, startRow));
		while (!tmpQ.empty()) {
			int nowC = tmpQ.front().first; int nowR = tmpQ.front().second; tmpQ.pop_front();
			for (int k = 0; k < 4; k++) {
				int nextC = nowC + dy[k]; int nextR = nowR + dx[k];
				if (nextC >= 0 && nextC <= col + 1 && nextR >= 0 && nextR <= row + 1) {
					if (map[nextC][nextR] == 0) {
						if (visited[nextC][nextR][s] == -1) {
							visited[nextC][nextR][s] = visited[nowC][nowR][s];
							tmpQ.push_front(make_pair(nextC, nextR));
						}
					}
					else if (map[nextC][nextR] == 1) {
						continue;
					}
					else if (map[nextC][nextR] == 2) {
						if (visited[nextC][nextR][s] == -1) {
							visited[nextC][nextR][s] = visited[nowC][nowR][s] + 1;
							tmpQ.push_back(make_pair(nextC, nextR));
						}
					}
				}
			}
		}
	}

	for (int c = 0; c <= col + 1; c++) {
		for (int r = 0; r <= row + 1; r++) {
			if (map[c][r] != 1 && visited[c][r][0]!=-1) {
				int tmp=0;
				for (int i = 0; i < 3; i++) {
					tmp += visited[c][r][i];
				}
				if (map[c][r] == 2) tmp = tmp - 2;
				if (min_ > tmp) min_ = tmp;
			}

		}
	}
	cout << min_ << "\n";
	

	min_ = 987654321;

}

int main() {
	int N; cin >> N;
	for (int n = 0; n < N; n++) {

		cin >> col >> row;
		for (int c = 0; c <= col + 1; c++) {
			for (int r = 0; r <= row + 1; r++) {
				for (int i = 0; i < 3; i++) {
					visited[c][r][i] = -1;
				}
				map[c][r] = 0;
			}
		}
		for (int c = 1; c <= col; c++) {
			for (int r = 1; r <= row; r++) {
				char ch;
				cin >> ch;
				if (ch == '*') {
					map[c][r] = 1;
				}
				else if (ch == '.') {
					map[c][r] = 0;
				}
				else if (ch == '$') {
					map[c][r] = 0;
					start.push_front(make_pair(c, r));
				}
				else if (ch == '#') {
					map[c][r] = 2;
				}
			}
		}

		bfs();


	}

	return 0;
}