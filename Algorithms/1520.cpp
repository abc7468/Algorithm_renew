#include<iostream>
using namespace std;

int dw[4] = { -1,0,1,0 };
int dh[4] = { 0,-1,0,1 };
int height, width;
int map[500][500];
int way[500][500];

int dfs(int h, int w) {
	if (h == height - 1 && w == width - 1) {
		return 1;
	}
	if (way[h][w]>=0) return way[h][w];
	way[h][w] = 0;
	for (int k = 0; k < 4; k++) {
		int nextW = w + dw[k];
		int nextH = h + dh[k];
		if (nextW >= 0 && nextW < width && nextH >= 0 && nextH < height) {
			if (map[h][w] > map[nextH][nextW]) {
				way[h][w] += dfs(nextH, nextW);
			}
		}
	}
	return way[h][w];
}

int main() {
	cin >> height >> width;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			cin >> map[h][w];
			way[h][w] = -1;
		}
	}
	dfs(0, 0);
	cout << way[0][0];
	return 0;
}