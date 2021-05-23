#include <iostream>

using namespace std;
int map[10][10];
bool attach[10][10];
int used[6];
int ans=100;
int tmp=0;
int countSticker = 0;

void attachSticker(int x, int y, int size) {
	for (int yy = y; yy < y + size; yy++) {
		for (int xx = x; xx < x + size; xx++) {
			attach[xx][yy] = true;
		}
	}
}
void cleanSticker(int x, int y, int size) {
	for (int yy = y; yy < y + size; yy++) {
		for (int xx = x; xx < x + size; xx++) {
			attach[xx][yy] = false;
		}
	}
}

bool isAttach(int x, int y, int size) {

	if (x + size - 1 > 9) return false;
	if (y + size - 1 > 9) return false;
	for (int yy = y; yy < y + size; yy++) {
		for (int xx = x; xx < x + size; xx++) {
			if (map[xx][yy] == 0) return false;
			if (attach[xx][yy] == true) return false;
		}
	}
	return true;
}

bool check() {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (map[x][y] == 1 && attach[x][y] == false)return false;
		}
	}
	return true;
}

void back(int x, int y) {
	if (countSticker > ans) return;
	while (map[x][y] == 0 || (map[x][y] == 1 && attach[x][y])) {
		x++;
		if (x == 10) {
			x = 0;
			y++;
		}
		if (y == 10) {
			if (check()) {
				if (ans > countSticker)ans = countSticker;
				return;
			}
		}
	}
	for (int s = 5; s > 0; s--) {
		if (used[s] >= 5) continue;

		if (isAttach(x, y, s)) {
			attachSticker(x, y, s);
			used[s]++;
			countSticker++;
			back(x, y);
			countSticker--;
			cleanSticker(x, y, s);
			used[s]--;
		}
	}


}

int main() {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			cin >> map[x][y];
		}
	}
	back(0, 0);
	if (ans == 100) {
		cout << "-1";
		return 0;
	}
	cout << ans;
	return 0;
}