#include <iostream>
using namespace std;
char map[50][50];
int answer = 987654321;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int H, W;
	cin >> H >> W;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> map[w][h];
		}
	}
	int wRange = W - 8;
	int hRange = H - 8;
	//WB
	for (int hh = 0; hh <= hRange; hh++) {
		for (int ww = 0; ww <= wRange; ww++) {
			int count = 0;
			for (int y = hh; y < hh + 8; y++) {
				if ((y - hh) % 2 == 0) {
					for (int x = ww; x < ww + 8; x++) {
						if ((x - ww) % 2 == 0) {
							if (map[x][y] == 'B') count++;
						}
						else {
							if (map[x][y] == 'W') count++;
						}
					}
				}
				else {
					for (int x = ww; x < ww + 8; x++) {
						if ((x - ww) % 2 == 0) {
							if (map[x][y] == 'W') count++;
						}
						else {
							if (map[x][y] == 'B') count++;
						}
					}
				}

			}
			if (answer > count) answer = count;
		}
	}
	//BW
	for (int hh = 0; hh <= hRange; hh++) {
		for (int ww = 0; ww <= wRange; ww++) {
			int count = 0;
			for (int y = hh; y < hh + 8; y++) {
				if ((y - hh) % 2 == 0) {
					for (int x = ww; x < ww + 8; x++) {
						if ((x - ww) % 2 == 0) {
							if (map[x][y] == 'W') count++;
						}
						else {
							if (map[x][y] == 'B') count++;
						}
					}
				}
				else {
					for (int x = ww; x < ww + 8; x++) {
						if ((x - ww) % 2 == 0) {
							if (map[x][y] == 'B') count++;
						}
						else {
							if (map[x][y] == 'W') count++;
						}
					}
				}

			}
			if (answer > count) answer = count;
		}
	}
	cout << answer;
	return 0;
}