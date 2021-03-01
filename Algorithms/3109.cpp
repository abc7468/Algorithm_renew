#include<iostream>
using namespace std;

int dy[3] = {-1,0,1};
int map[10000][500];
bool visited[10000][500];
int col, row;
bool check;
int ans = 0;
void dfs(int c, int r) {
	if (check == true) {
		return;
	}
	visited[c][r] = true;
	int nowC = c;
	int nowR = r;
	for (int k = 0; k < 3; k++) {
		int nextR = nowR + 1;
		int nextC = nowC + dy[k];
		if (nextR == row - 1 && visited[nextC][nextR] == false) {
			ans++;
			check = true;
			return;
		}
		if (nextC < col && nextC >= 0 && nextR<row && visited[nextC][nextR] == false) {
			dfs(nextC, nextR);
		}
	}



}


int main() {
	cin >> col >> row;
	for (int c = 0; c < col; c++) {
		for (int r = 0; r < row; r++) {
			char k; cin >> k;
			if (k == 'x') {
				map[c][r] = 1;
				visited[c][r] = true;
			}
			else {
				map[c][r] = 0;
			}
		}
	}
	for (int i = 0; i < col; i++) {
		check = false;
		dfs(i, 0);
	}
	cout << ans;
	return 0;
}